#include <stdint.h>
#include "f256lib.h"
#include "../include/draw_line.h"

__attribute__((aligned(256)))
struct line_list g_line_list;

uint8_t __zp g_line_count = 0;   // 0 to MAX_LINE_LIST(128)
uint8_t g_line_count_max = 0;  // peak line count per frame (diagnostic)
uint16_t g_line_dropped = 0; // count lines that couldn't be added due to list full
volatile uint16_t g_line_fifo_timeouts = 0; // watchdog bailout count (draw FIFO stall)


void reset_line_list(void) {
    if (g_line_count > g_line_count_max) {
        g_line_count_max = g_line_count;  // track peak usage
    }
    g_line_count = 0;
}
void add_line_to_list(uint16_t x0, uint8_t y0, uint16_t x1, uint8_t y1, uint8_t color) {
    // Removed guard. Caller ensures vertex validity and clipping as needed.
    if (g_line_count < MAX_LINE_LIST) {
        g_line_list.x0[g_line_count] = x0;
        g_line_list.x1[g_line_count] = x1;
        g_line_list.y[g_line_count] = (((uint16_t) y1) << 8) | y0;
        g_line_list.color[g_line_count] = color;
        g_line_count++;
    } else {
        g_line_dropped++;
    }
}

void draw_lines_from_list(uint8_t layer) {
    for (uint16_t i = 0; i < g_line_count; i++) {
        draw_line(g_line_list.x0[i], g_line_list.y[i] & 0xFF, g_line_list.x1[i], (g_line_list.y[i])>>8, g_line_list.color[i] & 0xFF, layer);
    }
}

void draw_line(uint16_t x0, uint8_t y0, uint16_t x1, uint8_t y1, uint8_t color, uint8_t layer);
// x0: A,X
// y0: __rc2
// x1: __rc3,__rc4
// y1: __rc5
// color: __rc6
// layer: __rc7

    asm (     
        ".text\n"
        ".global draw_line\n"
        "draw_line:\n"
        "pha\n"
        "lda __rc7\n"
        "asl\n"
        "asl\n"
        "ora #$01\n"
        "sta $d180\n"
        "lda #$01\n"
        "sta $D00A\n"
        "pla\n"
        "sta $d182\n"
        "stx $d183\n"
        "lda __rc2\n"
        "sta $d186\n"
        "lda __rc3\n"
        "sta $d184\n"
        "lda __rc4\n"
        "sta $d185\n"
        "lda __rc5\n"
        "sta $d187\n"
        "lda __rc6\n"
        "sta $d181\n"
        "lda __rc7\n"
        "asl\n"
        "asl\n"
        "ora #$03\n"
        "sta $d180\n"
        // "ldx #$7F\n"
        // "1: dex\n"
        // "beq 2f\n"
        // "lda $d180\n"
        // "bmi 1b\n"
        "ldx #$40\n"       // watchdog timeout (bounded spin)
        "1: lda $d182\n"   // wait for fifo to zero
        "ora $d183\n"
        "beq 2f\n"
        "dex\n"
        "bne 1b\n"
        "inc g_line_fifo_timeouts\n"
        "bne 2f\n"
        "inc g_line_fifo_timeouts+1\n"
        "2: lda #$00\n"
        "sta $d180\n"
        "sta $D00A\n"
        "rts\n"
    );

