#ifndef VIDEO_H
#define VIDEO_H

#include <stdint.h>

void video_init(void);
void video_wait_vblank(void);
void dmaBitmapClear(uint8_t layer);

#endif // VIDEO_H
