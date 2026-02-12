#include "../include/3d_object.h"
#include "../include/3d_math.h"
#include <stdbool.h>
#include <string.h>

// Cube vertices: scaled to fit int16, centered at origin
// Scale by 100 for visibility (25% of previous 1000)
#define SCALE 200

static const int16_t g_cube_vx[8] = {
    -1 * SCALE, -1 * SCALE, -1 * SCALE, -1 * SCALE,
     1 * SCALE,  1 * SCALE,  1 * SCALE,  1 * SCALE,
};
static const int16_t g_cube_vy[8] = {
    -1 * SCALE, -1 * SCALE,  1 * SCALE,  1 * SCALE,
    -1 * SCALE, -1 * SCALE,  1 * SCALE,  1 * SCALE,
};
static const int16_t g_cube_vz[8] = {
    -1 * SCALE,  1 * SCALE, -1 * SCALE,  1 * SCALE,
    -1 * SCALE,  1 * SCALE, -1 * SCALE,  1 * SCALE,
};
static const uint8_t g_cube_edge_a[12] = {
    0, 0, 0, 1, 1, 2, 2, 3, 4, 4, 5, 6,
};
static const uint8_t g_cube_edge_b[12] = {
    1, 2, 4, 3, 5, 3, 6, 7, 5, 6, 7, 7,
};
const Model3D g_model_cube = {
    .vertex_count = 8,  // debug 2 instead of 8
    .edge_count = 12,    // debug 1 instead of 12
    .vx = g_cube_vx,
    .vy = g_cube_vy,
    .vz = g_cube_vz,
    .edge_a = g_cube_edge_a,
    .edge_b = g_cube_edge_b,
    // Center and radius derived from the provided AABB.
    .center_x = 0,
    .center_y = 0,
    .center_z = 0,
    .radius = 173, // sqrt(3*100^2)
};

static const int16_t g_ico_vx[30] = {
    // Set A (±1, ±1, ±1)
    -200, -200, -200, -200,  200,  200,  200,  200,

    // Set B (0, ±1/φ, ±φ)
       0,    0,    0,    0,    0,    0,
       0,    0,    0,    0,    0,    0,

    // Set C (±1/φ, ±φ, 0)
    -124, -124,  124,  124, -124, -124,  124,  124, -124, 124
};

static const int16_t g_ico_vy[30] = {
    // Set A
    -200, -200,  200,  200, -200, -200,  200,  200,

    // Set B (0, ±1/φ, ±φ)
    -124,  124, -124,  124, -324,  324,
    -324,  324, -124,  124, -124, 124,

    // Set C (±1/φ, ±φ, 0)
    -324,  324, -324,  324,    0,    0,    0,    0,  324, -324
};

static const int16_t g_ico_vz[30] = {
    // Set A
    -200,  200, -200,  200, -200,  200, -200,  200,

    // Set B (0, ±1/φ, ±φ)
    -324, -324,  324,  324, -124, -124,
     124,  124, -324, -324,  324,  324,

    // Set C (±1/φ, ±φ, 0)
       0,    0,    0,    0, -124,  124, -124, 124,    0,    0
};

static const uint8_t g_ico_edge_a[60] = {
     0,  0,  0,  1,  1,  1,  2,  2,  2,  3,
     3,  3,  4,  4,  4,  5,  5,  5,  6,  6,
     6,  7,  7,  7,  8,  8,  8,  9,  9,  9,
    10, 10, 10, 11, 11, 11, 12, 12, 12, 13,
    13, 13, 14, 14, 14, 15, 15, 15, 16, 16,
    16, 17, 17, 17, 18, 18, 18, 19, 19, 19
};

static const uint8_t g_ico_edge_b[60] = {
     1,  2,  4,  3,  5,  0,  3,  6,  0,  7,
     1,  2,  0,  8,  9,  1, 10, 11,  2, 12,
    13,  3, 14, 15,  4, 16, 17,  4, 18, 19,
     5, 20, 21,  5, 22, 23,  6, 24, 25,  6,
    26, 27,  7, 28, 29,  7, 28, 29,  8, 16,
    20,  9, 17, 21, 10, 18, 22, 11, 19, 23
};
const Model3D g_model_icosahedron = {
    .vertex_count = 30,
    .edge_count = 60,
    .vx = g_ico_vx,
    .vy = g_ico_vy,
    .vz = g_ico_vz,
    .edge_a = g_ico_edge_a,
    .edge_b = g_ico_edge_b,
    // Center and radius derived from the provided AABB.
    .center_x = 0,
    .center_y = 0,
    .center_z = 0,
    .radius = 324, // distance from center to vertices in set B
};

// Tetrahedron: 4 vertices (regular tetra centered at origin with coordinates
// (1,1,1),(1,-1,-1),(-1,1,-1),(-1,-1,1) scaled by SCALE)
static const int16_t g_tetra_vx[4] = { SCALE,  SCALE, -SCALE, -SCALE };
static const int16_t g_tetra_vy[4] = { SCALE, -SCALE,  SCALE, -SCALE };
static const int16_t g_tetra_vz[4] = { SCALE, -SCALE, -SCALE,  SCALE };
static const uint8_t g_tetra_edge_a[6] = { 0, 0, 0, 1, 1, 2 };
static const uint8_t g_tetra_edge_b[6] = { 1, 2, 3, 2, 3, 3 };
const Model3D g_model_tetrahedra = {
    .vertex_count = 4,
    .edge_count = 6,
    .vx = g_tetra_vx,
    .vy = g_tetra_vy,
    .vz = g_tetra_vz,
    .edge_a = g_tetra_edge_a,
    .edge_b = g_tetra_edge_b,
    .center_x = 0,
    .center_y = 0,
    .center_z = 0,
    .radius = 207, // SCALE * sqrt(3)
};


