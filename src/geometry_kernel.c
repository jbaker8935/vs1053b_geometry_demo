#include <stdint.h>
#include "f256lib.h"
#include "../include/geometry_kernel.h"
#include "../include/3d_object.h"
#include "../include/draw_line.h"

const int16_t sin_table[256] = {
    0, 402, 804, 1205, 1606, 2006, 2404, 2801, 3196, 3590, 3981, 4370, 4756, 5139, 5520, 5897, 
    6270, 6639, 7005, 7366, 7723, 8076, 8423, 8765, 9102, 9434, 9760, 10080, 10394, 10702, 11003, 11297, 
    11585, 11866, 12140, 12406, 12665, 12916, 13160, 13395, 13623, 13842, 14053, 14256, 14449, 14635, 14811, 14978, 
    15137, 15286, 15426, 15557, 15679, 15791, 15893, 15986, 16069, 16143, 16207, 16261, 16305, 16340, 16364, 16379, 
    16384, 16379, 16364, 16340, 16305, 16261, 16207, 16143, 16069, 15986, 15893, 15791, 15679, 15557, 15426, 15286, 
    15137, 14978, 14811, 14635, 14449, 14256, 14053, 13842, 13623, 13395, 13160, 12916, 12665, 12406, 12140, 11866, 
    11585, 11297, 11003, 10702, 10394, 10080, 9760, 9434, 9102, 8765, 8423, 8076, 7723, 7366, 7005, 6639, 
    6270, 5897, 5520, 5139, 4756, 4370, 3981, 3590, 3196, 2801, 2404, 2006, 1606, 1205, 804, 402, 
    0, -402, -804, -1205, -1606, -2006, -2404, -2801, -3196, -3590, -3981, -4370, -4756, -5139, -5520, -5897, 
    -6270, -6639, -7005, -7366, -7723, -8076, -8423, -8765, -9102, -9434, -9760, -10080, -10394, -10702, -11003, -11297, 
    -11585, -11866, -12140, -12406, -12665, -12916, -13160, -13395, -13623, -13842, -14053, -14256, -14449, -14635, -14811, -14978, 
    -15137, -15286, -15426, -15557, -15679, -15791, -15893, -15986, -16069, -16143, -16207, -16261, -16305, -16340, -16364, -16379, 
    -16384, -16379, -16364, -16340, -16305, -16261, -16207, -16143, -16069, -15986, -15893, -15791, -15679, -15557, -15426, -15286, 
    -15137, -14978, -14811, -14635, -14449, -14256, -14053, -13842, -13623, -13395, -13160, -12916, -12665, -12406, -12140, -11866, 
    -11585, -11297, -11003, -10702, -10394, -10080, -9760, -9434, -9102, -8765, -8423, -8076, -7723, -7366, -7005, -6639, 
    -6270, -5897, -5520, -5139, -4756, -4370, -3981, -3590, -3196, -2801, -2404, -2006, -1606, -1205, -804, -402, 

};

uint16_t vs1053_read_sci(uint8_t addr) {

  POKE(VS_SCI_ADDR, addr);
  POKE(VS_SCI_CTRL, CTRL_Start | CTRL_RWn);  // Activate xCS and start read
  POKE(VS_SCI_CTRL, 0);                      // Deactivate xCS

  while (PEEK(0xD700) & CTRL_Busy)
  ;
  uint16_t ret = ((uint16_t)PEEK(0xD703) << 8) | PEEK(0xD702);

return ret;
} 

void vs1053_write_sci(uint8_t addr, uint16_t data) {
  POKE(VS_SCI_ADDR, addr);
  POKEW(VS_SCI_DATA, data);
  POKE(VS_SCI_CTRL, CTRL_Start);  // start write
  POKE(VS_SCI_CTRL, 0);           // deactivate
  while (PEEK(0xD700) & CTRL_Busy);
  return;
}

static inline void vs1053_write_mem(uint16_t wram_addr, uint16_t data) {
    vs1053_write_sci(SCI_WRAMADDR, wram_addr);
    vs1053_write_sci(SCI_WRAM, data);
}

