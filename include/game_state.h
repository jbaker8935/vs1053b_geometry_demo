#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <stdbool.h>
#include <stdint.h>
#include "../include/3d_object.h"
#include "../include/input.h"

#define SCREEN_WIDTH   320
#define SCREEN_HEIGHT  240
#define ROTATION_STEPS 8
#define MAX_ARENAS      4
#define MAX_NEIGHBORS   3
#define FIRE_DELAY      6
#define LASER_DELAY     12
#define GRENADE_DELAY   30
#define TUNNEL_RING_TARGET 64

#define INSTANCE_COUNT 27

typedef enum {
	STATE_DRONE_SHOW,
	STATE_DESTRUCT
} GameMode;

typedef struct {
	int16_t x;
	int16_t y;
	int16_t z;
	int16_t vx;
	int16_t vy;
	uint16_t speed;
	uint8_t headingStep;
	uint16_t health;
	uint16_t ammoPrimary;
	uint16_t ammoLaser;
	uint8_t grenades;
	uint16_t primaryCooldown;
	uint16_t laserCooldown;
	uint16_t grenadeCooldown;
} Player;

typedef struct {
	int8_t id;
	int8_t neighbors[MAX_NEIGHBORS];
	bool   blocked[MAX_NEIGHBORS];
	uint8_t neighborCount;
	uint8_t playerWinPoints;
	uint8_t enemyWinPoints;
} ArenaNode;

typedef struct {
	uint8_t from;
	uint8_t to;
	int16_t lateral;
	int16_t vertical;
	uint16_t ringIndex;
	uint16_t accuracyScore;
	uint16_t combo;
} TunnelState;

typedef struct {
	Camera camera;
	Instance3D instances[INSTANCE_COUNT];
	uint8_t instance_count;

    // Per-instance path runtime state (Structure-Of-Arrays for efficient indexing)
    const uint8_t *x_deltas[INSTANCE_COUNT];
    uint16_t      x_len[INSTANCE_COUNT]; // byte length (even number for (delta,duration) pairs)
    uint16_t      x_idx[INSTANCE_COUNT]; // byte index into x_deltas (0..len-1)
    uint8_t       x_rem[INSTANCE_COUNT]; // frames remaining in current run

    const uint8_t *y_deltas[INSTANCE_COUNT];
    uint16_t      y_len[INSTANCE_COUNT];
    uint16_t      y_idx[INSTANCE_COUNT];
    uint8_t       y_rem[INSTANCE_COUNT];

    const uint8_t *z_deltas[INSTANCE_COUNT];
    uint16_t      z_len[INSTANCE_COUNT];
    uint16_t      z_idx[INSTANCE_COUNT];
    uint8_t       z_rem[INSTANCE_COUNT];

    /* Current delta values (signed) for the active run */
    int8_t        x_cur[INSTANCE_COUNT];
    int8_t        y_cur[INSTANCE_COUNT];
    int8_t        z_cur[INSTANCE_COUNT];
} Wireframe3D;

typedef struct {
	GameMode mode;
	Player player;
	ArenaNode graph[MAX_ARENAS];
	uint8_t arenaCount;
	uint8_t activeArena;
	TunnelState tunnel;
	uint32_t frameCounter;
	bool mapOverlayVisible;
	Wireframe3D wireframe;
} GameContext;

GameContext *game_state_data(void);
void game_state_init(GameMode mode);
void game_state_enter_arena(uint8_t arenaId);
void game_state_enter_tunnel(uint8_t from, uint8_t to);
void game_state_toggle_map(void);
void game_state_update_3d(InputState *input);
void game_state_increment_frame(void);
void game_state_tick_player_weapons(void);
int16_t game_state_clamp16(int16_t value, int16_t min, int16_t max);

#endif // GAME_STATE_H
