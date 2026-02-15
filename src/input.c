#include "../include/input.h"

#include <string.h>

static InputState g_input __attribute__((section(".bss")));

uint16_t objectIndex = 0; // default cube.
bool droneShow = true; // default to drone show mode.

InputState *input_state_data(void) {
	return &g_input;
}

void input_state_init(void) {
	memset(&g_input, 0, sizeof(g_input));
	objectIndex = 0; // default cube.
	droneShow = true; // default to drone show mode.
}

void input_state_clear_edges(InputState *state) {
	state->edge.rotateLeft = false;
	state->edge.rotateRight = false;
	state->edge.rotateUp = false;
	state->edge.rotateDown = false;
	state->edge.resetCam = false;

}