uint16_t vs1053_read_mem(uint16_t wram_addr) {
    vs1053_write_sci(SCI_WRAMADDR, wram_addr);
    return vs1053_read_sci(SCI_WRAM);
}

void initialize_plugin(void) {
    vs1053_write_mem(VS_GEOM_STATUS, 0x0000);   // Clear status
    vs1053_write_sci(SCI_AIADDR, 0x0050);  
}

// Setup object transformation parameters
void setup_object_params(uint8_t pitch, uint8_t yaw, uint8_t roll, uint8_t scale,
                         int16_t pos_x, int16_t pos_y, int16_t pos_z) {
    vs1053_write_mem(VS_GEOM_OBJ_PITCH_YAW, (uint16_t)pitch << 8 | yaw);  // sets WRAMADDR, auto increments
    vs1053_write_sci(SCI_WRAM, ((uint16_t)roll << 8) | scale);
    vs1053_write_sci(SCI_WRAM, pos_x);
    vs1053_write_sci(SCI_WRAM, pos_y);
    vs1053_write_sci(SCI_WRAM, pos_z);
}

// Setup camera transformation parameters
void setup_camera_params(uint8_t pitch, uint8_t yaw, uint8_t roll,
                         int16_t pos_x, int16_t pos_y, int16_t pos_z) {
    vs1053_write_mem(VS_GEOM_CAM_PITCH_YAW,  (uint16_t)pitch << 8 | yaw);
    vs1053_write_sci(SCI_WRAM, ((uint16_t)roll << 8) | 0x80);  // scale not used for camera, but set scale to 1.0 (Q7) for consistency
    vs1053_write_sci(SCI_WRAM, pos_x);
    vs1053_write_sci(SCI_WRAM, pos_y);
    vs1053_write_sci(SCI_WRAM, pos_z);
}

// Setup camera transformation parameters
void setup_projection_params(int16_t focal, int16_t half_w, int16_t half_h,
                         int16_t near_z) {
    vs1053_write_mem(VS_GEOM_ENABLE_PROJECT, 0x0001);  // Enable projection
    vs1053_write_mem(VS_GEOM_ENABLE_CLIP, 0x0001);    // Enable clipping              
    vs1053_write_mem(VS_GEOM_PROJ_FOCAL, focal);
    vs1053_write_sci(SCI_WRAM, half_w);
    vs1053_write_sci(SCI_WRAM, half_h);
    vs1053_write_sci(SCI_WRAM, near_z);
}


void setup_model_vertices(const Model3D* model) {
    // Write the total number of vertices
    vs1053_write_mem(VS_GEOM_N_VERTICES, model->vertex_count);
    vs1053_write_sci(SCI_WRAMADDR, VS_GEOM_INPUT_VERT);
    // Vertices Start at INPUT_VERT in X-RAM
    for(uint8_t i = 0; i < model->vertex_count; ++i) {
        vs1053_write_sci(SCI_WRAM, model->vx[i]);
        vs1053_write_sci(SCI_WRAM, model->vy[i]);
        vs1053_write_sci(SCI_WRAM, model->vz[i]);
    }
}

void load_model_to_plugin(const Model3D* model, uint8_t slot) {
    setup_model_vertices(model);
    setup_model_edges(model);
    if(!geometry_kernel_save(slot)) {
        printf("Error saving model to plugin slot %d\n", slot);
    }
}

void setup_model_edges(const Model3D* model) {
    // Write the total number of edges
    vs1053_write_mem(VS_GEOM_N_EDGES, model->edge_count);
    // set base address
    vs1053_write_sci(SCI_WRAMADDR, VS_GEOM_EDGE_LIST);
    // Output edges to X-RAM packed as [v0_low | v1_high] per word
    for(uint8_t i = 0; i < model->edge_count; ++i) {
        vs1053_write_sci(SCI_WRAM, (uint16_t)model->edge_b[i] << 8 | (uint16_t)model->edge_a[i]);
    }
}

void geometry_kernel_reset(void) {
    vs1053_write_mem(VS_GEOM_STATUS, 0x0000);
}

// Call the plugin entry point
void trigger_geometry_kernel(void) {
    vs1053_write_sci(SCI_AICTRL0, VS_GEOM_TRIGGER_MAGIC);  // Set trigger to start processing 
}

