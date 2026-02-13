#ifndef GEOMETRY_KERNEL_H
#define GEOMETRY_KERNEL_H
#include <stdint.h>
#include "../include/muVS1053b.h"
#include "../include/3d_math.h"
#include "../include/3d_object.h"

// VS1053b SCI register addresses
#define SCI_MODE        0x00
#define SCI_STATUS      0x01
#define SCI_WRAMADDR    0x07
#define SCI_WRAM        0x06
#define SCI_AIADDR      0x0A
#define SCI_AICTRL0     0x0C
#define SCI_AICTRL1     0x0D
#define SCI_AICTRL2     0x0E
#define SCI_AICTRL3     0x0F
// Memory space offsets for WRAMADDR
#define IRAM_OFFSET     0x8000
#define XRAM_OFFSET     0x0000
#define YRAM_OFFSET     0x4000
// ==============================================================================
// MEMORY MAP
// ==============================================================================

// I-RAM Plugin Entry (WRAMADDR = DSP address + 0x8000)
#define HOST_GEOM_PLUGIN_ENTRY  0x8050  // DSP: 0x0050

#define VS_GEOM_MAX_VERTICES  32
#define VS_GEOM_MAX_EDGES     36
// Input Parameters (X-RAM)
#define VS_GEOM_N_VERTICES    0x1800  // Number of vertices (16-bit)

// Packed Euler inputs (8-bit indices) and Q7 scale (packed)
// Ordered consecutively so SCI autoincrement can be used to write the values.
#define VS_GEOM_OBJ_PITCH_YAW  0x1801  // packed: high byte pitch, low byte yaw
#define VS_GEOM_OBJ_ROLL_SCALE 0x1802  // packed: high byte roll, low byte scale (Q7)
#define VS_GEOM_OBJ_POS_X      0x1803  // World position X
#define VS_GEOM_OBJ_POS_Y      0x1804  // World position Y
#define VS_GEOM_OBJ_POS_Z      0x1805  // World position Z

#define VS_GEOM_CAM_PITCH_YAW  0x1806  // packed: high byte pitch, low byte yaw
#define VS_GEOM_CAM_ROLL_SCALE 0x1807  // packed: high byte roll, low byte scale (Q7)
#define VS_GEOM_CAM_POS_X      0x1808  // Camera position X
#define VS_GEOM_CAM_POS_Y      0x1809  // Camera position Y
#define VS_GEOM_CAM_POS_Z      0x180A  // Camera position Z

// Unpacked trig and scale (kernel writes these based on the packed inputs for convenience)
#define VS_GEOM_OBJ_SX        0x180B  // sin(rx) Q14
#define VS_GEOM_OBJ_CX        0x180C  // cos(rx) Q14
#define VS_GEOM_OBJ_SY        0x180D  // sin(ry) Q14
#define VS_GEOM_OBJ_CY        0x180E  // cos(ry) Q14
#define VS_GEOM_OBJ_SZ        0x180F  // sin(rz) Q14
#define VS_GEOM_OBJ_CZ        0x1810  // cos(rz) Q14
#define VS_GEOM_OBJ_SCALE     0x1811  // Global scale Q14 (converted from Q7)

#define VS_GEOM_CAM_SX        0x1812  // sin(rx) Q14
#define VS_GEOM_CAM_CX        0x1813  // cos(rx) Q14
#define VS_GEOM_CAM_SY        0x1814  // sin(ry) Q14
#define VS_GEOM_CAM_CY        0x1815  // cos(ry) Q14
#define VS_GEOM_CAM_SZ        0x1816  // sin(rz) Q14
#define VS_GEOM_CAM_CZ        0x1817  // cos(rz) Q14

// Convenience aliases
#define VS_GEOM_OBJ_TRIG      VS_GEOM_OBJ_SX
#define VS_GEOM_CAM_TRIG      VS_GEOM_CAM_SX

// Input/Output Buffers
#define VS_GEOM_INPUT_VERT    0x1818  // Input vertices (X-RAM)
#define VS_GEOM_OUTPUT_VERT   0x580C  // Output vertices (Y-RAM)

// Matrix storage (Y-RAM) - 3x4 = 12 words
#define VS_GEOM_MATRIX_BASE   0x5800  // Final composite matrix
#define VS_GEOM_TEMP_OBJ      0x1EDA  // Object matrix temp (12 words, X-RAM)
#define VS_GEOM_TEMP_CAM      0x5860  // Camera matrix temp (12 words, Y-RAM)

// Magic trigger value for SCI_AICTRL0 (PLUGIN_MODE)
#define VS_GEOM_TRIGGER_MAGIC 0xCAFE  // Write this to SCI_AICTRL0 to trigger

// Internal kernal state memory (X-RAM)
#define VS_GEOM_LR0_SAVE_PROJECT           0x1ED7  // For _project_all_vertices
#define VS_GEOM_LR0_SAVE_CLIP              0x1ED8  // For _clip_all_edges
#define VS_GEOM_LR0_SAVE_CLIP_AND_PROJECT  0x1ED9  // For _clip_and_project

// Edge List (X-RAM: placed inside free X-RAM region to avoid audio decoder memory)
// Base free X-RAM region per memory map: 0x3565..0x3FFF

#define VS_GEOM_X_FREE_BASE     0x3600  // Aligned free X-RAM base (within free_x memory define provided by VLSI)
#define VS_GEOM_N_EDGES         VS_GEOM_X_FREE_BASE         // Number of input edges (X-RAM)
#define VS_GEOM_EDGE_LIST       (VS_GEOM_X_FREE_BASE + 1)   // Edge list (packed): [v0_low | v1_high] × n (1 word per edge)
// Edge list ends at (VS_GEOM_X_FREE_BASE + 0x24) inclusive (max 36 edges) 
#define VS_GEOM_MAX_INPUT_EDGES 36  // Maximum allowed input edges (match output edge capacity)

