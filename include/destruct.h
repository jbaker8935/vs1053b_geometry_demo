#if !defined(DESTRUCT_H)
#define DESTRUCT_H
#include <stdint.h>

#define DESTRUCT_COUNT 20
#define DESTRUCT_FRAME_COUNT 150
#define FRAME_0_DELAY 30 // frames to delay on the first frame for visual pause at the start of the animation
typedef struct DestructPose {
    int16_t x;
    int16_t y;
    int16_t z;
    uint8_t yaw;
    uint8_t pitch;
    uint8_t roll;
} DestructPose;


extern DestructPose frame_destruct[DESTRUCT_COUNT];
uint16_t destruct_get_frame(void);
void loadNextDestructFrame();
void resetDestructAnimation();
#endif // DESTRUCT_H 

