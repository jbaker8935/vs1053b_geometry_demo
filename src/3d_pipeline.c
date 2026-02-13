#include "f256lib.h"
#include "../include/3d_pipeline.h"
#include "../include/geometry_kernel.h"

// transforms instance vertices/edges to screen space
// output is written to global line list buffer
void transform_instance_to_screen(const Instance3D *instance, const Camera *camera) {

    setup_object_params(
        instance->pitch, instance->yaw, instance->roll, instance->scale,
        instance->position.x, instance->position.y, instance->position.z);

    trigger_geometry_kernel();
    
    uint8_t wait_result = geometry_kernel_wait_complete(10000);
    (void)wait_result; // ignore timeout response for now
}