// Square pyramid: 5 vertices (square base in XZ at y=-SCALE and apex at y=2*SCALE; apex along +Y)
static const int16_t g_square_pyramid_vx[5] = { -SCALE,  SCALE,  SCALE, -SCALE,  0 };
static const int16_t g_square_pyramid_vy[5] = { -SCALE, -SCALE, -SCALE, -SCALE, 2*SCALE };
static const int16_t g_square_pyramid_vz[5] = { -SCALE, -SCALE,  SCALE,  SCALE,  0 };
static const uint8_t g_square_pyramid_edge_a[8] = { 0, 1, 2, 3, 4, 4, 4, 4 };
static const uint8_t g_square_pyramid_edge_b[8] = { 1, 2, 3, 0, 0, 1, 2, 3 };
const Model3D g_model_square_pyramid = {
    .vertex_count = 5,
    .edge_count = 8,
    .vx = g_square_pyramid_vx,
    .vy = g_square_pyramid_vy,
    .vz = g_square_pyramid_vz,
    .edge_a = g_square_pyramid_edge_a,
    .edge_b = g_square_pyramid_edge_b,
    .center_x = 0,
    .center_y = -48, // average of vertex y positions: (-120*4 + 240)/5 = -48
    .center_z = 0,
    .radius = 288,   // max distance from center to apex (288)
};


// Octahedron: 6 vertices (axis-aligned octahedron centered at origin)
// Vertices: (±SCALE,0,0), (0,±SCALE,0), (0,0,±SCALE)
static const int16_t g_octa_vx[6] = {  SCALE, -SCALE,  0,  0,  0,  0 };
static const int16_t g_octa_vy[6] = {  0,  0,  SCALE, -SCALE,  0,  0 };
static const int16_t g_octa_vz[6] = {  0,  0,  0,  0,  SCALE, -SCALE };
static const uint8_t g_octa_edge_a[12] = { 0, 0, 0, 0,  1, 1, 1, 1,  2, 2, 3, 3 };
static const uint8_t g_octa_edge_b[12] = { 2, 3, 4, 5,  2, 3, 4, 5,  4, 5, 4, 5 };
const Model3D g_model_octahedron = {
    .vertex_count = 6,
    .edge_count = 12,
    .vx = g_octa_vx,
    .vy = g_octa_vy,
    .vz = g_octa_vz,
    .edge_a = g_octa_edge_a,
    .edge_b = g_octa_edge_b,
    .center_x = 0,
    .center_y = 0,
    .center_z = 0,
    .radius = SCALE,
};

// Hexagonal pyramid: 7 vertices (hexagon base in XZ plane at y=-SCALE, apex along +Y)
// Base vertices arranged CCW starting at +X: angles 0,60,120,180,240,300 degrees
static const int16_t g_hex_pyr_vx[7] = {
    1.0f*SCALE,  0.5f*SCALE, -0.5f*SCALE, -1.0f*SCALE,
   -0.5f*SCALE,  0.5f*SCALE,  0.0f
};
static const int16_t g_hex_pyr_vy[7] = {
   -1.0f*SCALE, -1.0f*SCALE, -1.0f*SCALE, -1.0f*SCALE,
   -1.0f*SCALE, -1.0f*SCALE,  2.0f*SCALE
};
static const int16_t g_hex_pyr_vz[7] = {
    0.0f,  0.8660254f*SCALE,  0.8660254f*SCALE,  0.0f,
   -0.8660254f*SCALE, -0.8660254f*SCALE,  0.0f
};
static const uint8_t g_hex_pyr_edge_a[12] = { 0,1,2,3,4,5, 6,6,6,6,6,6 };
static const uint8_t g_hex_pyr_edge_b[12] = { 1,2,3,4,5,0, 0,1,2,3,4,5 };
const Model3D g_model_hexagonal_pyramid = {
    .vertex_count = 7,
    .edge_count = 12,
    .vx = g_hex_pyr_vx,
    .vy = g_hex_pyr_vy,
    .vz = g_hex_pyr_vz,
    .edge_a = g_hex_pyr_edge_a,
    .edge_b = g_hex_pyr_edge_b,
    .center_x = 0.0,
    .center_y = -68, // average Y: ((-SCALE*6)+(2*SCALE))/7 = -4/7*SCALE
    .center_z = 0,
    .radius = 308, // distance from center to apex: 18/7 * SCALE
};



void camera_init(Camera *cam, vec3_t pos) {
    cam->position = pos;
    cam->yaw = 0;
    cam->pitch = 0;
    cam->roll = 0;
    cam->moved = false;
}

void camera_look_at(Camera *cam, vec3_t target) {
    // Simplified: assume looking at origin from -Z
    cam->yaw = 0;
    cam->pitch = 0;
    cam->roll = 0;
}
