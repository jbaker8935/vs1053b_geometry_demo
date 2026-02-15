#include "../include/game_state.h"
#include "../include/3d_object.h"
#include "../include/drone_show.h"
#include "../include/destruct.h"
#include "../include/input.h"

/* minimal text API (avoid including f256lib.h here to prevent typedef collisions) */
extern void textGotoXY(unsigned char x, unsigned char y);
extern void textPrint(const char *message);
extern void textPrintUInt(unsigned int value);

#include <string.h>
#include <stdio.h>

extern void setup_camera_params(uint8_t pitch, uint8_t yaw, uint8_t roll,
                                 int16_t pos_x, int16_t pos_y, int16_t pos_z);

extern int16_t sin_table[256];

extern int32_t mathSignedMultiply(int16_t a, int16_t b);

static GameContext g_ctx __attribute__((section(".bss")));


static void reset_player(Player *player) {
	player->x = SCREEN_WIDTH / 2;
	player->y = SCREEN_HEIGHT - 32;
	player->z = 0;
	player->vx = 0;
	player->vy = 0;
	player->speed = 3;
	player->headingStep = 0;
	player->health = 100;
	player->ammoPrimary = 999;
	player->ammoLaser = 100;
	player->grenades = 5;
	player->primaryCooldown = 0;
	player->laserCooldown = 0;
	player->grenadeCooldown = 0;
}

static void reset_camera(void) {
	// Camera at +Z looking down -Z
	vec3_t cam_pos = {0, 200.0f, 1400.0f};
	camera_init(&g_ctx.wireframe.camera, cam_pos);
	camera_look_at(&g_ctx.wireframe.camera, g_ctx.wireframe.instances[0].position);
	Camera *camera = &g_ctx.wireframe.camera;
	setup_camera_params(
		camera->pitch, camera->yaw, camera->roll,
		camera->position.x, camera->position.y, camera->position.z); 	
}

GameContext *game_state_data(void) {
	return &g_ctx;
}

void game_state_init(GameMode mode) {
	memset(&g_ctx, 0, sizeof(g_ctx));
	g_ctx.mode = mode;
	g_ctx.mapOverlayVisible = false;
	reset_player(&g_ctx.player);
	// Initialize 3D wireframe instances from generated paths (SoA layout)
	switch (mode) {
		case STATE_DRONE_SHOW:
			g_ctx.wireframe.instance_count = DRONE_COUNT;
			// Load the first animation frame once; it populates the full `frame_drones[]` array.
			resetDroneAnimation();
			loadNextDroneFrame();
			break;
		case STATE_DESTRUCT:
			g_ctx.wireframe.instance_count = DESTRUCT_COUNT;
			resetDestructAnimation();
			loadNextDestructFrame();
			break;
		default:
			g_ctx.wireframe.instance_count = 0;
			break;
	}
	for (uint8_t i = 0; i < g_ctx.wireframe.instance_count; ++i) {

		g_ctx.wireframe.instances[i].model = &g_model_cube; // default model

		int16_t sx, sy, sz;
		uint8_t syaw, spitch, sroll;
		if (g_ctx.mode == STATE_DESTRUCT) {
			sx = frame_destruct[i].x;
			sy = frame_destruct[i].y;
			sz = frame_destruct[i].z;
			syaw = frame_destruct[i].yaw;
			spitch = frame_destruct[i].pitch;
			sroll = frame_destruct[i].roll;
		} else {
			sx = frame_drones[i].x;
			sy = frame_drones[i].y;
			sz = frame_drones[i].z;
			syaw = frame_drones[i].yaw;
			spitch = frame_drones[i].pitch;
			sroll = frame_drones[i].roll;
		}
		g_ctx.wireframe.instances[i].position = (vec3_t){sx, sy, sz};
		g_ctx.wireframe.instances[i].yaw = syaw;
		g_ctx.wireframe.instances[i].pitch = spitch;
		g_ctx.wireframe.instances[i].roll = sroll;
		g_ctx.wireframe.instances[i].scale = 128; // 1.0 in Q7

	}

	reset_camera();
}



void game_state_increment_frame(void) {
	g_ctx.frameCounter++;
}



int16_t game_state_clamp16(int16_t value, int16_t min, int16_t max) {
	if (value < min) {
		return min;
	}
	if (value > max) {
		return max;
	}
	return value;
}