// Save Object to internal slot
bool geometry_kernel_save(uint16_t slot) {
    vs1053_write_sci(SCI_AICTRL1, slot);  // Set trigger to start processing 
    if(geometry_kernel_wait_complete(100) == 1) { // wait for completion (or error)
        return true;
    }
    return false;
}

// load Object from internal slot
bool geometry_kernel_load(uint16_t slot) {
    vs1053_write_sci(SCI_AICTRL2, slot);  // Set trigger to start processing 
    if(geometry_kernel_wait_complete(100) == 1) { // wait for completion (or error)
        return true;
    }
    return false;
}

uint8_t geometry_kernel_status(void) {
   volatile uint16_t status = vs1053_read_mem(VS_GEOM_STATUS);
    
    if (status == VS_GEOM_STATUS_DONE) {
        return 2;  // Complete
    } else if (status == VS_GEOM_STATUS_BUSY) {
        return 1;  // Busy
    } else if (status == VS_GEOM_STATUS_SAVE_ERROR || status == VS_GEOM_STATUS_LOAD_ERROR) {
        return 3;  // Error
    } else {
        return 0;  // Idle
    }
}

uint8_t geometry_kernel_wait_complete(uint16_t timeout_ms) {
    uint16_t elapsed = 0;
    volatile uint16_t raw_status = 0;
    volatile uint16_t debug_iter = 0;
    while (elapsed < timeout_ms) {

        raw_status = vs1053_read_mem(VS_GEOM_STATUS);
        
        if (raw_status == VS_GEOM_STATUS_DONE) {
            return 1;  // Complete
        } else if (raw_status == VS_GEOM_STATUS_SAVE_ERROR || raw_status == VS_GEOM_STATUS_LOAD_ERROR) {
            return 2;  // Error
        }

        // Small delay to avoid hammering SCI interface
        for(volatile uint16_t delay = 0; delay < 25; delay++) {
            __asm__("nop");
        }
        elapsed++;
    }


    return 0;  // Timeout
}
uint16_t screen_x[VS_GEOM_MAX_VERTICES];  
uint16_t clip_verts_x[VS_GEOM_MAX_VERTICES]; 
uint16_t screen_y[VS_GEOM_MAX_VERTICES];  
uint16_t clip_verts_y[VS_GEOM_MAX_VERTICES]; 
void get_screen_coordinates(uint8_t* out_n_verts) {
    // Read back the number of output screen vertices
    uint16_t n_verts = vs1053_read_mem(VS_GEOM_N_VERTICES);
    if (n_verts > VS_GEOM_MAX_VERTICES) {
        n_verts = VS_GEOM_MAX_VERTICES;  // Clamp to max
    }
    *out_n_verts = (uint8_t)n_verts;
    // Read back the screen coordinates
    vs1053_write_sci(SCI_WRAMADDR, VS_GEOM_SCREEN_COORDS);
    for(uint16_t i = 0; i < n_verts; ++i) {
        screen_x[i] = vs1053_read_sci(SCI_WRAM);
        screen_y[i] = vs1053_read_sci(SCI_WRAM);
    }
}

