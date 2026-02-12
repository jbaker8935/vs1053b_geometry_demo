#if !defined(DRONE_SHOW_H)
#define DRONE_SHOW_H
#include <stdint.h>

#define DRONE_COUNT 27
#define FRAME_COUNT 550
typedef struct DronePose {
    int16_t x;
    int16_t y;
    int16_t z;
    uint8_t yaw;
    uint8_t pitch;
    uint8_t roll;
} DronePose;


extern DronePose frame_drones[DRONE_COUNT];
void loadNextDroneFrame();
void resetDroneAnimation();
#endif // DRONE_SHOW_H 

