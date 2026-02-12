#include <stddef.h>
#include <stdint.h>

#include "../include/draw_line.h"
#include "../include/3d_math.h"
#include "../include/3d_object.h"

// Emit a global assembler constant.
// `%c0` forces clang to print the operand as a bare constant.
#define EMIT_EQU(name, value) __asm__(".equ " #name ", %c0" : : "i"(value))

__attribute__((used, noinline))
static void emit_struct_offsets(void) {
    EMIT_EQU(LINE_LIST_X0, offsetof(struct line_list, x0));
    EMIT_EQU(LINE_LIST_X1, offsetof(struct line_list, x1));
    EMIT_EQU(LINE_LIST_Y, offsetof(struct line_list, y));
    EMIT_EQU(LINE_LIST_COLOR, offsetof(struct line_list, color));
    EMIT_EQU(LINE_LIST_SIZE, sizeof(struct line_list));

    EMIT_EQU(VEC3_X, offsetof(vec3_t, x));
    EMIT_EQU(VEC3_Y, offsetof(vec3_t, y));
    EMIT_EQU(VEC3_Z, offsetof(vec3_t, z));
    EMIT_EQU(VEC3_SIZE, sizeof(vec3_t));

    EMIT_EQU(VEC2_X, offsetof(vec2_t, x));
    EMIT_EQU(VEC2_Y, offsetof(vec2_t, y));
    EMIT_EQU(VEC2_SIZE, sizeof(vec2_t));

    EMIT_EQU(MODEL3D_VERTEX_COUNT, offsetof(Model3D, vertex_count));
    EMIT_EQU(MODEL3D_EDGE_COUNT, offsetof(Model3D, edge_count));
    EMIT_EQU(MODEL3D_CENTER_X, offsetof(Model3D, center_x));
    EMIT_EQU(MODEL3D_CENTER_Y, offsetof(Model3D, center_y));
    EMIT_EQU(MODEL3D_CENTER_Z, offsetof(Model3D, center_z));
    EMIT_EQU(MODEL3D_RADIUS, offsetof(Model3D, radius));
    EMIT_EQU(MODEL3D_VX, offsetof(Model3D, vx));
    EMIT_EQU(MODEL3D_VY, offsetof(Model3D, vy));
    EMIT_EQU(MODEL3D_VZ, offsetof(Model3D, vz));
    EMIT_EQU(MODEL3D_EDGE_A, offsetof(Model3D, edge_a));
    EMIT_EQU(MODEL3D_EDGE_B, offsetof(Model3D, edge_b));
    EMIT_EQU(MODEL3D_SIZE, sizeof(Model3D));
    EMIT_EQU(MODEL3D_MAX_VERTICES, MODEL3D_MAX_VERTICES);

    EMIT_EQU(INSTANCE3D_POSITION_X, offsetof(Instance3D, position) + offsetof(vec3_t, x));
    EMIT_EQU(INSTANCE3D_POSITION_Y, offsetof(Instance3D, position) + offsetof(vec3_t, y));
    EMIT_EQU(INSTANCE3D_POSITION_Z, offsetof(Instance3D, position) + offsetof(vec3_t, z));
    EMIT_EQU(INSTANCE3D_YAW, offsetof(Instance3D, yaw));
    EMIT_EQU(INSTANCE3D_YAW_RATE, offsetof(Instance3D, yaw_rate));
    EMIT_EQU(INSTANCE3D_MODEL, offsetof(Instance3D, model));
    EMIT_EQU(INSTANCE3D_SIZE, sizeof(Instance3D));

    EMIT_EQU(VERTEX_BATCH_SOA_COUNT, offsetof(VertexBatchSoA, count));
    EMIT_EQU(VERTEX_BATCH_SOA_X, offsetof(VertexBatchSoA, x));
    EMIT_EQU(VERTEX_BATCH_SOA_Y, offsetof(VertexBatchSoA, y));
    EMIT_EQU(VERTEX_BATCH_SOA_Z, offsetof(VertexBatchSoA, z));
    EMIT_EQU(VERTEX_BATCH_SOA_SIZE, sizeof(VertexBatchSoA));

    EMIT_EQU(CAMERA_POSITION_X, offsetof(Camera, position) + offsetof(vec3_t, x));
    EMIT_EQU(CAMERA_POSITION_Y, offsetof(Camera, position) + offsetof(vec3_t, y));
    EMIT_EQU(CAMERA_POSITION_Z, offsetof(Camera, position) + offsetof(vec3_t, z));
    EMIT_EQU(CAMERA_YAW, offsetof(Camera, yaw));
    EMIT_EQU(CAMERA_PITCH, offsetof(Camera, pitch));
    EMIT_EQU(CAMERA_ROLL, offsetof(Camera, roll));
    EMIT_EQU(CAMERA_SIZE, sizeof(Camera));
}

// Ensure the TU is not empty and the function remains in emitted assembly.
__attribute__((used))
static const void *g_emit_struct_offsets_anchor = (const void *)&emit_struct_offsets;
