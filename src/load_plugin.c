#include "f256lib.h"
#include "../include/muVS1053b.h"

EMBED(plugin_data,"assets/plugin.bin",0x10000lu);

#define PLUGIN_SIZE 3577


void loadVS1053Plugin() {
  initVS1053Plugin(PLUGIN_SIZE);
}

void initVS1053Plugin(uint16_t size) {
	uint16_t n;
    uint16_t addr, val, i=0;
  // i is the byte offset into the plugin data
  // plugin size is in words (2 bytes each)
  while (i<size*2) {
	  

    addr = FAR_PEEKW(0x10000lu + (uint32_t)i);
    n = FAR_PEEKW(0x10000lu + (uint32_t)(i+2));
    i += 4;
	
    if (n & 0x8000U) { /* RLE run, replicate n samples */
      n &= 0x7FFF;
      val = FAR_PEEKW(0x10000lu + (uint32_t)i);
	  i += 2;
      while (n--) {
        //WriteVS10xxRegister(addr, val);
        POKEW(VS_SCI_ADDR,addr);
        POKEW(VS_SCI_DATA,val);
        POKE(VS_SCI_CTRL,CTRL_Start);
        POKE(VS_SCI_CTRL,0);
        while ((PEEK(VS_SCI_CTRL) & CTRL_Busy) == CTRL_Busy)
          ;
      }
    } else {           /* Copy run, copy n samples */
      while (n--) {
        val = FAR_PEEKW(0x10000lu + (uint32_t)i);
		i += 2;
        //WriteVS10xxRegister(addr, val);
        POKEW(VS_SCI_ADDR,addr);
        POKEW(VS_SCI_DATA,val);
        POKE(VS_SCI_CTRL,CTRL_Start);
        POKE(VS_SCI_CTRL,0);
        while ((PEEK(VS_SCI_CTRL) & CTRL_Busy) == CTRL_Busy)
          ;
      }
    }
  }
}

//perform this routine to boost the chip's clock. Pretty much necessary to do before real time midi mode or mp3 playback
void boostVSClock()
{
//target the clock register
// Recommended SC_MULT=3.5×,SC_ADD=1.0×(SCI_CLOCKF=0x8800).
POKEW(VS_SCI_ADDR, VS_SCI_ADDR_CLOCKF);
POKEW(VS_SCI_DATA,0x8800);
//trigger the command
POKE(VS_SCI_CTRL,CTRL_Start);
POKE(VS_SCI_CTRL,0);
//check to see if it's done
	while (PEEK(VS_SCI_CTRL) & CTRL_Busy)
		;
}