// Status and Projection Parameters 

#define VS_GEOM_STATUS_IDLE         0
#define VS_GEOM_STATUS_BUSY         1
#define VS_GEOM_STATUS_DONE         0xABCD
#define VS_GEOM_STATUS_SAVE_ERROR   0xE201
#define VS_GEOM_STATUS_LOAD_ERROR   0xE202

#define VS_GEOM_LR0_SAVE        (VS_GEOM_X_FREE_BASE + 0xA2)  // Save/restore LR0 (X-RAM)
#define VS_GEOM_STATUS          (VS_GEOM_X_FREE_BASE + 0xA3)  // 0=idle, 1=busy, 0xABCD=done (X-RAM)
#define VS_GEOM_ENABLE_PROJECT  (VS_GEOM_X_FREE_BASE + 0xA4)  // Non-zero to enable projection
#define VS_GEOM_ENABLE_CLIP     (VS_GEOM_X_FREE_BASE + 0xA5)  // Non-zero to enable clipping
#define VS_GEOM_PROJ_FOCAL      (VS_GEOM_X_FREE_BASE + 0xA6)  // Focal length (Q0, = half_w for 90 deg FOV)
#define VS_GEOM_PROJ_HALF_W     (VS_GEOM_X_FREE_BASE + 0xA7)  // Half screen width (Q0, e.g., 160)
#define VS_GEOM_PROJ_HALF_H     (VS_GEOM_X_FREE_BASE + 0xA8)  // Half screen height (Q0, e.g., 120)
#define VS_GEOM_PROJ_NEAR_Z     (VS_GEOM_X_FREE_BASE + 0xA9)  // Near plane Z (Q0, negative, e.g., -256)
#define VS_GEOM_SCRATCH0        (VS_GEOM_X_FREE_BASE + 0xAA)  // General scratch (X-RAM)
#define VS_GEOM_SCRATCH1        (VS_GEOM_X_FREE_BASE + 0xAB)  // General scratch (X-RAM)
#define VS_GEOM_LR0_SAVE2       (VS_GEOM_X_FREE_BASE + 0xAC)  // Save/restore LR0 (X-RAM)
#define VS_GEOM_LR0_SAVE3       (VS_GEOM_X_FREE_BASE + 0xAD)  // Save/restore LR0 (X-RAM)

// Screen Coordinates Output (X-RAM)
#define VS_GEOM_SCREEN_COORDS_X  (VS_GEOM_X_FREE_BASE + 0xC0) // X-RAM: 64 words for [sx,sy] × up to 32 verts
#define VS_GEOM_SCREEN_COORDS    VS_GEOM_SCREEN_COORDS_X      // Alias

// Clipping Output (X-RAM)
#define VS_GEOM_N_CLIP_VERTS_X  (VS_GEOM_X_FREE_BASE + 0x170) // X-RAM: count (1 word)
#define VS_GEOM_CLIP_VERTS_X    (VS_GEOM_X_FREE_BASE + 0x171) // X-RAM: clip verts buffer (48 words)
#define VS_GEOM_N_CLIP_VERTS    VS_GEOM_N_CLIP_VERTS_X
#define VS_GEOM_CLIP_VERTS      VS_GEOM_CLIP_VERTS_X
#define VS_GEOM_CLIP_SCREEN_X   (VS_GEOM_X_FREE_BASE + 0x100) // X-RAM: 32 words for [sx,sy] × up to 16 verts
#define VS_GEOM_CLIP_SCREEN     VS_GEOM_CLIP_SCREEN_X
#define VS_GEOM_N_OUTPUT_EDGES_X (VS_GEOM_X_FREE_BASE + 0x120) // X-RAM: count (1 word)
#define VS_GEOM_OUTPUT_EDGES_X   (VS_GEOM_X_FREE_BASE + 0x121) // X-RAM: edges buffer (72 words)
#define VS_GEOM_N_OUTPUT_EDGES   VS_GEOM_N_OUTPUT_EDGES_X
#define VS_GEOM_OUTPUT_EDGES     VS_GEOM_OUTPUT_EDGES_X

// Edge flags for output
#define VS_GEOM_EDGE_VISIBLE    0x0001  // Edge is visible
#define VS_GEOM_EDGE_CLIP_V0    0x0002  // V0 was clipped (new vertex created)
#define VS_GEOM_EDGE_CLIP_V1    0x0004  // V1 was clipped (new vertex created)
#define VS_GEOM_EDGE_CULLED     0x0000  // Edge is culled

extern const int16_t sin_table[256];
uint8_t get_screen_edges(Model3D * model, uint8_t color);
// geometry kernel functions
void setup_object_params(uint8_t pitch, uint8_t yaw, uint8_t roll, uint8_t scale,
                         int16_t pos_x, int16_t pos_y, int16_t pos_z);
void setup_camera_params(uint8_t pitch, uint8_t yaw, uint8_t roll,
                                 int16_t pos_x, int16_t pos_y, int16_t pos_z);
void setup_model_vertices(const Model3D* model);
void setup_model_edges(const Model3D* model);
void setup_projection_params(int16_t focal, int16_t half_w, int16_t half_h,
                         int16_t near_z);
void trigger_geometry_kernel(void);
void geometry_kernel_reset(void);
uint8_t geometry_kernel_wait_complete(uint16_t timeout_ms);
bool geometry_kernel_save(uint16_t slot);
bool geometry_kernel_load(uint16_t slot);
void load_model_to_plugin(const Model3D* model, uint8_t slot);

#endif // GEOMETRY_KERNEL_H