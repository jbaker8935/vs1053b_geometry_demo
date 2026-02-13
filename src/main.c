#define F256LIB_IMPLEMENTATION
#include "f256lib.h"
#include "../include/game_state.h"
#include "../include/input.h"
#include "../include/input_handler.h"
#include "../include/render.h"
#include "../include/video.h"
#include "../include/3d_math.h"
#include "../include/muVS1053b.h"
#include "../include/geometry_kernel.h"


// Declare the function we need
extern float mathFloatMul(float a, float b);
extern void loadVS1053Plugin();
extern void boostVSClock();
extern void initialize_plugin();

void init_models(void) {
    // Preload model data into the plugin's memory
    load_model_to_plugin(&g_model_cube, 0);
    load_model_to_plugin(&g_model_tetrahedra, 1);
    load_model_to_plugin(&g_model_square_pyramid, 2);
    load_model_to_plugin(&g_model_octahedron, 3);
    load_model_to_plugin(&g_model_hexagonal_pyramid, 4);
}

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;


    f256Init();
    loadVS1053Plugin();
    initialize_plugin();
    boostVSClock();

    game_state_init();
    input_handler_init();
    video_init();

    // 4:3 aspect 320x240 with vertical fov 90 degrees
    setup_projection_params(120, 160, 120, -256); 
    
    init_models();

    GameContext *ctx = game_state_data();
    ctx->mode = STATE_3D_TEST;

    textPrint("VS1053b -- Objects: 1-5,M Cam Pos: WASDTGC Cam Yaw: QE Cam Pitch: RF Exit: X\n");

    while (true) {
        input_handler_poll();
        InputState *input = input_state_data();
        if (input->edge.exit) {
            break;
        }
        ctx = game_state_data();
        game_state_update_3d(input);
        render_frame(ctx);
        game_state_increment_frame();
        input_state_clear_edges(input);
     }
    return 0;
}
