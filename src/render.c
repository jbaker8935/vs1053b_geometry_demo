#include "f256lib.h"

#include "../include/render.h"

#include <string.h>

#include "../include/3d_object.h"
#include "../include/3d_pipeline.h"
#include "../include/draw_line.h"
#include "../include/geometry_kernel.h"
#include "../include/video.h"

uint8_t out_edge_count = 0;

// Shared display buffer state for proper double buffering
static uint8_t g_visible_layer = 0;

void render_hud(const GameContext *ctx) {
    (void)ctx;  // No HUD elements for now.
}
__attribute__((noinline)) void render_frame(const GameContext *ctx) {
    uint8_t draw_layer = 1 - g_visible_layer;

    bitmapSetActive(draw_layer);

    const uint8_t color = (uint8_t)(1 + ((ctx->frameCounter / 30) % 10));  // Cycle colors every 30 frames
    // if ((ctx->frameCounter & 0xF) == 0) {
    //     textGotoXY(0, 1);
    //     textPrintUInt(ctx->frameCounter);
    // }

    Camera *camera = &ctx->wireframe.camera;
    if (camera->moved) {
        setup_camera_params(camera->pitch, camera->yaw, camera->roll, camera->position.x, camera->position.y,
                            camera->position.z);
        camera->moved = false;  // reset moved flag until next change
    }

    for (uint8_t i = 0; i < ctx->wireframe.instance_count; ++i) {
        Instance3D *inst = &ctx->wireframe.instances[i];

        // if(i > 17) continue; //  Used to limit instances drawn per frame for testing --- IGNORE ---


		// For test 'many' will load different model for each instance
        if (input_state_data()->edge.many) {
            switch (i % 5) {
                case 0:
                    inst->model = &g_model_cube;  // DEBUG: line instead of cube
                    break;
                case 1:
                    inst->model = &g_model_tetrahedra;
                    break;
                case 2:
                    inst->model = &g_model_square_pyramid;
                    break;
                case 3:
                    inst->model = &g_model_octahedron;
                    break;
                case 4:
                    inst->model = &g_model_hexagonal_pyramid;
                    break;
                default:
                    inst->model = &g_model_cube;
                    break;
            }
				geometry_kernel_load(i % 5); // load from plugin slot
        } else {
			// otherwise load the model set by game_state_update_3d().
			// only the first instance in the loop needs to load.
            if (i == 0) {
                geometry_kernel_load(objectIndex);
            }
        }

        transform_instance_to_screen(inst, &ctx->wireframe.camera);
        // out_edge_count = get_screen_edges(inst->model, 11);        
        out_edge_count = get_screen_edges_with_depth(inst->model, 11,12);
        draw_lines_asm(draw_layer);
        // Clear line list after drawing to leave a clean slate for the next instance.
        reset_line_list();
    }

    video_wait_vblank();
    // Swap buffers to make the newly rendered frame visible
    bitmapSetVisible(draw_layer, true);
    bitmapSetVisible(g_visible_layer, false);
    dmaBitmapClear(g_visible_layer);
    g_visible_layer = draw_layer;

    render_hud(ctx);
}