void game_state_update_3d(InputState *input) {

	g_ctx.mode = droneShow ? STATE_DRONE_SHOW : STATE_DESTRUCT;
	
	if(input->edge.resetCam) {
		reset_camera();
	}

	switch (g_ctx.mode) {
		case STATE_DRONE_SHOW:
			loadNextDroneFrame();
			break;
		case STATE_DESTRUCT:
			loadNextDestructFrame();
			break;
		default:
			break;
	}

	/* Debug: show current destruct frame index */
	if (g_ctx.mode == STATE_DESTRUCT) {
		char buffer[32];
		textGotoXY(0, 2);
		textPrint("Destruct frame: ");
		sprintf(buffer, "%05u", destruct_get_frame());
		textPrint(buffer);
	}
	
	for (uint8_t i = 0; i < g_ctx.wireframe.instance_count ; ++i) {
		switch(g_ctx.mode) {
			case STATE_DRONE_SHOW:
				switch (objectIndex) {
					case 0:
						g_ctx.wireframe.instances[i].model = &g_model_cube;  // DEBUG: line instead of cube
						break;
					case 1:
						g_ctx.wireframe.instances[i].model = &g_model_tetrahedra;
						break;
					case 2:
						g_ctx.wireframe.instances[i].model = &g_model_square_pyramid;
						break;
					case 3:
						g_ctx.wireframe.instances[i].model = &g_model_octahedron;
						break;
					case 4:
						g_ctx.wireframe.instances[i].model = &g_model_hexagonal_pyramid;
						break;				
					default:
						g_ctx.wireframe.instances[i].model = &g_model_cube;
						break;
				}
				break;
			case STATE_DESTRUCT:
				// cube only for destruct animation
				g_ctx.wireframe.instances[i].model = &g_model_cube;
				break;
			default:
				break;
		}

		if (g_ctx.mode == STATE_DESTRUCT) {
			g_ctx.wireframe.instances[i].position.x = frame_destruct[i].x;
			g_ctx.wireframe.instances[i].position.y = frame_destruct[i].y;
			g_ctx.wireframe.instances[i].position.z = frame_destruct[i].z;
			g_ctx.wireframe.instances[i].yaw = frame_destruct[i].yaw;
			g_ctx.wireframe.instances[i].pitch = frame_destruct[i].pitch;
			g_ctx.wireframe.instances[i].roll = frame_destruct[i].roll;
		} else {
			g_ctx.wireframe.instances[i].position.x = frame_drones[i].x;
			g_ctx.wireframe.instances[i].position.y = frame_drones[i].y;
			g_ctx.wireframe.instances[i].position.z = frame_drones[i].z;
			g_ctx.wireframe.instances[i].yaw = frame_drones[i].yaw;
			g_ctx.wireframe.instances[i].pitch = frame_drones[i].pitch;
			g_ctx.wireframe.instances[i].roll = frame_drones[i].roll;
		}
		g_ctx.wireframe.instances[i].scale = 64; // fixed scale 50% Q7

	}

	int16_t speed = 70; // Movement speed

	uint8_t yaw = g_ctx.wireframe.camera.yaw;
	uint8_t pitch = g_ctx.wireframe.camera.pitch;
	int16_t cy = sin_table[(uint8_t)(yaw+64)&0xFF]; 
	int16_t sy = sin_table[yaw];
	int16_t sp = sin_table[pitch];
	int16_t cp = sin_table[(uint8_t)(pitch+64)&0xFF];

	int32_t tmp_fx = mathSignedMultiply(sy, cp); 
	int16_t fwd_x = (int16_t)(-(tmp_fx >> 14));
	int16_t fwd_y = sp; // vertical component (Q14)
	int32_t tmp_fz = mathSignedMultiply(cy, cp);
	int16_t fwd_z = (int16_t)(-(tmp_fz >> 14));

	int16_t right_x = cy;
	int16_t right_z = -sy;

    int16_t applied_dx = 0;
    int16_t applied_dz = 0;
    int16_t applied_dy = 0;

    if (input->hold.w && g_ctx.wireframe.camera.position.x < 8192 && g_ctx.wireframe.camera.position.z < 8192) {
        // camera position += forward * speed (signed Q14 math)
        int16_t dx = (int16_t)(mathSignedMultiply(fwd_x, speed) >> 14);
        int16_t dz = (int16_t)(mathSignedMultiply(fwd_z, speed) >> 14);
        int16_t dy = (int16_t)(mathSignedMultiply(fwd_y, speed) >> 14);
        g_ctx.wireframe.camera.position.x = g_ctx.wireframe.camera.position.x + dx;
        g_ctx.wireframe.camera.position.z = g_ctx.wireframe.camera.position.z + dz;
        g_ctx.wireframe.camera.position.y = game_state_clamp16(g_ctx.wireframe.camera.position.y + dy, -8192, 8192);
        applied_dx += dx;
        applied_dz += dz;
        applied_dy += dy;
		g_ctx.wireframe.camera.moved = true;
    }
    if (input->hold.s && g_ctx.wireframe.camera.position.x > -8192 && g_ctx.wireframe.camera.position.z > -8192) {
        // camera position -= forward * speed (signed Q14 math)
        int16_t dx = (int16_t)(mathSignedMultiply(fwd_x, speed) >> 14);
        int16_t dz = (int16_t)(mathSignedMultiply(fwd_z, speed) >> 14);
        int16_t dy = (int16_t)(mathSignedMultiply(fwd_y, speed) >> 14);
        g_ctx.wireframe.camera.position.x = g_ctx.wireframe.camera.position.x - dx;
        g_ctx.wireframe.camera.position.z = g_ctx.wireframe.camera.position.z - dz;
        g_ctx.wireframe.camera.position.y = game_state_clamp16(g_ctx.wireframe.camera.position.y - dy, -8192, 8192);
        applied_dx -= dx;
        applied_dz -= dz;
        applied_dy -= dy;
		g_ctx.wireframe.camera.moved = true;
    }
    if (input->hold.a && g_ctx.wireframe.camera.position.x > -8192 && g_ctx.wireframe.camera.position.z > -8192) {
        // strafe left; camera position -= right * speed (signed Q14 math)
        int16_t dx = (int16_t)(mathSignedMultiply(right_x, speed) >> 14);
        int16_t dz = (int16_t)(mathSignedMultiply(right_z, speed) >> 14);
        g_ctx.wireframe.camera.position.x = g_ctx.wireframe.camera.position.x - dx;
        g_ctx.wireframe.camera.position.z = g_ctx.wireframe.camera.position.z - dz;
        applied_dx -= dx;
        applied_dz -= dz;
		g_ctx.wireframe.camera.moved = true;
    }
    if (input->hold.d && g_ctx.wireframe.camera.position.x < 8192 && g_ctx.wireframe.camera.position.z < 8192) {
        // strafe right; camera position += right * speed (signed Q14 math)
        int16_t dx = (int16_t)(mathSignedMultiply(right_x, speed) >> 14);
        int16_t dz = (int16_t)(mathSignedMultiply(right_z, speed) >> 14);
        g_ctx.wireframe.camera.position.x = g_ctx.wireframe.camera.position.x + dx;
        g_ctx.wireframe.camera.position.z = g_ctx.wireframe.camera.position.z + dz;
        applied_dx += dx;
        applied_dz += dz;
		g_ctx.wireframe.camera.moved = true;
    }
    if (input->hold.t && g_ctx.wireframe.camera.position.y < 8192) {
        // camera up
        // `speed` is already a small integer; dividing by 16384 produced 0 previously.
        // Use `speed` directly so vertical movement is visible and consistent with horizontal speed.
        int16_t dy = (int16_t) speed;
        g_ctx.wireframe.camera.position.y = g_ctx.wireframe.camera.position.y + dy;
		g_ctx.wireframe.camera.moved = true;
    }
    if (input->hold.g && g_ctx.wireframe.camera.position.y > -8192) {
        // camera down
        int16_t dy = (int16_t) speed;
        g_ctx.wireframe.camera.position.y = g_ctx.wireframe.camera.position.y - dy;
		g_ctx.wireframe.camera.moved = true;
    }		

	// Camera rotation (Yaw)
	// 256 steps = 360 degrees. 1 step approx 1.4 degrees.
	if (input->hold.rotateLeft) {
		g_ctx.wireframe.camera.yaw += 2;
		g_ctx.wireframe.camera.moved = true;		
	}
	if (input->hold.rotateRight) {
		g_ctx.wireframe.camera.yaw -= 2;
		g_ctx.wireframe.camera.moved = true;		
	}
	// Camera rotation (Yaw)
	// 256 steps = 360 degrees. 1 step approx 1.4 degrees.
	// Pitch control: respond to both hold and edge so single presses and holds behave consistently.
	if (input->hold.rotateUp || input->edge.rotateUp) {
		g_ctx.wireframe.camera.pitch += 2;
		g_ctx.wireframe.camera.moved = true;
	}
	if (input->hold.rotateDown || input->edge.rotateDown) {
		g_ctx.wireframe.camera.pitch -= 2;
		g_ctx.wireframe.camera.moved = true;
	}	
}

