#if !defined(DRAW_LINE_H)
#define DRAW_LINE_H
#include <stdint.h>
// limit line list to 36 to match max edges output by the kernel
#define MAX_LINE_LIST 36

// to be page aligned for easy access.  each array is 256 bytes
struct line_list {
    uint16_t x0[MAX_LINE_LIST];
    uint16_t x1[MAX_LINE_LIST];
    uint16_t y[MAX_LINE_LIST];  // combined y0 and y1: y0 = low byte, y1 = high byte
    uint16_t color[MAX_LINE_LIST];  // low byte is color
};

extern struct line_list g_line_list;
extern uint8_t __zp g_line_count;  // 0 to MAX_LINE_LIST(36)
extern uint8_t g_line_count_max;   // peak line count per frame (diagnostic)

void reset_line_list(void);
void add_line_to_list(uint16_t x0, uint8_t y0, uint16_t x1, uint8_t y1, uint8_t color);

extern uint16_t g_line_dropped; // count lines that couldn't be added due to list full
extern uint16_t g_clipped_edges; // count edges that required clipping/projection
extern uint16_t g_fast_edges;    // count edges that used fast int path

// Debug counters for diagnosing clipping/projection issues (reset each frame).
extern uint16_t g_near_clip_edges;   // edges that straddled the near plane and were clipped in view space
extern uint16_t g_2d_clip_calls;     // calls into the 2D viewport clipper
extern uint16_t g_2d_clip_rejects;   // 2D clipper rejects due to degenerates/overflow guards

// More detailed 2D clipper diagnostics.
extern uint16_t g_2d_clip_accepts;        // segments accepted and added after 2D clipping
extern uint16_t g_2d_trivial_rejects;     // rejects from (out0 & out1) != 0
extern uint16_t g_2d_intersect_failures;  // rejects due to failing intersection math
extern uint16_t g_2d_iter_guards;         // rejects due to iteration guard (should be 0)
void draw_lines_from_list(uint8_t layer);
void draw_line(uint16_t x0, uint8_t y0, uint16_t x1, uint8_t y1, uint8_t color, uint8_t layer);

extern void draw_lines_asm(uint8_t layer);

#endif /* DRAW_LINE_H */