uint8_t get_screen_edges(Model3D * model, uint8_t color) {
    // Read number of input vertices (needed to distinguish original vs clipped)

    uint8_t edges_written = 0;
    uint8_t start_line_count = g_line_count; 

    volatile uint8_t n_input = model->vertex_count; // vs1053_read_mem(VS_GEOM_N_VERTICES);
    
    // Read number of output edges
    volatile uint8_t edge_count = vs1053_read_mem(VS_GEOM_N_OUTPUT_EDGES);
    
    // guards really not necessary, but just in case of plugin bugs.
    if (edge_count > VS_GEOM_MAX_EDGES) {
        edge_count = VS_GEOM_MAX_EDGES;
    }

    // Prefetch original screen coordinates once to minimize SCI writes/reads
    if (n_input > VS_GEOM_MAX_VERTICES) {
        n_input = VS_GEOM_MAX_VERTICES;  // Clamp to max expected
    }
    vs1053_write_sci(SCI_WRAMADDR, VS_GEOM_SCREEN_COORDS);

    for (uint8_t i = 0; i < n_input; ++i) {
        screen_x[i] = vs1053_read_sci(SCI_WRAM);
        screen_y[i] = vs1053_read_sci(SCI_WRAM);
    }

    // Read all clip screen coords in one burst (if any)
    uint8_t n_clip = vs1053_read_mem(VS_GEOM_N_CLIP_VERTS);

    if (n_clip == 0 && model->edge_count == edge_count) {
        // Fast no-clip/cull path - read edges directly
        const uint8_t *pa = model->edge_a;                  // pointer to edge a indices
        const uint8_t *pb = model->edge_b;                  // pointer to edge b indices
        uint8_t e = edge_count;
        // add_line_to_list writes to a global line buffer used by the draw line assembly code.
        while (e--) {
            uint8_t v0 = *pa++;
            uint8_t v1 = *pb++;
            uint16_t sx0 = screen_x[v0];
            uint16_t sy0 = screen_y[v0];
            uint16_t sx1 = screen_x[v1];
            uint16_t sy1 = screen_y[v1];
            add_line_to_list(sx0, sy0, sx1, sy1, color);
        }

    } else {
        // clipping or culling so need to read back edges from X-RAM
        // supports up to 16 clipped vertices, are going to replace edge vertices.
        if (n_clip > 16) n_clip = 16; // safety clamp
        int16_t clip_sx[16] = {0};
        int16_t clip_sy[16] = {0};
        if (n_clip > 0) {
            vs1053_write_sci(SCI_WRAMADDR, VS_GEOM_CLIP_SCREEN);
            for (uint8_t i = 0; i < n_clip; ++i) {
                clip_sx[i] = (int16_t)vs1053_read_sci(SCI_WRAM);
                clip_sy[i] = (int16_t)vs1053_read_sci(SCI_WRAM);
            }
        }
    
        // Read all output edges into CPU buffers in one burst
        uint16_t v0_arr[VS_GEOM_MAX_EDGES];
        uint16_t v1_arr[VS_GEOM_MAX_EDGES];
        uint16_t flags_arr[VS_GEOM_MAX_EDGES];
        vs1053_write_sci(SCI_WRAMADDR, VS_GEOM_OUTPUT_EDGES);
        for (uint8_t e = 0; e < edge_count; ++e) {
            uint16_t packed = vs1053_read_sci(SCI_WRAM);
            v0_arr[e] = packed & 0xFF;
            v1_arr[e] = (packed >> 8) & 0xFF;
            flags_arr[e] = vs1053_read_sci(SCI_WRAM);
        }

        // Process edges using cached data 
        for (uint8_t e = 0; e < edge_count; ++e) {
            uint16_t flags = flags_arr[e];
            if (!(flags & VS_GEOM_EDGE_VISIBLE)) continue;
    
            uint16_t v0 = v0_arr[e];
            uint16_t v1 = v1_arr[e];
  
            int16_t sx0, sy0, sx1, sy1;
            // vertices values >= n_input are clipped vertices and index into clip arrays
            if (v0 < n_input) {
                sx0 = (int16_t)screen_x[v0];
                sy0 = (int16_t)screen_y[v0];
            } else {
                uint16_t ci = v0 - n_input;
                if (ci < n_clip) {
                    sx0 = clip_sx[ci];
                    sy0 = clip_sy[ci];
                } else {
                    sx0 = 0; sy0 = 0;
                }
            }
    
            if (v1 < n_input) {
                sx1 = (int16_t)screen_x[v1];
                sy1 = (int16_t)screen_y[v1];
            } else {
                uint16_t ci = v1 - n_input;
                if (ci < n_clip) {
                    sx1 = clip_sx[ci];
                    sy1 = clip_sy[ci];
                } else {
                    sx1 = 0; sy1 = 0;
                }
            }
    
            add_line_to_list((uint16_t)sx0, (uint16_t)sy0, (uint16_t)sx1, (uint16_t)sy1, color);
        }
    }
    
    edges_written = g_line_count - start_line_count;
    // Return actual number of visible edges written
    return edges_written;
}

