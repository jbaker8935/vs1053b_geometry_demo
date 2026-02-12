#include <stdio.h>
#include <stddef.h>

/* Allow compiling this tool with the host compiler: some project headers use
   target-specific macros (e.g., __zp). Define them as no-ops here so the
   headers are parseable by the generator. */
#ifndef __zp
#define __zp
#endif
#include "../include/draw_line.h"
#include "../include/3d_math.h"
#include "../include/3d_object.h"

int main(void) {
    printf(".equ LINE_LIST_X0, %zu\n", offsetof(struct line_list, x0));
    printf(".equ LINE_LIST_X1, %zu\n", offsetof(struct line_list, x1));
    printf(".equ LINE_LIST_Y, %zu\n", offsetof(struct line_list, y));
    printf(".equ LINE_LIST_COLOR, %zu\n", offsetof(struct line_list, color));
    printf(".equ LINE_LIST_SIZE, %zu\n", sizeof(struct line_list));

    printf(".equ VEC3_X, %zu\n", offsetof(vec3_t, x));
    printf(".equ VEC3_Y, %zu\n", offsetof(vec3_t, y));
    printf(".equ VEC3_Z, %zu\n", offsetof(vec3_t, z));
    printf(".equ VEC3_SIZE, %zu\n", sizeof(vec3_t));

    printf(".equ VEC2_X, %zu\n", offsetof( vec2_t, x));
    printf(".equ VEC2_Y, %zu\n", offsetof( vec2_t, y));
    printf(".equ VEC2_SIZE, %zu\n", sizeof( vec2_t));

    printf(".equ MODEL3D_VERTEX_COUNT, %zu\n", offsetof(Model3D, vertex_count));
    printf(".equ MODEL3D_EDGE_COUNT, %zu\n", offsetof(Model3D, edge_count));
    printf(".equ MODEL3D_CENTER_X, %zu\n", offsetof(Model3D, center_x));
    printf(".equ MODEL3D_CENTER_Y, %zu\n", offsetof(Model3D, center_y));
    printf(".equ MODEL3D_CENTER_Z, %zu\n", offsetof(Model3D, center_z));
    printf(".equ MODEL3D_RADIUS, %zu\n", offsetof(Model3D, radius));
    printf(".equ MODEL3D_VX, %zu\n", offsetof(Model3D, vx));
    printf(".equ MODEL3D_VY, %zu\n", offsetof(Model3D, vy));
    printf(".equ MODEL3D_VZ, %zu\n", offsetof(Model3D, vz));
    printf(".equ MODEL3D_EDGE_A, %zu\n", offsetof(Model3D, edge_a));
    printf(".equ MODEL3D_EDGE_B, %zu\n", offsetof(Model3D, edge_b));
    printf(".equ MODEL3D_SIZE, %zu\n", sizeof(Model3D));
    printf(".equ MODEL3D_MAX_VERTICES, %d\n", MODEL3D_MAX_VERTICES);

    printf(".equ INSTANCE3D_POSITION_X, %zu\n", offsetof(Instance3D, position.x));
    printf(".equ INSTANCE3D_POSITION_Y, %zu\n", offsetof(Instance3D, position.y));
    printf(".equ INSTANCE3D_POSITION_Z, %zu\n", offsetof(Instance3D, position.z));    
    printf(".equ INSTANCE3D_YAW, %zu\n", offsetof(Instance3D, yaw));
    printf(".equ INSTANCE3D_YAW_RATE, %zu\n", offsetof(Instance3D, yaw_rate));
    printf(".equ INSTANCE3D_MODEL, %zu\n", offsetof(Instance3D, model));
    printf(".equ INSTANCE3D_SIZE, %zu\n", sizeof(Instance3D));

    printf(".equ VERTEX_BATCH_SOA_COUNT, %zu\n", offsetof(VertexBatchSoA, count));
    printf(".equ VERTEX_BATCH_SOA_X, %zu\n", offsetof(VertexBatchSoA, x));
    printf(".equ VERTEX_BATCH_SOA_Y, %zu\n", offsetof(VertexBatchSoA, y));
    printf(".equ VERTEX_BATCH_SOA_Z, %zu\n", offsetof(VertexBatchSoA, z));
    printf(".equ VERTEX_BATCH_SOA_SIZE, %zu\n", sizeof(VertexBatchSoA));

    printf(".equ CAMERA_POSITION_X, %zu\n", offsetof(Camera, position.x));
    printf(".equ CAMERA_POSITION_Y, %zu\n", offsetof(Camera, position.y));
    printf(".equ CAMERA_POSITION_Z, %zu\n", offsetof(Camera, position.z));
    printf(".equ CAMERA_YAW, %zu\n", offsetof(Camera, yaw));
    printf(".equ CAMERA_PITCH, %zu\n", offsetof(Camera, pitch));
    printf(".equ CAMERA_ROLL, %zu\n", offsetof(Camera, roll));
    printf(".equ CAMERA_SIZE, %zu\n", sizeof(Camera));

    return 0;
}