#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>
#include <stdint.h>

typedef struct {
	bool w, a, s, d, t, g;
	bool rotateLeft;
	bool rotateRight;
	bool rotateUp;
	bool rotateDown;	
} InputHold;

typedef struct {
	bool rotateLeft;
	bool rotateRight;
	bool rotateUp;
	bool rotateDown;
	bool resetCam;
bool exit;
	uint8_t objectIndex;	
} InputEdge;

typedef struct {
	InputHold hold;
	InputEdge edge;
} InputState;

// Debug: last keyboard event observed by input handler.
// Useful for diagnosing missing key holds / spurious key events.
extern volatile char g_dbg_last_key_ascii;
extern volatile uint8_t g_dbg_last_key_raw;
extern volatile char g_dbg_last_key_flags;
extern volatile uint8_t g_dbg_last_key_pressed;

InputState *input_state_data(void);
void input_state_init(void);
void input_state_clear_edges(InputState *state);
extern uint16_t objectIndex;

#endif // INPUT_H
