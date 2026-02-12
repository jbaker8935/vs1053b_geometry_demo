#ifndef PIPELINE_3D_H
#define PIPELINE_3D_H

#include <stdint.h>
#include "../include/3d_object.h"

void transform_instance_to_screen(const Instance3D *instance, const Camera *camera, bool set_model);

#endif // PIPELINE_3D_H
