#include "../include/video.h"

#include "f256lib.h"

#define DMA_FILL_VAL16   0xDF02
#define DMA_16_BIT      0x40
uint32_t bitmap_base[] = {0x6c000, 0x58000, 0x44000};

__attribute__((optnone,noinline))
void dmaBitmapClear(uint8_t layer) {

	asm("sei");
	POKE(DMA_CTRL, DMA_CTRL_FILL | DMA_CTRL_ENABLE | DMA_16_BIT);
	POKEA(DMA_DST_ADDR, bitmap_base[layer]);
	POKEA(DMA_COUNT, 0x12C00); 
	POKEW(DMA_FILL_VAL16, 0x0000);

	POKE(DMA_CTRL, PEEK(DMA_CTRL) | DMA_CTRL_START);
	// Wait for DMA to complete with timeout to avoid hangs
	uint16_t timeout = 12000; // generous safety margin
	while (timeout-- > 0) {
		if ((PEEK(0xDF01) & 0x80) == 0) { // Busy bit clear
			break;
		}
	}
	POKE(0xDF00, 0x00); // Stop DMA

	asm("cli");

}

void video_init(void) {
	textClear();
    textDefineForegroundColor(1,0xaa,0xaa,0xaa); // #aaaaaa Normal Text
    textDefineBackgroundColor(1, 40,40,40); 
	textEnableBackgroundColors(true);   
	textSetColor(1, 1);

	graphicsSetLayerBitmap(0, 0);
	bitmapSetActive(0);
	bitmapSetCLUT(0);
	bitmapSetVisible(0, true);
	bitmapSetColor(0);
	bitmapClear();

	// Initialize Layer 1 for double buffering
	graphicsSetLayerBitmap(1, 1);
	bitmapSetActive(1);
	bitmapSetCLUT(0); // Use same CLUT
	bitmapSetVisible(1, false); // Start hidden
	bitmapSetColor(0);
	bitmapClear();

	graphicsDefineColor(0, 0, 0, 0, 0);
	graphicsDefineColor(0, 1, 0, 255, 239);
	graphicsDefineColor(0, 2, 255, 0, 150);
	graphicsDefineColor(0, 3, 180, 255, 0);
	graphicsDefineColor(0, 4, 255, 85, 0);
	graphicsDefineColor(0, 5, 110, 0, 255);
	graphicsDefineColor(0, 6, 255, 110, 110);
	graphicsDefineColor(0, 7, 0, 120, 255);
	graphicsDefineColor(0, 8, 255, 200, 0);
	graphicsDefineColor(0, 9, 0, 255, 150);
	graphicsDefineColor(0, 10, 220, 20, 60);
	graphicsDefineColor(0, 11, 95, 205, 228); // #5fcdE4 Light Blue
	graphicsDefineColor(0, 12, 61, 133, 148);  // #3D8594 Medium Blue
	
	POKE(0xD00D, 0x33);
    POKE(0xD00E, 0x33);
    POKE(0xD00F, 0x33);

}

void video_wait_vblank(void) {
	graphicsWaitVerticalBlank();
}
