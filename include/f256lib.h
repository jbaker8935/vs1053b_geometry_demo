/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


/*
 *  Configuration DEFINEs
 *
 *  Before including this file, you may define one or more of the following
 *  to customize the library for your application:
 *
 *   SWAP_RESTORE
 *
 *     When using functions such as FAR_PEEK or bitmap features, return the
 *     swap slot back to it's original memory location before returning.  By
 *     default, the swap slot is left in whatever state the last function that
 *     used it switched it to.
 *
 *   WITHOUT_GRAPHICS
 *
 *     Shortcut for WITHOUT_BITMAP, WITHOUT_TILE, and WITHOUT_SPRITE.
 *
 *   WITHOUT_BITMAP
 *
 *     Disables bitmap functions.
 *
 *   WITHOUT_TILE
 *
 *     Disables tilemap functions.
 *
 *   WITHOUT_SPRITE
 *
 *     Disables sprite functions.
 *
 *   WITHOUT_FILE
 *
 *     Disables file handling support.
 *
 *   WITHOUT_KERNEL
 *
 *     Disables microkernel support.  Also disables FILE, PLATFORM, and MAIN.
 *
 *   WITHOUT_TEXT
 *
 *     Disables text functions.  Also disables PLATFORM.
 *
 *   WITHOUT_MATH
 *
 *     Disables math coprocessor support.  Also disables TEXT, PLATFORM and
 *     BITMAP.
 *
 *   WITHOUT_MAIN
 *
 *     Removes support for the standardized "int main(int argc, char *argv[])"
 *     function and replaces it with "int main(void)".  You must also manually
 *     call "f256Init()" at the start of your program.
 *
 *   WITHOUT_PLATFORM
 *
 *     Removes basic C library I/O support for "getchar()" and "__putchar()".
 *     This removes printf().
 *
 *   WITHOUT_DMA
 *
 *     Removes DMA support.  In the future, will also disable BITMAP.
 *
 */


/*
 *  Usage Example:
 *
 *    #define WITHOUT_FILE
 *    #define WITHOUT_SPRITE
 *    #define WITHOUT_TILE
 *    #define F256LIB_IMPLEMENTATION
 *    #include "f256lib.h"
 *
 *    int main(int argc, char *argv[]) {
 *       return 0;
 *    }
 *
 */


/*
 *  Library documentation at this point is basically "Use the Source, Luke!"
 *  Each section of the library has it's own header file in the non-amalgamated
 *  build.  Look through the headers in the "include/" and "f256lib/"
 *  directories.
 *
 *  Examples of using the various features of the library are in the "examples/"
 *  directory.  Source code for helpful utilities and tools that run on the
 *  host computer can be found in "tools/".
 *
 */


#define END_OF_DOCS__BEYOND_LIE_DRAGONS
#ifndef STDDCLMR_H
#define STDDCLMR_H

/*
Action figures sold separately. Add toner. All models over 18 years of age.
All rights reserved. Allow four to six weeks for delivery. An equal
opportunity employer. Any resemblance to actual persons, living or dead, is
unintentional and purely coincidental. Apply only to affected area. Approved
for veterans. As seen on TV. At participating locations only. Avoid contact
with mucous membranes. Avoid contact with skin. Avoid extreme temperatures
and store in a cool dry place. Batteries not included. Be sure each item is
properly endorsed. Beware of dog. Booths for two or more. Breaking seal
constitutes acceptance of agreement. Call toll free number before digging.
Caveat emptor. Check here if tax deductible. Close cover before striking
Colors may fade. Contains a substantial amount of non-tobacco ingredients.
Contents may settle during shipment. Contestants have been briefed on some
questions before the show. Copyright 1995 Joker's Wild. Disclaimer does
not cover hurricane, lightning, tornado, tsunami, volcanic eruption,
earthquake, flood, and other Acts of God, misuse, neglect, unauthorized
repair, damage from improper installation, broken antenna or marred cabinet,
incorrect line voltage, missing or altered serial numbers, sonic boom
vibrations, electromagnetic radiation from nuclear blasts, customer
adjustments that are not covered in the joke list, and incidents owing to
airplane crash, ship sinking, motor vehicle accidents, leaky roof, broken
glass, falling rocks, mud slides, forest fire, flying projectiles, or
dropping the item. Do not bend, fold, mutilate, or spindle. Do not place
near flammable or magnetic source. Do not puncture, incinerate, or store
above 120 degrees Fahrenheit. Do not stamp. Use other side for additional
listings. Do not use while operating a motor vehicle or heavy equipment. Do
not write below this line. Documents are provided "as is" without any
warranties expressed or implied. Don't quote me on anything. Don't quote me
on that. Driver does not carry cash. Drop in any mailbox. Edited for
television. Employees and their families are not eligible. Falling rock.
First pull up, then pull down. Flames redirected to /dev/null. For a
limited time only. For external use only. For off-road use only. For office
use only. For recreational use only. Do not disturb. Freshest if eaten
before date on carton. Hand wash only, tumble dry on low heat. If a rash,
redness, irritation, or swelling develops, discontinue use. If condition
persists, consult your physician. If defects are discovered, do not attempt
to fix them yourself, but return to an authorized service center. If
ingested, do not induce vomiting, if symptoms persist, consult a doctor.
Keep away from open flames and avoid inhaling fumes. Keep away from
sunlight, pets, and small children. Keep cool; process promptly. Limit
one-per-family please. Limited time offer, call now to ensure prompt
delivery. List at least two alternate dates. List each check separately by
bank number. List was current at time of printing. Lost ticket pays maximum
rate. May be too intense for some viewers. Must be 18 to enter. No Canadian
coins. No alcohol, dogs or horses. No anchovies unless otherwise specified.
No animals were harmed in the production of these documents. No money down.
No other warranty expressed or implied. No passes accepted for this
engagement. No postage necessary if mailed in the United States. No
preservatives added. No purchase necessary. No salt, MSG, artificial color
or flavor added. No shoes, no shirt, no service, no kidding. No solicitors.
No substitutions allowed. No transfers issued until the bus comes to a
complete stop. No user-serviceable parts inside. Not affiliated with the
American Red Cross. Not liable for damages due to use or misuse. Not
recommended for children. Not responsible for direct, indirect, incidental
or consequential damages resulting from any defect, error or failure to
perform. Not the Beatles. Objects in mirror may be closer than they appear.
One size fits all. Many suitcases look alike. Other copyright laws for
specific entries apply wherever noted. Other restrictions may apply. Package
sold by weight, not volume. Parental advisory - explicit lyrics. Penalty for
private use. Place stamp here. Please remain seated until the ride has come
to a complete stop. Possible penalties for early withdrawal. Post office will
not deliver without postage. Postage will be paid by addressee. Prerecorded
for this time zone. Price does not include taxes. Processed at location
stamped in code at top of carton. Quantities are limited while supplies last.
Read at your own risk. Record additional transactions on back of previous
stub. Replace with same type. Reproduction strictly prohibited. Restaurant
package, not for resale. Return to sender, no forwarding order on file,
unable to forward. Safety goggles may be required during use. Sanitized for
your protection. Sealed for your protection, do not use if the safety seal is
broken. See label for sequence. Shading within a garment may occur. Sign here
without admitting guilt. Simulated picture. Slightly enlarged to show detail.
Slightly higher west of the Rockies. Slippery when wet. Smoking these may be
hazardous to your health. Some assembly required. Some equipment shown is
optional. Some of the trademarks mentioned in this product appear for
identification purposes only. Subject to FCC approval. Subject to change
without notice. Substantial penalty for early withdrawal. Text may contain
material some readers may find objectionable, parental guidance is advised.
Text used in these documents is made from 100% recycled electrons and magnetic
particles.  These documents do not reflect the thoughts or opinions of either
myself, my company, my friends, or my rabbit. This is not an offer to sell
securities. This offer is void where prohibited, taxed, or otherwise
restricted. This product is meant for educational purposes only. Times
approximate. Unix is a registered trademark of AT&T. Use only as directed. Use
only in a well-ventilated are. User assumes full liabilities. Void where
prohibited. We have sent the forms which seem right for you. You must be
present to win. You need not be present to win. Your canceled check is your
receipt. Your mileage may vary. I didn't do it. You can't prove anything.

This supersedes all previous notices.
*/

#endif // STDDCLMR_H
#ifndef F256LIB_AMALGAMATED_BUILD
#define F256LIB_AMALGAMATED_BUILD
/*
 *   This file is part of the TinyCore 6502 MicroKernel, Copyright 2022 Jessie
 *   Oberreuter <joberreu@moselle.com>. As with the Linux Kernel Exception to
 *   the GPL3, programs built to run on the MicroKernel are expected to
 *   include this file. Doing so does not effect their license status.
 *
 *  Kernel Calls Populate the kernel.arg.* variables appropriately, and then
 *  JSR to one of the velctors below:
 */

#ifndef kernel_api_h
#define kernel_api_h


// Ported from https://github.com/ghackwrench/F256_MicroKernel/blob/master/kernel/api.asm


#include <stdint.h>


#pragma push_macro("EOF")
#undef EOF

struct call {  // Mount at $ff00

    long NextEvent;      // Copy the next event into user-space.
    long ReadData;       // Copy primary bulk event data into user-space
    long ReadExt;        // Copy secondary bolk event data into user-space
    long Yield;          // Give unused time to the kernel.
    long Putch;          // deprecated
    long RunBlock;       //
    long RunNamed;       //
    long reserved;

    struct {
        long List;       // Returns a bit-set of available block-accessible devices.
        long GetName;    // Gets the hardware level name of the given block device or media.
        long GetSize;    // Get the number of raw sectors (48 bits) for the given device
        long Read;       // Read a raw sector (48 bit LBA)
        long Write;      // Write a raw sector (48 bit LBA)
        long Format;     // Perform a low-level format if the media support it.
        long Export;     // Update the FileSystem table with the partition table (if present).
    } BlockDevice;

    struct {
        long List;       // Returns a bit-set of available logical devices.
        long GetSize;    // Get the size of the partition or logical device in sectors.
        long MkFS;       // Creates a new file-system on the logical device.
        long CheckFS;    // Checks the file-system for errors and corrects them.
        long Mount;      // Mark the file-system as available for File and Directory operations.
        long Unmount;    // Mark the file-system as unavailable for File and Directory operations.
        long ReadBlock;  // Read a partition-local raw sector on an unmounted device.
        long WriteBlock; // Write a partition-local raw sector on an unmounted device.
    } FileSystem;

    struct {
        long Open;       // Open the given file for read, create, or append.
        long Read;       // Request bytes from a file opened for reading.
        long Write;      // Write bytes to a file opened for create or append.
        long Close;      // Close an open file.
        long Rename;     // Rename a closed file.
        long Delete;     // Delete a closed file.
        long Seek;       // Set the next read/write position within an open file.
    } File;

    struct {
        long Open;       // Open a directory for reading.
        long Read;       // Read a directory entry; may also return VOLUME and FREE events.
        long Close;      // Close a directory once finished reading.
        long MkDir;      // Create a new directory.
        long RmDir;      // Deletes an existing directory.
    } Directory;

    long gate;

    struct {
        long GetIP;      // Get the local IP address.
        long SetIP;      // Set the local IP address.
        long GetDNS;     // Get the configured DNS IP address.
        long SetDNS;     // Set the configured DNS IP address.
        long SendICMP;   // Send an ICMP packet (typically a ping).
        long Match;      // Determine if the current event matches a specific socket.

        struct {
            long Init;   // Initialize a 32 byte UDP socket structure.
            long Send;   // Send data via the supplied UDP socket structure.
            long Recv;   // Copy the UDP payload from the event to the user's address space.
        } UDP;

        struct {
            long Open;   // Initialize a 256 byte TCP structure for a specified destination.
            long Accept; // Initialize a 256 byte TCP structure from a received SYN packet.
            long Reject; // Reply to a received TCP packet with a REJECT message.
            long Send;   // Accept some new data and send an ACK along with any unACK'd data.
            long Recv;   // Copy any new TCP bytes into the user's buf and update the socket state.
            long Close;
        } TCP;
    };

    struct {
        long Reset;      // Re-init the display.
        long GetSize;    // Returns rows/cols in kernel args.
        long DrawRow;    // Draw text/color buffers left-to-right
        long DrawColumn; // Draw text/color buffers top-to-bottom
    } Display;

    struct {
        long GetTime;    // Get the date+time in BCD: YY,YY,MM,DD,HH,MM,SS,cS
        long SetTime;    //
        long vectors816_1;
        long vectors816_2;  // 12 bytes skipped here.
        long vectors816_3;
        long SetTimer;   //
    } Clock;
};

// Kernel Call Arguments; mount at $f0

struct events_t {
    struct event_t *event;   // GetNextEvent copies event data here
    char            pending; // Negative count of pending events
};

struct common_t {
    char        dummy[8-sizeof(struct events_t)];
    const void *ext;
    uint8_t     extlen;
    const void *buf;
    uint8_t     buflen;
    void *      internal;
};

struct fs_mkfs_t {
    uint8_t  drive;
    uint8_t  cookie;
    // label = common.buf; label_len = common.buflen
};

struct fs_t {
    union {
        struct fs_mkfs_t  format;
        struct fs_mkfs_t  mkfs;
    };
};

struct fs_open_t {
    uint8_t drive;
    uint8_t cookie;
    uint8_t mode;
    // fname       = common.buf
    // fname_len   = common.buflen
};

enum fs_open_mode {
    READ,
    WRITE,
    APPEND
};

struct fs_read_t {
    uint8_t stream;
    uint8_t buflen;
};

struct fs_write_t {
    uint8_t stream;
    // buf         = common.buf
    // buflen      = common.buflen
};

struct fs_seek_t {
	uint8_t  stream;
	uint32_t offset;
};

struct fs_close_t {
	uint8_t stream;
};

struct fs_rename_t {
    uint8_t drive;
    uint8_t cookie;
    // old         = args.buf
    // old_len     = args.buflen
    // new         = args.ext
    // new_len     = args.extlen
};

struct fs_delete_t {
    uint8_t drive;
    uint8_t cookie;
    // fnane       = args.buf
    // fname_len   = args.buflen
};

struct file_t {
    union {
        struct fs_open_t    open;
        struct fs_read_t    read;
        struct fs_write_t   write;
        struct fs_seek_t    seek;
        struct fs_close_t   close;
        struct fs_rename_t  rename;
        struct fs_delete_t  delete;
    };
};

struct dir_open_t {
    uint8_t drive;
    uint8_t cookie;
    // fname       = args.buf
    // fname_len   = args.buflen
};

struct dir_read_t {
    uint8_t stream;
    uint8_t buflen;
};

struct dir_close_t {
    uint8_t stream;
};

struct dir_t {
    union {
        struct dir_open_t   open;
        struct dir_read_t   read;
        struct dir_close_t  close;
        struct dir_open_t   mkdir;
        struct dir_open_t   rmdir;
    };
};

struct display_t {
    uint8_t x; // coordinate or size
    uint8_t y; // coordinate or size
    // text        = args.buf      ; text
    // color       = args.ext      ; color
    // buflen      = args.buflen
};

struct net_init_t {
	uint16_t source_port;
	uint16_t dest_port;
	long     dest_ip;
};

struct net_send_recv_t {
	uint8_t accepted;
	// buf         = args.ext
	// buflen      = args.extlen
};

struct net_t {
	// socket      = args.buf
	union {
		struct net_init_t       net_init;
		struct net_send_recv_t  net_send_recv;
	};
};

struct timer_t {
	uint8_t units;
	uint8_t absolute;
	uint8_t cookie;
};

struct time_t {
	uint8_t century;
	uint8_t year;
	uint8_t month;
	uint8_t day;
	uint8_t hours;
	uint8_t minutes;
	uint8_t seconds;
	uint8_t centis;
};


struct call_args {
    struct events_t events;  // The GetNextEvent dest address is globally reserved.
    union {
        struct common_t   common;
        struct fs_t       fs;
        struct file_t     file;
        struct dir_t      directory;
        struct display_t  display;
        struct net_t      net;
        struct timer_t    timer;
    };
};




// Events
// The vast majority of kernel operations communicate with userland
// by sending events; the data contained in the various events are
// described following the event list.

struct events {
    uint16_t reserved;
    uint16_t deprecated;
    uint16_t GAME;        // joystick events
    uint16_t DEVICE;      // deprecated

    struct {
        uint16_t PRESSED;
        uint16_t RELEASED;
    } key;

    struct {
        uint16_t DELTA;
        uint16_t CLICKS;
    } mouse;

    struct {
        uint16_t NAME;
        uint16_t SIZE;
        uint16_t DATA;
        uint16_t WROTE;
        uint16_t FORMATTED;
        uint16_t ERROR;
    } block;

    struct {
        uint16_t SIZE;
        uint16_t CREATED;
        uint16_t CHECKED;
        uint16_t DATA;
        uint16_t WROTE;
        uint16_t ERROR;
    } fs;

    struct {
        uint16_t NOT_FOUND;
        uint16_t OPENED;
        uint16_t DATA;
        uint16_t WROTE;
        uint16_t EOF;
        uint16_t CLOSED;
        uint16_t RENAMED;
        uint16_t DELETED;
        uint16_t ERROR;
        uint16_t SEEK;
    } file;

    struct {
        uint16_t OPENED;
        uint16_t VOLUME;
        uint16_t FILE;
        uint16_t FREE;
        uint16_t EOF;
        uint16_t CLOSED;
        uint16_t ERROR;
        uint16_t CREATED;
        uint16_t DELETED;
    } directory;

    struct {
        uint16_t TCP;
        uint16_t UDP;
    } net;

	struct {
		uint16_t EXPIRED;
	} timer;

	struct {
		uint16_t TICK;
	} clock;
};


struct event_key_t {
    uint8_t keyboard;
    uint8_t raw;
    char    ascii;
    char    flags;  // negative for no associated ASCII.
};

struct event_mouse_delta_t {
    char     x;
    char     y;
    char     z;
    uint8_t  buttons;
};

struct event_mouse_clicks_t {
    uint8_t inner;
    uint8_t middle;
    uint8_t outer;
};

struct event_mouse_t {
    union {
        struct event_mouse_delta_t  delta;
        struct event_mouse_clicks_t clicks;
    };
};

struct event_game_t {
	uint8_t game0;
	uint8_t game1;
};

struct event_fs_data_t {
    uint8_t requested;    // Requested number of bytes to read
    uint8_t delivered;    // Number of bytes actually read
};

struct event_fs_wrote_t {
    uint8_t requested;    // Requested number of bytes to write
    uint8_t delivered;    // Number of bytes actually written
};

struct event_file_t {
    uint8_t stream;
    uint8_t cookie;
    union {
        struct event_fs_data_t  data;
        struct event_fs_wrote_t wrote;
    };
};

struct event_dir_vol_t { // ext contains disk id
    uint8_t len;    // Length of volname (in buf)
    uint8_t flags;  // block size, text encoding
};

struct event_dir_file_t { // ext contains byte count and modified date
    uint8_t len;    // Length of name (in buf)
    uint8_t flags;  // block size, text encoding
};

struct event_dir_free_t {  // ext contains the block count &c
    uint8_t flags;  // block size, text encoding
};

struct dir_ext_t {  // Extended information; more to follow.
    uint32_t free;  // Actually, 48 bits, but you'll prolly never hit it.
};

struct event_dir_t {
    uint8_t stream;
    uint8_t cookie;
    union {
        struct event_dir_vol_t  volume;
        struct event_dir_file_t file;
        struct event_dir_free_t free;
    };
};

struct event_udp_t {
    uint8_t token;
};

struct event_tcp_t {
    uint8_t len;
};

struct event_timer_t {
	uint8_t value;
	uint8_t cookie;
};

struct event_t {
    uint8_t type;
    uint8_t buf;    // kernel's buf page ID
    uint8_t ext;    // kernel's ext page ID
    union {
        struct event_key_t    key;
        struct event_mouse_t  mouse;
        struct event_game_t   game;
        struct event_udp_t    udp;
        struct event_tcp_t    tcp;
        struct event_file_t   file;
        struct event_dir_t    directory;
        struct event_timer_t  timer;
    };
};


#pragma pop_macro("EOF")

#endif
#ifndef _F256_DMA_H_
#define _F256_DMA_H_

//
// Registers for DMA
//

#define DMA_CTRL   0xDF00                // DMA Control Register
#define DMA_CTRL_START   0x80            // Start the DMA operation
#define DMA_CTRL_INT_EN   0x08           // Enable DMA interrupts
#define DMA_CTRL_FILL   0x04             // DMA is a fill operation (otherwise DMA is a copy)
#define DMA_CTRL_2D   0x02               // DMA is 2D operation (otherwise it is 1D)
#define DMA_CTRL_ENABLE   0x01           // DMA engine is enabled

#define DMA_STATUS   0xDF01              // DMA status register (Read Only)
#define DMA_STAT_BUSY   0x80             // DMA engine is busy with an operation

#define DMA_FILL_VAL   0xDF01            // Byte value to use for fill operations

#define DMA_SRC_ADDR   0xDF04            // Source address (system bus) for copy operations
#define DMA_DST_ADDR   0xDF08            // Destination address (system bus) for fill and copy operations

#define DMA_COUNT   0xDF0C               // Number of bytes to fill or copy (1D operations, 24 bit value)
#define DMA_WIDTH   0xDF0C               // Width of rectangle to fill or copy (2D operations, 16 bit value)
#define DMA_HEIGHT   0xDF0E              // Height of rectangle to fill or copy (2D operations, 16 bit value)
#define DMA_STRIDE_SRC   0xDF10          // Width of the source bitmap image in bytes (2D operations, 16 bit value)
#define DMA_STRIDE_DST   0xDF12          // Width of the destination bitmap image in bytes (2D operations, 16 bit value)

#endif // _F256_DMA_H_
#ifndef _F256_INTMATH_H_
#define _F256_INTMATH_H_

//
// Integer Math Coprocessor
//

#define MULU_A_L   0xDE00 //R/W  Unsigned A Low Byte
#define MULU_A_H   0xDE01 //R/W  Unsigned A High Byte
#define MULU_B_L   0xDE02 //R/W  Unsigned B Low Byte
#define MULU_B_H   0xDE03 //R/W  Unsigned B High Byte
#define MULU_LL   0xDE10 //R  ? x ? (unsigned) byte 0
#define MULU_LH   0xDE11 //R  ? x ? (unsigned) byte 1
#define MULU_HL   0xDE12 //R  ? x ? (unsigned) byte 2
#define MULU_HH   0xDE13 //R  ? x ? (unsigned) byte 3
#define DIVU_DEN_L   0xDE04 //R/W  Unsigned Denominator Low Byte
#define DIVU_DEN_H   0xDE05 //R/W  Unsigned Denominator High Byte
#define DIVU_NUM_L   0xDE06 //R/W  Unsigned Numerator Low Byte
#define DIVU_NUM_H   0xDE07 //R/W  Unsigned Numerator High Byte
#define QUOU_LL   0xDE14 //R  Quotient of NUM/DEN (unsigned) low byte
#define QUOU_LH   0xDE15 //R  Quotient of NUM/DEN (unsigned) high byte
#define REMU_HL   0xDE16 //R  Remainder of NUM/DEN (unsigned) low byte
#define REMU_HH   0xDE17 //R  Remainder of NUM/DEN (unsigned) low byte
#define ADD_A_LL   0xDE08 //R/W  Unsigned A byte 0
#define ADD_A_LH   0xDE09 //R/W  Unsigned A byte 1
#define ADD_A_HL   0xDE0A //R/W  Unsigned A byte 2
#define ADD_A_HH   0xDE0B //R/W  Unsigned A byte 3
#define ADD_B_LL   0xDE0C //R/W  Unsigned B byte 0
#define ADD_B_LH   0xDE0D //R/W  Unsigned B byte 1
#define ADD_B_HL   0xDE0E //R/W  Unsigned B byte 2
#define ADD_B_HH   0xDE0F //R/W  Unsigned B byte 3
#define ADD_R_LL   0xDE18 //R  ? + ? (unsigned) byte 0
#define ADD_R_LH   0xDE19 //R  ? + ? (unsigned) byte 1
#define ADD_R_HL   0xDE1A //R  ? + ? (unsigned) byte 2
#define ADD_R_HH   0xDE1B //R  ? + ? (unsigned) byte 3

#endif // _F256_INTMATH_H_
#ifndef _F256_IRQ_H_
#define _F256_IRQ_H_

//
// Interrupt Controller Registers
//
#define INT_PEND_0   0xD660  // Pending register for interrupts 0 - 7
#define INT_PEND_1   0xD661  // Pending register for interrupts 8 - 15
#define INT_MASK_0   0xD66C  // Mask register for interrupts 0 - 7
#define INT_MASK_1   0xD66D  // Mask register for interrupts 8 - 15

//
// Interrupt bits
//
#define INT00_VKY_SOF   0x01
#define INT01_VKY_SOL   0x02
#define INT02_PS2_KBD   0x04
#define INT03_PS2_MOUSE   0x08
#define INT04_TIMER_0   0x10
#define INT05_TIMER_1   0x20
#define INT06_DMA   0x40
#define INT07_RESERVED   0x80

#define INT10_UART   0x01
#define INT11_VKY_2   0x02
#define INT12_VKY_3   0x04
#define INT13_VKY_4   0x08
#define INT14_RTC   0x10
#define INT15_VIA   0x20
#define INT16_IEC   0x40
#define INT17_SDC_INSERT   0x80

#endif // _F256_IRQ_H_
#ifndef _F256JR_H_
#define _F256JR_H_

//
// I/O register address definitions
//

//;
//; MMU Registers
//;

#define MMU_MEM_CTRL   0x0000            // MMU Memory Control Register
#define MMU_IO_CTRL   0x0001             // MMU I/O Control Register
#define MMU_IO_PAGE_0   0x00
#define MMU_IO_PAGE_1   0x01
#define MMU_IO_TEXT   0x02
#define MMU_IO_COLOR   0x03
#define MMU_MEM_BANK_0   0x0008          // MMU Edit Register for bank 0 ($0000 - $1FFF)
#define MMU_MEM_BANK_1   0x0009          // MMU Edit Register for bank 1 ($2000 - $3FFF)
#define MMU_MEM_BANK_2   0x000A          // MMU Edit Register for bank 2 ($4000 - $5FFF)
#define MMU_MEM_BANK_3   0x000B          // MMU Edit Register for bank 3 ($6000 - $7FFF)
#define MMU_MEM_BANK_4   0x000C          // MMU Edit Register for bank 4 ($8000 - $9FFF)
#define MMU_MEM_BANK_5   0x000D          // MMU Edit Register for bank 5 ($A000 - $BFFF)
#define MMU_MEM_BANK_6   0x000E          // MMU Edit Register for bank 6 ($C000 - $DFFF)
#define MMU_MEM_BANK_7   0x000F          // MMU Edit Register for bank 7 ($E000 - $FFFF)

//;
//; Vicky Registers
//;

#define VKY_MSTR_CTRL_0   0xD000         // Vicky Master Control Register 0
#define VKY_MSTR_CTRL_1   0xD001         // Vicky Master Control Register 1

#define VKY_LAYER_CTRL_0   0xD002        // Vicky Layer Control Register 0
#define VKY_LAYER_CTRL_1   0xD003        // Vicky Layer Control Register 1

#define VKY_BRDR_CTRL   0xD004           // Vicky Border Control Register
#define VKY_BRDR_COL_B   0xD005          // Vicky Border Color -- Blue
#define VKY_BRDR_COL_G   0xD006          // Vicky Border Color -- Green
#define VKY_BRDR_COL_R   0xD007          // Vicky Border Color -- Red
#define VKY_BRDR_VERT   0xD008           // Vicky Border vertical thickness in pixels
#define VKY_BRDR_HORI   0xD009           // Vicky Border Horizontal Thickness in pixels

#define VKY_BKG_COL_B   0xD00D           // Vicky Graphics Background Color Blue Component
#define VKY_BKG_COL_G   0xD00E           // Vicky Graphics Background Color Green Component
#define VKY_BKG_COL_R   0xD00F           // Vicky Graphics Background Color Red Component

#define VKY_CRSR_CTRL   0xD010           // Vicky Text Cursor Control
#define VKY_CRSR_CHAR   0xD012
#define VKY_CRSR_X_L   0xD014            // Cursor X position
#define VKY_CRSR_X_H   0xD015
#define VKY_CRSR_Y_L   0xD016            // Cursor Y position
#define VKY_CRSR_Y_H   0xD017

#define VKY_LINE_CTRL   0xD018           // Control register for the line interrupt
#define VKY_LINE_ENABLE   0x01
#define VKY_LINE_NBR_L   0xD019          // Line number target low byte
#define VKY_LINE_NBR_H   0xD01A          // Line number target high byte


//;
//; Bitmap Registers
//;

#define VKY_BM0_CTRL   0xD100            // Bitmap #0 Control Register
#define VKY_BM0_ADDR_L   0xD101          // Bitmap #0 Address bits 7..0
#define VKY_BM0_ADDR_M   0xD102          // Bitmap #0 Address bits 15..8
#define VKY_BM0_ADDR_H   0xD103          // Bitmap #0 Address bits 17..16

#define VKY_BM1_CTRL   0xD108            // Bitmap #1 Control Register
#define VKY_BM1_ADDR_L   0xD109          // Bitmap #1 Address bits 7..0
#define VKY_BM1_ADDR_M   0xD10A          // Bitmap #1 Address bits 15..8
#define VKY_BM1_ADDR_H   0xD10B          // Bitmap #1 Address bits 17..16

#define VKY_BM2_CTRL   0xD110            // Bitmap #2 Control Register
#define VKY_BM2_ADDR_L   0xD111          // Bitmap #2 Address bits 7..0
#define VKY_BM2_ADDR_M   0xD112          // Bitmap #2 Address bits 15..8
#define VKY_BM2_ADDR_H   0xD113          // Bitmap #2 Address bits 17..16

#define VKY_TXT_FGLUT   0xD800           // Text foreground CLUT
#define VKY_TXT_BGLUT   0xD840           // Text background CLUT

//;
//; Color Lookup Tables (I/O Page 1)
//;

#define VKY_GR_CLUT_0   0xD000           // Graphics LUT #0
#define VKY_GR_CLUT_1   0xD400           // Graphics LUT #1
#define VKY_GR_CLUT_2   0xD800           // Graphics LUT #2
#define VKY_GR_CLUT_3   0xDC00           // Graphics LUT #3

//;
//; Buzzer and Status LEDs
//;

#define VKY_SYS0   0xD6A0
#define VKY_SYS1   0xD6A1

#define SYS_SID_ST   0x08
#define SYS_PSG_ST   0x04

//;
//; Software Reset
//;
#define VKY_RST0   0xD6A2 	//R/W  Set to 0xDE to enable software reset
#define VKY_RST1   0xD6A3 	//R/W  Set to 0xAD to enable software reset

//;
//; Random Numbers
//;
#define VKY_SEEDL 	   0xD6A4    // SEED[7. . . 0]
#define VKY_RNDL 	   0xD6A4    // RND[7. . . 0]
#define VKY_SEEDH 	   0xD6A5    // SEED[15. . . 0]
#define VKY_RNDH 	   0xD6A5    // RND[15. . . 0]
#define VKY_RND_CTRL   0xD6A6 	// SEED_LD=$2 ENABLE=$1
#define VKY_RND_STAT   0xD6A6 	// DONE=$80

//;
//; Machine ID and Version
//;
#define VKY_MID   0xD6A7			// Machine ID
#define VKY_PCBID0   0xD6A8		// "B"
#define VKY_PCBID1   0xD6A9      // "0"
#define VKY_CHSV0   0xD6AA       // TinyVicky subversion BCD (low)
#define VKY_CHSV1   0xD6AB  		// TinyVicky subversion in BCD (high)
#define VKY_CHV0   0xD6AC  		// TinyVicky version in BCD (low)
#define VKY_CHV1   0xD6AD  		// TinyVicky version in BCD (high)
#define VKY_CHN0   0xD6AE  		// TinyVicky number in BCD (low)
#define VKY_CHN1   0xD6AF  		// TinyVicky number in BCD (high)
#define VKY_PCBMA   0xD6EB  		// PCB Major Rev (ASCII)
#define VKY_PCBMI   0xD6EC  		// PCB Minor Rev (ASCII)
#define VKY_PCBD   0xD6ED  		// PCB Day (BCD)
#define VKY_PCBM   0xD6EE  		// PCB Month (BCD)
#define VKY_PCBY   0xD6EF  		// PCB Year (BCD)

#define MID_C256_FMX    = %00000
#define MID_C256_U      = %00001
#define MID_F256        = %00010
#define MID_F256_K      = %10010
#define MID_A2560_DEV   = %00011
#define MID_GEN_X       = %00100
#define MID_C256_U_PLUS = %00101
#define MID_A2560_X = %01000 
#define MID_A2560_U = %01001 
#define MID_A2560_M = %01010 
#define MID_A2560_K = %01011 

//;
//; Sound Generators
//;
#define VKY_PSG0   0xD600
#define VKY_PSG1   0xD610

#define VKY_PSG_BOTH   0xD608

//;
//; CODEC
//;
#define CODEC_LO           0xD620
#define CODEC_HI           0xD621
#define CODEC_CTRL         0xD622



#endif // _F256JR_H_
#ifndef _F256_RTC_H_
#define _F256_RTC_H_

//
// F256jr definitions for the real time clock (bq4802)
//

#define RTC_SECS   0xD690
#define RTC_SECS_ALRM   0xD691
#define RTC_MINS   0xD692
#define RTC_MINS_ALRM   0xD693
#define RTC_HOURS   0xD694
#define RTC_HOURS_ALRM   0xD695
#define RTC_DAY   0xD696
#define RTC_DAY_ALRM   0xD697
#define RTC_DAY_OF_WEEK   0xD698
#define RTC_MONTH   0xD699
#define RTC_YEAR   0xD69A

#define RTC_RATES   0xD69B
#define RTC_PI_0   0x00                  // Periodic Interrupt rates...
#define RTC_PI_30us   0x01
#define RTC_PI_61us   0x02
#define RTC_PI_122us   0x03
#define RTC_PI_244us   0x04
#define RTC_PI_488us   0x05
#define RTC_PI_976us   0x06
#define RTC_PI_1ms   0x07
#define RTC_PI_3ms   0x08
#define RTC_PI_7ms   0x09
#define RTC_PI_15ms   0x0A
#define RTC_PI_31ms   0x0B
#define RTC_PI_62ms   0x0C
#define RTC_PI_125ms   0x0D
#define RTC_PI_250ms   0x0E
#define RTC_PI_500ms   0x0F

#define RTC_ENABLES   0xD69C
#define RTC_ABE   0x01
#define RTC_PWRIE   0x02
#define RTC_PIE   0x04
#define RTC_AIE   0x08

#define RTC_FLAGS   0xD69D
#define RTC_BVF   0x01
#define RTC_PWRF   0x02
#define RTC_PF   0x04
#define RTC_AF   0x08

#define RTC_CTRL   0xD96E
#define RTC_DSE   0x01
#define RTC_24HR   0x02
#define RTC_STOP   0x04
#define RTC_UTI   0x08

#define RTC_CENTURY   0xD69F

#endif // _F256_RTC_H_
#ifndef _F256_SPRITES_H_
#define _F256_SPRITES_H_

//
// Sprite registers
//

#define VKY_SP0_CTRL   0xD900
#define VKY_SP0_AD_L   0xD901
#define VKY_SP0_AD_M   0xD902
#define VKY_SP0_AD_H   0xD903
#define VKY_SP0_POS_X_L   0xD904
#define VKY_SP0_POS_X_H   0xD905
#define VKY_SP0_POS_Y_L   0xD906
#define VKY_SP0_POS_Y_H   0xD907

#define VKY_SP1_CTRL   0xD908
#define VKY_SP1_AD_L   0xD909
#define VKY_SP1_AD_M   0xD90A
#define VKY_SP1_AD_H   0xD90B
#define VKY_SP1_POS_X_L   0xD90C
#define VKY_SP1_POS_X_H   0xD90D
#define VKY_SP1_POS_Y_L   0xD90E
#define VKY_SP1_POS_Y_H   0xD90F

#define VKY_SP2_CTRL   0xD910
#define VKY_SP2_AD_L   0xD911
#define VKY_SP2_AD_M   0xD912
#define VKY_SP2_AD_H   0xD913
#define VKY_SP2_POS_X_L   0xD914
#define VKY_SP2_POS_X_H   0xD915
#define VKY_SP2_POS_Y_L   0xD916
#define VKY_SP2_POS_Y_H   0xD917

#define VKY_SP3_CTRL   0xD918
#define VKY_SP3_AD_L   0xD919
#define VKY_SP3_AD_M   0xD91A
#define VKY_SP3_AD_H   0xD91B
#define VKY_SP3_POS_X_L   0xD91C
#define VKY_SP3_POS_X_H   0xD91D
#define VKY_SP3_POS_Y_L   0xD91E
#define VKY_SP3_POS_Y_H   0xD91F


#endif // _F256_SPRITES_H_
#ifndef _F256_TILES_H_
#define _F256_TILES_H_

//
// Registers for the TinyVicky tile maps
//

//
// Tile Map #0 Registers
//

#define VKY_TM0_CTRL   0xD200
#define VKY_TM0_ADDR_L   0xD201
#define VKY_TM0_ADDR_M   0xD202
#define VKY_TM0_ADDR_H   0xD203
#define VKY_TM0_SIZE_X   0xD204
#define VKY_TM0_SIZE_Y   0xD206
#define VKY_TM0_POS_X_L   0xD208
#define VKY_TM0_POS_X_H   0xD209
#define VKY_TM0_POS_Y_L   0xD20A
#define VKY_TM0_POS_Y_H   0xD20B

//
// Tile Map #1 Registers
//

#define VKY_TM1_CTRL   0xD20C
#define VKY_TM1_ADDR_L   0xD20D
#define VKY_TM1_ADDR_M   0xD20E
#define VKY_TM1_ADDR_H   0xD20F
#define VKY_TM1_SIZE_X   0xD210
#define VKY_TM1_SIZE_Y   0xD212
#define VKY_TM1_POS_X_L   0xD214
#define VKY_TM1_POS_X_H   0xD215
#define VKY_TM1_POS_Y_L   0xD216
#define VKY_TM1_POS_Y_H   0xD217

//
// Tile Map #2 Registers
//

#define VKY_TM2_CTRL   0xD218
#define VKY_TM2_ADDR_L   0xD219
#define VKY_TM2_ADDR_M   0xD21A
#define VKY_TM2_ADDR_H   0xD21B
#define VKY_TM2_SIZE_X   0xD21C
#define VKY_TM2_SIZE_Y   0xD21E
#define VKY_TM2_POS_X_L   0xD220
#define VKY_TM2_POS_X_H   0xD221
#define VKY_TM2_POS_Y_L   0xD222
#define VKY_TM2_POS_Y_H   0xD223

//
// Tile Set Address Registers
//

#define VKY_TS0_ADDR_L   0xD280
#define VKY_TS0_ADDR_M   0xD281
#define VKY_TS0_ADDR_H   0xD282

#define VKY_TS1_ADDR_L   0xD284
#define VKY_TS1_ADDR_M   0xD285
#define VKY_TS1_ADDR_H   0xD286

#define VKY_TS2_ADDR_L   0xD288
#define VKY_TS2_ADDR_M   0xD289
#define VKY_TS2_ADDR_H   0xD28A

#define VKY_TS3_ADDR_L   0xD28C
#define VKY_TS3_ADDR_M   0xD28D
#define VKY_TS3_ADDR_H   0xD28E

#define VKY_TS4_ADDR_L   0xD290
#define VKY_TS4_ADDR_M   0xD291
#define VKY_TS4_ADDR_H   0xD292

#define VKY_TS5_ADDR_L   0xD294
#define VKY_TS5_ADDR_M   0xD295
#define VKY_TS5_ADDR_H   0xD296

#define VKY_TS6_ADDR_L   0xD298
#define VKY_TS6_ADDR_M   0xD299
#define VKY_TS6_ADDR_H   0xD29A

#define VKY_TS7_ADDR_L   0xD29C
#define VKY_TS7_ADDR_M   0xD29D
#define VKY_TS7_ADDR_H   0xD29E

#endif // _F256_TILES_H_
#ifndef _F256_TIMERS_H_
#define _F256_TIMERS_H_

//
// Definitions for the interval timers and the RTC
//

// Timer 0 -- Based on system clock

#define TM0_CTRL   0xD650
#define TM_CTRL_ENABLE   0x01
#define TM_CTRL_CLEAR   0x02
#define TM_CTRL_LOAD   0x04
#define TM_CTRL_UP_DOWN   0x08
#define TM_CTRL_RECLEAR   0x10
#define TM_CTRL_RELOAD   0x20
#define TM_CTRL_INTEN   0x80

#define TM0_STAT   0xD650
#define TM_STAT_EQUAL   0x01

#define TM0_VALUE_L   0xD651
#define TM0_VALUE_M   0xD652
#define TM0_VALUE_H   0xD653

#define TM0_CMP_CTRL   0xD654
#define TM_CMP_CTRL_CLR   0x01
#define TM_CMP_CTRL_LOAD   0x02

#define TM0_CMP_L   0xD655
#define TM0_CMP_M   0xD656
#define TM0_CMP_H   0xD657

// Timer 1 -- Based on SOF

#define TM1_CTRL   0xD658
#define TM1_STAT   0xD658
#define TM1_VALUE_L   0xD659
#define TM1_VALUE_M   0xD65A
#define TM1_VALUE_H   0xD65B
#define TM1_CMP_CTRL   0xD65C
#define TM1_CMP_L   0xD65D
#define TM1_CMP_M   0xD65E
#define TM1_CMP_H   0xD65F

#endif // _F256_TIMERS_H_
#ifndef _F256_VIA_H_
#define _F256_VIA_H_

//
// The Jr's VIA
//

#define VIA_IORB   0xDC00
#define VIA_IORA   0xDC01
#define VIA_DDRB   0xDC02
#define VIA_DDRA   0xDC03

#endif // _F256_VIA_H_
#ifndef _F256_XYMATH_H_
#define _F256_XYMATH_H_

//
// Registers for the bitmap coordinate math block
//

#define XY_BASE   0xD301         // Starting address of the bitmap
#define XY_POS_X   0xD304        // X-coordinate desired
#define XY_POS_Y   0xD306        // Y-coordinate desired
#define XY_OFFSET   0xD308       // Offset within an MMU bank of the pixel for (X, Y)
#define XY_BANK   0xD30A         // MMU bank containing the pixel for (X, Y)
#define XY_ADDRESS   0xD30B      // System address of the pixel for (X, Y)

#endif // _F256_XYMATH_H_
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef F256_H
#define F256_H


#ifdef __cplusplus
extern "C"
{
#endif


#include <stdlib.h>
#include <stdio.h>


#ifndef F256LIB_AMALGAMATED_BUILD
#include "docs.h"
#include "stddclmr.h"
#include "f_api.h"
#include "f256_dma.h"
#include "f256_intmath.h"
#include "f256_irq.h"
#include "f256jr.h"
#include "f256_rtc.h"
#include "f256_sprites.h"
#include "f256_tiles.h"
#include "f256_timers.h"
#include "f256_via.h"
#include "f256_xymath.h"
#endif


typedef unsigned char byte;
typedef unsigned char bool;


#define true   1
#define false  0


// Near memory slot to use for far memory swapping.
#ifndef SWAP_SLOT
#define SWAP_SLOT  MMU_MEM_BANK_7
#endif

#if SWAP_SLOT == MMU_MEM_BANK_7

#define SWAP_IO_SETUP()	\
	byte sios_ram = PEEK(MMU_MEM_BANK_7); \
	asm("sei");

#define SWAP_IO_SHUTDOWN() \
	POKE(MMU_MEM_BANK_7, sios_ram); \
	asm("cli");

#else

#define SWAP_IO_SETUP()
#define SWAP_IO_SHUTDOWN()

#endif

#ifdef SWAP_RESTORE
#define SWAP_RESTORE_SLOT()   POKE(SWAP_SLOT, SWAP_SLOT - MMU_MEM_BANK_0)
#else
#define SWAP_RESTORE_SLOT()
#endif

#define SWAP_ADDR  ((uint16_t)(SWAP_SLOT - MMU_MEM_BANK_0) * (uint16_t)0x2000)


// Things not in the Merlin defs.
#define EIGHTK       0x2000

#define TEXT_MATRIX  0xc000  // I/O Page 2

#define RAST_ROW_L   0xd01a
#define RAST_ROW_H   0xd01b

#define VKY_TS0_SQUARE  (VKY_TS0_ADDR_H+1)
#define VKY_TS1_SQUARE  (VKY_TS1_ADDR_H+1)
#define VKY_TS2_SQUARE  (VKY_TS2_ADDR_H+1)
#define VKY_TS3_SQUARE  (VKY_TS3_ADDR_H+1)
#define VKY_TS4_SQUARE  (VKY_TS4_ADDR_H+1)
#define VKY_TS5_SQUARE  (VKY_TS5_ADDR_H+1)
#define VKY_TS6_SQUARE  (VKY_TS6_ADDR_H+1)
#define VKY_TS7_SQUARE  (VKY_TS7_ADDR_H+1)

#define VIRQ  0xfffe

#define JOY_UP         1
#define JOY_DOWN       2
#define JOY_LEFT       4
#define JOY_RIGHT      8
#define JOY_BUTTON_1  16
#define JOY_BUTTON_2  32
#define JOY_BUTTON_3  64


typedef struct colorS {
	byte r;
	byte g;
	byte b;
} colorT;


// Allow embedding binary data into program
#define IBSTR2(x) #x
#define IBSTR(x)  IBSTR2(x)
#define EMBED(name, file, address) \
    __asm__(".section ." IBSTR(name) ",\"aR\" \n" \
            ".global " IBSTR(name) "_start\n" \
            ".balign 16\n" \
            IBSTR(name) "_start:\n" \
            ".incbin \"" file "\"\n" \
            \
            ".global " IBSTR(name) "_end\n" \
            ".balign 1\n" \
            IBSTR(name) "_end:\n" \
    ); \
    extern __attribute__((aligned(16))) const char name ## _start[]; \
    extern                              const char name ## _end[]


// Single-byte
#define PEEK(addy)         ((byte)*(volatile byte *)(addy))
#define POKE(addy, value)  (*(volatile byte *)(addy) = (value))

// Word (two bytes)
#define PEEKW(addy)        ((uint16_t)*(volatile uint16_t *)(addy))
#define POKEW(addy, value) (*(volatile uint16_t *)(addy) = (value))

// Address (three bytes)
//#define PEEKA
#define POKEA(addy, value) POKE(addy, value & 0xFF); POKE(addy + 1, (value >> 8) & 0xFF); POKE(addy + 2, (value >> 16) & 0xFF)

// Double-word (four bytes)
#define PEEKD(addy)        ((uint32_t)*(volatile uint32_t *)(addy))
#define POKED(addy,value)  (*(volatile uint32_t *)(addy) = (value))

// Bit fun.
#define LOW_BYTE(x)         ((byte)(x))
#define HIGH_BYTE(x)        ((byte)(((uint16_t)(x)) >> 8))
#define SWAP_NIBBLES(x)     ((x & 0x0F) << 4 | (x & 0xF0) >> 4)
#define SWAP_UINT16(x)      (((x) >> 8) | ((x) << 8))
#define CHECK_BIT(x, pos)   (x & (1UL << pos))
#define TOGGLE_BIT(x, pos)  (x ^= (1U << pos))
#define CLEAR_BIT(x, pos)   (x &= (~(1U << pos)))
#define SET_BIT(x, pos)     (x |= (1U << pos))


// Verify configuration DEFINEs.
#if (defined WITHOUT_BITMAP && defined WITHOUT_TILE && defined WITHOUT_SPRITE)
#define WITHOUT_GRAPHICS
#endif

#ifdef WITHOUT_GRAPHICS
#define WITHOUT_BITMAP
#define WITHOUT_TILE
#define WITHOUT_SPRITE
#endif

#ifdef WITHOUT_KERNEL
#define WITHOUT_FILE
#define WITHOUT_MAIN
#define WITHOUT_PLATFORM
#endif

#ifdef WITHOUT_TEXT
#define WITHOUT_PLATFORM
#endif

#ifdef WITHOUT_MATH
#define WITHOUT_TEXT
#define WITHOUT_PLATFORM
#endif


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f_kernel.h"
#include "f_dma.h"
#include "f_math.h"
#include "f_random.h"
#include "f_text.h"
#include "f_bitmap.h"
#include "f_tile.h"
#include "f_graphics.h"
#include "f_sprite.h"
#include "f_file.h"
#include "f_platform.h"
#endif


void      f256Init(void);
void      f256Reset(void);
byte      FAR_PEEK(uint32_t address);
uint16_t  FAR_PEEKW(uint32_t address);
void     *FAR_POINTER(uint32_t address);
void      FAR_POKE(uint32_t address, byte value);
void      FAR_POKEW(uint32_t address, uint16_t value);


#ifndef WITHOUT_MAIN
#define main f256main   // This one is needed if you build f256.c as it's own compilation unit.
#endif


#ifdef __cplusplus
}
#endif


#ifndef F256LIB_AMALGAMATED_BUILD
#ifdef F256LIB_IMPLEMENTATION
#include "f256.c"
#endif
#endif


#endif // F256_H
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef KERNEL_H
#define KERNEL_H
#ifndef WITHOUT_KERNEL


#ifdef __cplusplus
extern "C"
{
#endif


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f256.h"
#endif


#define kernelNextEvent()     ({ kernelEventData.type = 0;  kernelCall(NextEvent); })
#define kernelEvent(member)   (size_t)(&((struct events *)0)->member)
#define kernelVector(member)  (size_t)(&((struct call *)0xff00)->member)
#define kernelCall(fn) \
                ({ char ret; \
                    __attribute__((leaf)) asm( \
                        "jsr %[addy]   \n" \
                        "sta (%[ret])  \n" \
                        "lda #0        \n" \
                        "ror a         \n" \
                        "sta %[err]    \n" \
                        : [err] "=m"(kernelError), [ret] "=m"(ret) \
                        : [addy] "i"(kernelVector(fn)) \
                        : "a", "c", "v"); \
                    ret; \
                })


typedef struct event_t   kernelEventT;
typedef struct call_args kernelArgsT;


extern char         kernelError;
extern kernelEventT kernelEventData;
extern kernelArgsT *kernelArgs;


byte kernelGetPending(void);
void kernelReset(void);


#ifdef __cplusplus
}
#endif


#endif
#endif // KERNEL_H
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef DMA_H
#define DMA_H
#ifndef WITHOUT_DMA


#ifdef __cplusplus
extern "C"
{
#endif


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f256.h"
#endif


void dmaFill(uint32_t start, uint32_t length, byte value);
void dma2dFill(uint32_t start, uint16_t width, uint16_t height, uint16_t stride, byte value);


#ifdef __cplusplus
}
#endif


#endif
#endif // DMA_H
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef MATH_H
#define MATH_H
#ifndef WITHOUT_MATH


#ifdef __cplusplus
extern "C"
{
#endif


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f256.h"
#endif


int16_t  mathSignedDivision(int16_t a, int16_t b);
int16_t  mathSignedDivisionRemainder(int16_t a, int16_t b, int16_t *remainder);
int32_t  mathSignedMultiply(int16_t a, int16_t b);
uint32_t mathUnsignedAddition(uint32_t a, uint32_t b);
uint16_t mathUnsignedDivision(uint16_t a, uint16_t b);
uint16_t mathUnsignedDivisionRemainder(uint16_t a, uint16_t b, uint16_t *remainder);
uint32_t mathUnsignedMultiply(uint16_t a, uint16_t b);


#ifdef __cplusplus
}
#endif


#endif
#endif // MATH_H
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef RANDOM_H
#define RANDOM_H
#ifndef WITHOUT_RANDOM


#ifdef __cplusplus
extern "C"
{
#endif


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f256.h"
#endif


uint16_t randomRead(void);
void     randomReset(void);
void     randomSeed(uint16_t seed);


#ifdef __cplusplus
}
#endif


#endif
#endif // RANDOM_H
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef TEXT_H
#define TEXT_H
#ifndef WITHOUT_TEXT


#ifdef __cplusplus
extern "C"
{
#endif


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f256.h"
#endif


// Apple IIgs Colors, because that's how we roll.
typedef enum textColorsE {
	BLACK = 0,
	DEEP_RED,
	DARK_BLUE,
	PURPLE,
	DARK_GREEN,
	DARK_GRAY,
	MEDIUM_BLUE,
	LIGHT_BLUE,
	BROWN,
	ORANGE,
	LIGHT_GRAY,
	PINK,
	LIGHT_GREEN,
	YELLOW,
	AQUAMARINE,
	WHITE,
	TEXTCOLORS_COUNT
} textColorsT;


extern colorT textColors[16];


void __putchar(char c);  // Allows printf().

void textClear(void);
void textDefineBackgroundColor(byte slot, byte r, byte g, byte b);
void textDefineForegroundColor(byte slot, byte r, byte g, byte b);
void textEnableBackgroundColors(bool b);
void textGetXY(byte *x, byte *y);
void textGotoXY(byte x, byte y);
void textPrint(char *message);
void textPrintInt(int32_t value);
void textPrintUInt(uint32_t value);
void textReset(void);
void textSetColor(byte f, byte b);
void textSetCursor(byte c);
void textSetDouble(bool x, bool y);


#ifdef __cplusplus
}
#endif


#endif
#endif // TEXT_H
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef BITMAP_H
#define BITMAP_H
#ifndef WITHOUT_BITMAP


#ifdef __cplusplus
extern "C"
{
#endif


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f256.h"
#endif


void bitmapClear(void);
void bitmapGetResolution(uint16_t *x, uint16_t *y);
void bitmapLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void bitmapPutPixel(uint16_t x, uint16_t y);
void bitmapReset(void);
void bitmapSetActive(byte p);
void bitmapSetAddress(byte p, uint32_t a);
void bitmapSetCLUT(byte clut);
void bitmapSetColor(byte c);
void bitmapSetVisible(byte p, bool v);


#ifdef __cplusplus
}
#endif


#endif
#endif // BITMAP_H
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef TILE_H
#define TILE_H
#ifndef WITHOUT_TILE


#ifdef __cplusplus
extern "C"
{
#endif


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f256.h"
#endif


void tileDefineTileMap(byte t, uint32_t address, byte tileSize, uint16_t mapSizeX, uint16_t mapSizeY);
void tileDefineTileSet(byte t, uint32_t address, bool square);
void tileSetScroll(byte t, byte xPixels, uint16_t xTiles, byte yPixels, uint16_t yTiles);
void tileSetVisible(byte t, bool v);
void tileReset(void);


#ifdef __cplusplus
}
#endif


#endif
#endif // TILE_H
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef GRAPHICS_H
#define GRAPHICS_H
#ifndef WITHOUT_GRAPHICS


#ifdef __cplusplus
extern "C"
{
#endif


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f256.h"
#endif


void graphicsDefineColor(byte clut, byte slot, byte r, byte g, byte b);
void graphicsReset();
void graphicsSetLayerBitmap(byte layer, byte which);
void graphicsSetLayerTile(byte layer, byte which);
void graphicsWaitVerticalBlank(void);


#ifdef __cplusplus
}
#endif


#endif
#endif // GRAPHICS_H
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef SPRITE_H
#define SPRITE_H
#ifndef WITHOUT_SPRITE


#ifdef __cplusplus
extern "C"
{
#endif


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f256.h"
#endif


void spriteDefine(byte s, uint32_t address, byte size, byte CLUT, byte layer);
void spriteSetPosition(byte s, uint16_t x, uint16_t y);
void spriteSetVisible(byte s, bool v);
void spriteReset(void);


#ifdef __cplusplus
}
#endif


#endif
#endif // SPRITE_H
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef FILE_H
#define FILE_H
#ifndef WITHOUT_FILE


#ifdef __cplusplus
extern "C"
{
#endif


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f256.h"
#endif


typedef struct fileDirEntS {
	unsigned char  d_blocks;
	unsigned char  d_type;
	char           d_name[256];
} fileDirEntT;


int8_t       fileClose(uint8_t *fd);
int8_t       fileCloseDir(char *dir);
int8_t       fileMakeDir(char *dir);
uint8_t     *fileOpen(char *fname, char *mode);
char        *fileOpenDir(char *name);
int16_t      fileRead(void *buf, uint16_t nbytes, uint16_t nmemb, uint8_t *fd);
fileDirEntT *fileReadDir(char *dir);
int8_t       fileRemoveDir(char *dir);
int8_t       fileRename(char *name, char *to);
void         fileReset(void);
int8_t       fileSeek(uint8_t *fd, uint32_t offset, uint8_t whence);
int8_t       fileUnlink(char *name);
int16_t      fileWrite(void *buf, uint16_t nbytes, uint16_t nmemb, uint8_t *fd);


#define _DE_ISREG(t)  (t == 0)
#define _DE_ISDIR(t)  (t == 1)
#define _DE_ISLBL(t)  (t == 2)
#define _DE_ISLNK(t)  (0)


// Aliases to the standard names if they don't exist.
#ifndef DIR
#define closedir   fileCloseDir
#define DIR        char
#define dirent     fileDirEntS
#define FILE       uint8_t
#define fclose     fileClose
#define fopen      fileOpen
#define fread      fileRead
#define fseek      fileSeek
#define fwrite     fileWrite
#define mkdir(d,m) fileMakeDir(d)
#define opendir    fileOpenDir
#define readdir    fileReadDir
#define rename     fileRename
#define rewind(s)  (void)fileSeek(s, 0, SEEK_SET)
#define rmdir      fileRemoveDir
#define SEEK_SET   0
#define STDIN      0
#define STDOUT     1
#define unlink     fileUnlink
#endif


#ifdef __cplusplus
}
#endif


#endif
#endif // FILE_H
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef PLATFORM_H
#define PLATFORM_H
#ifndef WITHOUT_PLATFORM


#ifdef __cplusplus
extern "C"
{
#endif


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f256.h"
#endif


void __putchar(char c);
int  getchar(void);  // This is an int so llvm-mos finds it.


#ifdef __cplusplus
}
#endif


#endif
#endif // PLATFORM_H
#ifdef F256LIB_IMPLEMENTATION
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f256.h"
#include "f_kernel.c"
#include "f_dma.c"
#include "f_math.c"
#include "f_random.c"
#include "f_text.c"
#include "f_bitmap.c"
#include "f_tile.c"
#include "f_graphics.c"
#include "f_sprite.c"
#include "f_file.c"
#include "f_platform.c"
#endif


void f256Init(void) {
	// Swap I/O page 0 into bank 6.  This is our normal state.
	POKE(MMU_IO_CTRL, MMU_IO_PAGE_0);

	POKE(VKY_MSTR_CTRL_0, 63); // Enable text and all graphics.

	POKE(MMU_MEM_CTRL, 0xb3);  // MLUT editing enabled, editing 3, 3 is active.

	// Set all memory slots to be CPU memory.
	POKE(MMU_MEM_BANK_0, 0);
	POKE(MMU_MEM_BANK_1, 1);
	POKE(MMU_MEM_BANK_2, 2);
	POKE(MMU_MEM_BANK_3, 3);
	POKE(MMU_MEM_BANK_4, 4);
	POKE(MMU_MEM_BANK_5, 5);
	//POKE(MMU_MEM_BANK_6, 6);  // Don't use this - it's for the micro kernel.
	//POKE(MMU_MEM_BANK_7, 7);  // Don't use this - it's for the micro kernel.

#ifndef WITHOUT_KERNEL
	kernelReset();
#endif
#ifndef WITHOUT_GRAPHICS
	graphicsReset();
#endif
#ifndef WITHOUT_TEXT
	textReset();
#endif
#ifndef WITHOUT_BITMAP
	bitmapReset();
#endif
#ifndef WITHOUT_TILE
	tileReset();
#endif
#ifndef WITHOUT_SPRITE
	spriteReset();
#endif
#ifndef WITHOUT_FILE
	fileReset();
#endif
#ifndef WITHOUT_RANDOM
	randomReset();
#endif
}


void f256Reset(void) {
	asm("sei");
	POKE(MMU_MEM_BANK_7, 7);
	POKE(0xD6A2, 0xDE);
	POKE(0xD6A3, 0xAD);
	POKE(0xD6A0, 0xF0);
	POKE(0xD6A0, 0x00);
	asm("JMP ($FFFC)");
}


byte FAR_PEEK(uint32_t address) {
	byte block;
	byte result;

	SWAP_IO_SETUP();

	block = address / EIGHTK;
	address &= 0x1FFF;  // Find offset into this block.
	POKE(SWAP_SLOT, block);
	result = PEEK(SWAP_ADDR + address);
	SWAP_RESTORE_SLOT();

	SWAP_IO_SHUTDOWN();

	return result;
}


uint16_t FAR_PEEKW(uint32_t address) {
	byte     block;
	uint16_t result;

	SWAP_IO_SETUP();

	block = address / EIGHTK;
	address &= 0x1FFF;  // Find offset into this block.
	POKE(SWAP_SLOT, block);
	result = PEEKW(SWAP_ADDR + address);
	SWAP_RESTORE_SLOT();

	SWAP_IO_SHUTDOWN();

	return result;
}


void *FAR_POINTER(uint32_t address) {
	// This only works if we use slot 5 and don't restore it after swapping.
#if SWAP_SLOT == MMU_MEM_BANK_5
	byte block;

	block = address / EIGHTK;
	address &= 0x1FFF;  // Find offset into this block.
	POKE(SWAP_SLOT, block);
	return (void *)address;
#else
	return 0;
#endif
}


void FAR_POKE(uint32_t address, byte value) {
	byte block;

	SWAP_IO_SETUP();

	block = address / EIGHTK;
	address &= 0x1FFF;  // Find offset into this block.
	POKE(SWAP_SLOT, block);
	POKE(SWAP_ADDR + address, value);
	SWAP_RESTORE_SLOT();

	SWAP_IO_SHUTDOWN();
}



void FAR_POKEW(uint32_t address, uint16_t value) {
	byte block;

	SWAP_IO_SETUP();

	block = address / EIGHTK;
	address &= 0x1FFF;  // Find offset into this block.
	POKE(SWAP_SLOT, block);
	POKEW(SWAP_ADDR + address, value);
	SWAP_RESTORE_SLOT();

	SWAP_IO_SHUTDOWN();
}


#ifndef WITHOUT_MAIN
#ifdef main
#undef main
#endif
int f256main(int argc, char *argv[]);
int main(void) {
	f256Init();
	f256main(kernelArgs->common.extlen / 2, (char **)kernelArgs->common.ext);
	f256Reset();
	return 0;
}
#define main f256main   // This one is needed if you build f256.c included with your code.
#endif
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef WITHOUT_KERNEL


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f_kernel.h"
#endif


kernelEventT kernelEventData;  // Allocate some RAM to hold event data.
kernelArgsT *kernelArgs;       // Create an alias for the kernel args.
char         kernelError;


byte kernelGetPending(void) {
	return -kernelArgs->events.pending;
}


void kernelReset(void) {
	// Plop this into the zero page where the kernel can find it.
	kernelArgs = (kernelArgsT *)0x00f0;
	// Tell the kernel where our event buffer lives.
	kernelArgs->events.event = &kernelEventData;
}


/*
			case EVENT(GAME):
				// Joystick
				break;

			case EVENT(key.PRESSED):
				// Keyboard
				break;
			case EVENT(key.RELEASED):
				// Keyboard
				break;

			case EVENT(mouse.CLICKS):
				// Mouse
				break;
			case EVENT(mouse.DELTA):
				// Mouse
				break;

			case EVENT(block.NAME):
				// Block
				break;
			case EVENT(block.SIZE):
				// Block
				break;
			case EVENT(block.DATA):
				// Block
				break;
			case EVENT(block.WROTE):
				// Block
				break;
			case EVENT(block.FORMATTED):
				// Block
				break;
			case EVENT(block.ERROR):
				// Block
				break;

			case EVENT(file.NOT_FOUND):
				// File
				break;
			case EVENT(file.OPENED):
				// File
				break;
			case EVENT(file.DATA):
				// File
				break;
			case EVENT(file.WROTE):
				// File
				break;
			case EVENT(file.EOF):
				// File
				break;
			case EVENT(file.CLOSED):
				// File
				break;
			case EVENT(file.RENAMED):
				// File
				break;
			case EVENT(file.DELETED):
				// File
				break;
			case EVENT(file.ERROR):
				// File
				break;

			case EVENT(directory.OPENED):
				// Directory
				break;
			case EVENT(directory.VOLUME):
				// Directory
				break;
			case EVENT(directory.FILE):
				// Directory
				break;
			case EVENT(directory.FREE):
				// Directory
				break;
			case EVENT(directory.EOF):
				// Directory
				break;
			case EVENT(directory.CLOSED):
				// Directory
				break;
			case EVENT(directory.ERROR):
				// Directory
				break;

			// ***TODO*** Network
*/


#endif
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef WITHOUT_DMA


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f_dma.h"
#endif


//static void dmaWait(void);


void dmaFill(uint32_t start, uint32_t length, byte value) {
	while (PEEKW(RAST_ROW_L) != 482); // Wait for VBL.

	POKE(DMA_CTRL, DMA_CTRL_FILL | DMA_CTRL_ENABLE);
	POKE(DMA_FILL_VAL, value);
	POKEA(DMA_DST_ADDR, start);
	POKEA(DMA_COUNT, length);
	POKE(DMA_CTRL, PEEK(DMA_CTRL) | DMA_CTRL_START);

//	dmaWait();
}



void dma2dFill(uint32_t start, uint16_t width, uint16_t height, uint16_t stride, byte value) {
	while (PEEKW(RAST_ROW_L) != 482); // Wait for VBL.

	asm("sei");
	POKE(DMA_CTRL, DMA_CTRL_2D | DMA_CTRL_FILL | DMA_CTRL_ENABLE);
	POKE(DMA_FILL_VAL, value);
	POKEA(DMA_DST_ADDR, start);
	POKEW(DMA_WIDTH, width);
	POKEW(DMA_HEIGHT, height);
	POKEW(DMA_STRIDE_DST, stride);
	POKE(DMA_CTRL, PEEK(DMA_CTRL) | DMA_CTRL_START);
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("cli");

//	dmaWait();
}


/*
static void dmaWait(void) {

	// ***FIX*** This whole block seems unneeded if DMA halts the CPU while it transfers.

	// First, wait for DMA to be complete.
	while (PEEK(DMA_STATUS) & DMA_STAT_BUSY)
		// Spin our wheels.
		;

	POKE(DMA_CTRL, 0);

	// Then wait for a VBL because two DMAs per frame will crash.
	//graphicsWaitVerticalBlank();
}
*/


#endif
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef WITHOUT_MATH


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f_math.h"
#endif


int16_t mathSignedDivision(int16_t a, int16_t b) {
	byte    signA = 0;  // Zero indicates positive.
	byte    signB = 0;
	int16_t r;

	if (a < 0) {
		signA = 1;
		a = -a;
	}
	if (b < 0) {
		signB = 1;
		b = -b;
	}

	POKEW(DIVU_NUM_L, a);
	POKEW(DIVU_DEN_L, b);
	r = PEEKW(QUOU_LL);

	if (signA + signB == 1) r = -r;

	return r;
}


int16_t mathSignedDivisionRemainder(int16_t a, int16_t b, int16_t *remainder) {
	byte    signA = 0;  // Zero indicates positive.
	byte    signB = 0;
	int16_t r;

	if (a < 0) {
		signA = 1;
		a = -a;
	}
	if (b < 0) {
		signB = 1;
		b = -b;
	}

	POKEW(DIVU_NUM_L, a);
	POKEW(DIVU_DEN_L, b);
	r = PEEKW(QUOU_LL);
	*remainder = PEEKW(REMU_HL);

	if (signA + signB == 1) r = -r;

	return r;
}


int32_t mathSignedMultiply(int16_t a, int16_t b) {
	byte    signA = 0;  // Zero indicates positive.
	byte    signB = 0;
	int32_t r;

	if (a < 0) {
		signA = 1;
		a = -a;
	}
	if (b < 0) {
		signB = 1;
		b = -b;
	}

	POKEW(MULU_A_L, a);
	POKEW(MULU_B_L, b);
	r = PEEKD(MULU_LL);

	if (signA + signB == 1) r = -r;

	return r;
}


uint32_t mathUnsignedAddition(uint32_t a, uint32_t b) {
	POKED(ADD_A_LL, a);
	POKED(ADD_B_LL, b);
	return PEEKD(ADD_R_LL);
}


uint16_t mathUnsignedDivision(uint16_t a, uint16_t b) {
	POKEW(DIVU_NUM_L, a);
	POKEW(DIVU_DEN_L, b);
	return PEEKW(QUOU_LL);
}


uint16_t mathUnsignedDivisionRemainder(uint16_t a, uint16_t b, uint16_t *remainder) {
	POKEW(DIVU_NUM_L, a);
	POKEW(DIVU_DEN_L, b);
	*remainder = PEEKW(REMU_HL);
	return PEEKW(QUOU_LL);
}


uint32_t mathUnsignedMultiply(uint16_t a, uint16_t b) {
	POKEW(MULU_A_L, a);
	POKEW(MULU_B_L, b);
	return PEEKD(MULU_LL);
}


#endif
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef WITHOUT_RANDOM


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f_random.h"
#endif


uint16_t randomRead(void) {
	uint16_t result;

	POKE(VKY_RND_CTRL, 1);  // Enable.
	result = PEEKW(VKY_RNDL);

	return result;
}


void randomReset(void) {
	struct time_t clock;

	// Seed the random number generator from the clock.
	kernelArgs->common.buf = &clock;
	kernelArgs->common.buflen = sizeof(struct time_t);
	kernelCall(Clock.GetTime);
	randomSeed(mathUnsignedMultiply(clock.seconds, clock.centis));
}


void randomSeed(uint16_t seed) {
	POKEW(VKY_SEEDL, seed);
	POKE(VKY_RND_CTRL, 3);  // Enable, load seed.
}


#endif
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef WITHOUT_TEXT


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f_text.h"
#include "f_math.h"
#endif


//***FIX***  IIgs colors aren't as useful as EGA colors.
colorT textColors[16] = {
	{ 0x00, 0x00, 0x00 },  // 0 Black
	{ 0xdd, 0x00, 0x33 },  // 1 Deep Red
	{ 0x00, 0x00, 0x99 },  // 2 Dark Blue
	{ 0xdd, 0x22, 0xdd },  // 3 Purple
	{ 0x00, 0x77, 0x22 },  // 4 Dark Green
	{ 0x55, 0x55, 0x55 },  // 5 Dark Gray
	{ 0x22, 0x22, 0xff },  // 6 Medium Blue
	{ 0x66, 0xaa, 0xff },  // 7 Light Blue
	{ 0x88, 0x55, 0x00 },  // 8 Brown
	{ 0xff, 0x66, 0x00 },  // 9 Orange
	{ 0xaa, 0xaa, 0xaa },  // A Light Gray
	{ 0xff, 0x99, 0x88 },  // B Pink
	{ 0x00, 0xdd, 0x00 },  // C Light Green
	{ 0xff, 0xff, 0x00 },  // D Yellow
	{ 0x55, 0xff, 0x99 },  // E Aquamarine
	{ 0xff, 0xff, 0xff }   // F White
};


static byte  _MAX_COL = 80;
static byte  _MAX_ROW = 30;
static byte  _row     = 0;
static byte  _col     = 0;
static byte  _fcolor  = 15;
static byte  _bcolor  = 0;
static byte  _ccolor  = 240;


// Clear screen to current text attributes.
void textClear(void) {
	byte           mmu   = PEEK(MMU_IO_CTRL);  // Get current MMU state.
	int16_t        i;
	int16_t        count = mathUnsignedMultiply(_MAX_COL, _MAX_ROW);
	volatile byte *vram  = (byte *)TEXT_MATRIX;

	POKE(MMU_IO_CTRL, MMU_IO_TEXT);     // Swap I/O page 2 into bank 6.
	for (i=0; i<count; i++) *vram++ = 32;

	POKE(MMU_IO_CTRL, MMU_IO_COLOR);  // Swap I/O page 3 into bank 6.
	vram = (byte *)TEXT_MATRIX;
	for (i=0; i<count; i++) *vram++ = _ccolor;

	POKE(MMU_IO_CTRL, mmu);  // Restore MMU state.

	textGotoXY(0, 0);
}


void textDefineBackgroundColor(byte slot, byte r, byte g, byte b) {
	byte *write;

	write = (byte *)VKY_TXT_BGLUT + mathUnsignedMultiply(slot, 4);
	*write++ = b;
	*write++ = g;
	*write++ = r;
	*write++ = 0xff;
}


void textDefineForegroundColor(byte slot, byte r, byte g, byte b) {
	byte *write;

	write = (byte *)VKY_TXT_FGLUT + mathUnsignedMultiply(slot, 4);
	*write++ = b;
	*write++ = g;
	*write++ = r;
	*write++ = 0xff;
}


void textEnableBackgroundColors(bool b) {
	POKE(VKY_MSTR_CTRL_1, (PEEK(VKY_MSTR_CTRL_1) & 0xef) | (b << 4));
}


void textGetXY(byte *x, byte *y) {
	*x = _col;
	*y = _row;
}


// Move cursor.
void textGotoXY(byte x, byte y) {
	_col = x;
	POKE(VKY_CRSR_X_L, _col);  // Set cursor X position.
	POKE(VKY_CRSR_X_H, 0);

	_row = y;
	POKE(VKY_CRSR_Y_L, _row);  // Set cursor Y position.
	POKE(VKY_CRSR_Y_H, 0);
}


// Print a string to the screen.
void textPrint(char *message) {
	int16_t  x      = 0;
	int16_t  i      = 0;
	int16_t  j      = 0;
	int16_t  m      = 0;
	byte     mmu    = PEEK(MMU_IO_CTRL);  // Get current MMU state.
	volatile byte *vram = (byte *)mathUnsignedAddition(TEXT_MATRIX, mathUnsignedMultiply(_MAX_COL, _row));
	volatile byte *save = 0;

	while (message[x] != 0) {
		switch (message[x]) {
			default:
				POKE(MMU_IO_CTRL, MMU_IO_COLOR);  // Swap I/O page 3 into bank 6.
				vram[_col] = _ccolor;
				POKE(MMU_IO_CTRL, MMU_IO_TEXT);  // Swap I/O page 2 into bank 6.
				vram[_col] = message[x];
				_col++;
				if (_col != _MAX_COL) break;
				// Fall through.
			case 10:
			case 13:
				_col = 0;
				_row++;
				if (_row == _MAX_ROW) {
					// Scroll contents up one line.
					vram = (byte *)TEXT_MATRIX;
					m = _MAX_COL * (_MAX_ROW - 1); // mathUnsignedMultiply(_MAX_COL, (_MAX_ROW - 1));  // It REALLY doesn't like using the copro for this.
					POKE(MMU_IO_CTRL, MMU_IO_COLOR);  // Swap I/O page 3 into bank 6.
					for (j=0; j<2; j++) {  // Twice - first is the text, second is color.
						for (i = 0; i < m; i++) {
							vram[i] = vram[i + _MAX_COL];
						}
						POKE(MMU_IO_CTRL, MMU_IO_TEXT);  // Swap I/O page 2 into bank 6.
					}
					// Clear bottom line.
					vram += i;
					save = vram;
					POKE(MMU_IO_CTRL, MMU_IO_COLOR);  // Swap I/O page 3 into bank 6.
					for (i = 0; i < _MAX_COL; i++) *vram++ = _ccolor;
					POKE(MMU_IO_CTRL, MMU_IO_TEXT);  // Swap I/O page 2 into bank 6.
					vram = save;
					for (i = 0; i < _MAX_COL; i++) *vram++ = 32;
					// Set up on bottom line.
					_row--;
					vram = (byte *)mathUnsignedAddition(TEXT_MATRIX, (_MAX_ROW - 1));
				} else {
					vram += _MAX_COL;
				}
				break;
		}
		x++;
	}

	POKE(MMU_IO_CTRL, mmu);  // Restore MMU state.

	textGotoXY(_col, _row);
}


void textPrintInt(int32_t value){
	if (value < 0) {
		textPrint("-");
		value = -value;
	}
	textPrintUInt(value);
}


void textPrintUInt(uint32_t value){
	char c[2];

	if (value > 9) {
		if (value > 65535) {
			textPrintUInt(value / 10);  // Can't use the coprocessor for uint32.
		} else {
			textPrintUInt(mathUnsignedDivision(value,  10));
		}
	}

	c[0] = '0' + (value % 10);
	c[1] = 0;
	textPrint(c);
}


void textReset(void) {
	byte  x;

	_fcolor  = 15;
	_bcolor  = 0;
	_ccolor  = 240;

	// Make font taller for us blind people.
	textSetDouble(false, true);

	// No cursor by default.
	textSetCursor(0);

	// Set up default text colors.
	for (x=0; x<TEXTCOLORS_COUNT; x++) {
		textDefineForegroundColor(x, textColors[x].r, textColors[x].g, textColors[x].b);
		textDefineBackgroundColor(x, textColors[x].r, textColors[x].g, textColors[x].b);
	}

	textClear();
}


void textSetColor(byte f, byte b) {
	_fcolor = f;
	_bcolor = b;
	_ccolor = (f << 4) + b;
}


void textSetCursor(byte c) {
	if (c == 0) {
		POKE(VKY_CRSR_CTRL, 0);  // No cursor.
	} else {
		POKE(VKY_CRSR_CTRL, 3);  // Enable cursor, 1/2s flash.
		POKE(VKY_CRSR_CHAR, c);  // Set cursor shape.  (199 = Checkerboard)
	}
}


void textSetDouble(bool x, bool y) {
	POKE(VKY_MSTR_CTRL_1, (PEEK(VKY_MSTR_CTRL_1) & 0xf9) | (x << 1) | (y << 2));

	_MAX_COL = x ? 40 : 80;
	_MAX_ROW = y ? 30 : 60;
}


#endif
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef WITHOUT_BITMAP


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f_bitmap.h"
#include "f_dma.h"
#endif


static uint16_t _MAX_X;
static uint16_t _MAX_Y;
static uint32_t _PAGE_SIZE;
static uint32_t _BITMAP_BASE[3];   // Maximum of 3 pages possible.
static byte     _BITMAP_CLUT[3];
static byte     _color;
static byte     _active;           // Current drawing page.


#define bitmapPutPixelIOSet(x, y)  ({ \
	uint32_t address = _BITMAP_BASE[_active] + mathUnsignedAddition(mathUnsignedMultiply(y, _MAX_X), (int32_t)x); \
	byte     block   = address / EIGHTK; \
	address &= 0x1FFF; \
	POKE(SWAP_SLOT, block); \
	POKE(SWAP_ADDR + address, _color); \
})


void bitmapClear(void) {
#ifdef BOOM
	dmaFill(_BITMAP_BASE[_active], _PAGE_SIZE, _color);
	//dma2dFill(_BITMAP_BASE[_active], _MAX_X, _MAX_Y, _MAX_X, _color);
#else
	byte     block = _BITMAP_BASE[_active] / EIGHTK;
	byte     x;
	uint16_t c;
	volatile byte *mem = (byte *)SWAP_ADDR;

	SWAP_IO_SETUP();

	// Clear full 8k blocks.
	for (x=0; x<9; x++) {
		POKE(SWAP_SLOT, block++);
		for (c=0; c<EIGHTK; c++) mem[c] = _color;
	}
	// Clear last partial block.
	POKE(SWAP_SLOT, block);
	for (c=0; c<5120; c++) mem[c] = _color;

	SWAP_RESTORE_SLOT();
	SWAP_IO_SHUTDOWN();
#endif
}


void bitmapGetResolution(uint16_t *x, uint16_t *y) {
	*x = _MAX_X;
	*y = _MAX_Y;
}


void bitmapLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
	uint16_t x;
	uint16_t y;
	int16_t  dx;
	int16_t  dy;
	int16_t  incX;
	int16_t  incY;
	int16_t  balance;

	SWAP_IO_SETUP();

	if (x2 >= x1) {
		dx = x2 - x1;
		incX = 1;
	} else {
		dx = x1 - x2;
		incX = -1;
	}

	if (y2 >= y1) {
		dy = y2 - y1;
		incY = 1;
	} else {
		dy = y1 - y2;
		incY = -1;
	}

	x = x1;
	y = y1;

	if (dx >= dy) {
		dy <<= 1;
		balance = dy - dx;
		dx <<= 1;
		while (x != x2) {
			bitmapPutPixelIOSet(x, y);
			if (balance >= 0) {
				y += incY;
				balance -= dx;
			}
			balance += dy;
			x += incX;
		}
		bitmapPutPixelIOSet(x, y);
	} else {
		dx <<= 1;
		balance = dx - dy;
		dy <<= 1;
		while (y != y2) {
			bitmapPutPixelIOSet(x, y);
			if (balance >= 0) {
				x += incX;
				balance -= dy;
			}
			balance += dx;
			y += incY;
		}
		bitmapPutPixelIOSet(x, y);
	}

	SWAP_RESTORE_SLOT();
	SWAP_IO_SHUTDOWN();
}


void bitmapPutPixel(uint16_t x, uint16_t y) {
	SWAP_IO_SETUP();
	bitmapPutPixelIOSet(x, y);
	SWAP_RESTORE_SLOT();
	SWAP_IO_SHUTDOWN();
}


void bitmapReset(void) {
	uint32_t realSize;
	uint32_t pageBlocks;

	_MAX_X       = 320;
	_MAX_Y       = 240;
	_PAGE_SIZE   = mathUnsignedMultiply(_MAX_X, _MAX_Y);
	_active      = 0;
	_color       = 255;

	// I could hardcode this, but this preserves the math so I don't forget later.
	pageBlocks   = _PAGE_SIZE / EIGHTK;
	if (mathUnsignedMultiply(pageBlocks, EIGHTK) != _PAGE_SIZE) {
		// Fractional pageBlock.  Round up.
		pageBlocks++;
	}
	realSize = mathUnsignedMultiply(pageBlocks, EIGHTK);  // Works out to 80k or 0x14000.

	// Bitmaps start at the top of far memory and work downwards for each additional page.
	_BITMAP_BASE[0] = 0x080000 - realSize;         // Page 1 = 0x6c000
	_BITMAP_BASE[1] = _BITMAP_BASE[0] - realSize;  // Page 2 = 0x58000
	_BITMAP_BASE[2] = _BITMAP_BASE[1] - realSize;  // Page 3 = 0x44000

	/*
	textPrint("\nbase0 = ");  textPrintInt(_BITMAP_BASE[0]);
	textPrint("\nbase1 = ");  textPrintInt(_BITMAP_BASE[1]);
	textPrint("\nbase2 = ");  textPrintInt(_BITMAP_BASE[2]);
	*/

	_BITMAP_CLUT[0] = 0;
	_BITMAP_CLUT[1] = 0;
	_BITMAP_CLUT[2] = 0;

	// Set up default bitmap memory.
	POKEA(VKY_BM0_ADDR_L, _BITMAP_BASE[0]);  // Location of bitmap data.
	POKEA(VKY_BM1_ADDR_L, _BITMAP_BASE[1]);  // Location of bitmap data.
	POKEA(VKY_BM2_ADDR_L, _BITMAP_BASE[2]);  // Location of bitmap data.

	// Hide everything.
	bitmapSetVisible(0, false);
	bitmapSetVisible(1, false);
	bitmapSetVisible(2, false);
}


void bitmapSetActive(byte p) {
	_active = p;
}


void bitmapSetAddress(byte p, uint32_t a) {
	_BITMAP_BASE[p] = a;
	switch (p) {
		case 0:
			POKEA(VKY_BM0_ADDR_L, a);  // Location of bitmap data.
			break;
		case 1:
			POKEA(VKY_BM1_ADDR_L, a);  // Location of bitmap data.
			break;
		case 2:
			POKEA(VKY_BM2_ADDR_L, a);  // Location of bitmap data.
			break;
	}
}


void bitmapSetCLUT(byte clut) {
	// Convert CLUT address to bits for bitmap control registers.
	_BITMAP_CLUT[_active] = clut << 1;

	switch (_active) {
		case 0:
			POKE(VKY_BM0_CTRL, (PEEK(VKY_BM0_CTRL) & 0xf9) | _BITMAP_CLUT[_active]);
			break;
		case 1:
			POKE(VKY_BM1_CTRL, (PEEK(VKY_BM1_CTRL) & 0xf9) | _BITMAP_CLUT[_active]);
			break;
		case 2:
			POKE(VKY_BM2_CTRL, (PEEK(VKY_BM2_CTRL) & 0xf9) | _BITMAP_CLUT[_active]);
			break;
	}
}


void bitmapSetColor(byte c) {
	_color = c;
}


void bitmapSetVisible(byte p, bool v) {
	switch (p) {
		case 0:
			POKE(VKY_BM0_CTRL, v ? 1 | _BITMAP_CLUT[p] : 0);  // Enable bitmap 0.
			break;
		case 1:
			POKE(VKY_BM1_CTRL, v ? 1 | _BITMAP_CLUT[p] : 0);  // Enable bitmap 1.
			break;
		case 2:
			POKE(VKY_BM2_CTRL, v ? 1 | _BITMAP_CLUT[p] : 0);  // Enable bitmap 2.
			break;
	}
}


#endif
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef WITHOUT_TILE


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f_tile.h"
#endif


static byte _tileSize[3];


void tileDefineTileMap(byte t, uint32_t address, byte tileSize, uint16_t mapSizeX, uint16_t mapSizeY) {
	// Map size is 10 bits.  Docs are wrong.
	_tileSize[t] = tileSize;
	switch (t) {
		case 0:
			POKEA(VKY_TM0_ADDR_L, address);
			POKEW(VKY_TM0_SIZE_X, mapSizeX);
			POKEW(VKY_TM0_SIZE_Y, mapSizeY);
			break;
		case 1:
			POKEA(VKY_TM1_ADDR_L, address);
			POKEW(VKY_TM1_SIZE_X, mapSizeX);
			POKEW(VKY_TM1_SIZE_Y, mapSizeY);
			break;
		case 2:
			POKEA(VKY_TM2_ADDR_L, address);
			POKEW(VKY_TM2_SIZE_X, mapSizeX);
			POKEW(VKY_TM2_SIZE_Y, mapSizeY);
			break;
	}

	tileSetScroll(t, 0, 0, 0, 0);
}


void tileDefineTileSet(byte t, uint32_t address, bool square) {
	switch (t) {
		case 0:
			POKEA(VKY_TS0_ADDR_L, address);
			POKE(VKY_TS0_SQUARE, square << 3);
			break;
		case 1:
			POKEA(VKY_TS1_ADDR_L, address);
			POKE(VKY_TS1_SQUARE, square << 3);
			break;
		case 2:
			POKEA(VKY_TS2_ADDR_L, address);
			POKE(VKY_TS2_SQUARE, square << 3);
			break;
		case 3:
			POKEA(VKY_TS3_ADDR_L, address);
			POKE(VKY_TS3_SQUARE, square << 3);
			break;
		case 4:
			POKEA(VKY_TS4_ADDR_L, address);
			POKE(VKY_TS4_SQUARE, square << 3);
			break;
		case 5:
			POKEA(VKY_TS5_ADDR_L, address);
			POKE(VKY_TS5_SQUARE, square << 3);
			break;
		case 6:
			POKEA(VKY_TS6_ADDR_L, address);
			POKE(VKY_TS6_SQUARE, square << 3);
			break;
		case 7:
			POKEA(VKY_TS7_ADDR_L, address);
			POKE(VKY_TS7_SQUARE, square << 3);
			break;
	}
}


void tileSetScroll(byte t, byte xPixels, uint16_t xTiles, byte yPixels, uint16_t yTiles) {
	uint16_t scrollX = (xTiles << 4) + xPixels;
	uint16_t scrollY = (yTiles << 4) + yPixels;

	switch (t) {
		case 0:
			POKEW(VKY_TM0_POS_X_L, scrollX);
			POKEW(VKY_TM0_POS_Y_L, scrollY);
			break;
		case 1:
			POKEW(VKY_TM1_POS_X_L, scrollX);
			POKEW(VKY_TM1_POS_Y_L, scrollY);
			break;
		case 2:
			POKEW(VKY_TM2_POS_X_L, scrollX);
			POKEW(VKY_TM2_POS_Y_L, scrollY);
			break;
	}
}


void tileSetVisible(byte t, bool v) {
	switch (t) {
		case 0:
			POKE(VKY_TM0_CTRL, ((_tileSize[0] == 8 ? 1 : 0) << 4) | v);
			break;
		case 1:
			POKE(VKY_TM1_CTRL, ((_tileSize[1] == 8 ? 1 : 0) << 4) | v);
			break;
		case 2:
			POKE(VKY_TM2_CTRL, ((_tileSize[2] == 8 ? 1 : 0) << 4) | v);
			break;
	}
}


void tileReset(void) {
	// All maps 8x8 by default.
	_tileSize[0] = 8;
	_tileSize[1] = 8;
	_tileSize[2] = 8;
	// Hide all tilemaps.
	tileSetVisible(0, false);
	tileSetVisible(1, false);
	tileSetVisible(2, false);
}


#endif
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef WITHOUT_GRAPHICS


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f_graphics.h"
#endif


void graphicsDefineColor(byte clut, byte slot, byte r, byte g, byte b) {
	byte      mmu = PEEK(MMU_IO_CTRL);  // Get current MMU state.
	byte     *write;
	uint16_t  gclut;

	switch (clut) {
		case 0:
			gclut = VKY_GR_CLUT_0;
			break;
		case 1:
			gclut = VKY_GR_CLUT_1;
			break;
		case 2:
			gclut = VKY_GR_CLUT_2;
			break;
		case 3:
			gclut = VKY_GR_CLUT_3;
			break;
	}

	POKE(MMU_IO_CTRL, MMU_IO_PAGE_1);  // Swap I/O page 1 into bank 6.

	// This doesn't work for some reason.
	//write = (byte *)mathUnsignedAddition((uint32_t)gclut, mathUnsignedMultiply((uint16_t)slot, (uint16_t)4));

	write = (byte *)gclut + (slot * 4);
	*write++ = b;
	*write++ = g;
	*write++ = r;
	*write++ = 0xff;

	POKE(MMU_IO_CTRL, mmu);  // Restore MMU state.
}


void graphicsReset() {
	int16_t  x;
	byte     y;

	// Set palettes to a gradient so there's at least *something*.
	for (y=0; y<4; y++) {
		for (x=0; x<256; x++) {
			graphicsDefineColor(y, x, x, x, x);
		}
	}

	graphicsSetLayerBitmap(0, 0);
	graphicsSetLayerBitmap(1, 1);
	graphicsSetLayerBitmap(2, 2);
}


void graphicsSetLayerBitmap(byte layer, byte which) {
	switch (layer) {
		case 0:
			POKE(VKY_LAYER_CTRL_0, (PEEK(VKY_LAYER_CTRL_0) & 0xf0) | which);
			break;
		case 1:
			POKE(VKY_LAYER_CTRL_0, (PEEK(VKY_LAYER_CTRL_0) & 0x0f) | (which << 4));
			break;
		case 2:
			POKE(VKY_LAYER_CTRL_1, which);  //***TODO*** This doesn't work?
			break;
	}
}


void graphicsSetLayerTile(byte layer, byte which) {
	graphicsSetLayerBitmap(layer, which + 4);
}


void graphicsWaitVerticalBlank(void) {
	//***TODO*** This assumes we're 60hz with graphics enabled.
	while (PEEKW(RAST_ROW_L) != 482)
		// Spin our wheels.
		;
}


#endif
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef WITHOUT_SPRITE


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f_sprite.h"
#endif


#define OFF_SPR_ADL_L    1
#define OFF_SPR_POS_X_L  4
#define OFF_SPR_POS_Y_L  6


static byte _spriteCtl[64];


void spriteDefine(byte s, uint32_t address, byte size, byte CLUT, byte layer) {
	uint16_t sprite = VKY_SP0_CTRL + (s * 8);
	byte     sz;

	switch (size) {
		case 8:
			sz = 3;
			break;
		case 16:
			sz = 2;
			break;
		case 24:
			sz = 1;
			break;
		case 32:
			sz = 0;
			break;
	}

	_spriteCtl[s] = (sz << 5) | (layer << 3) | (CLUT << 1);
	POKE(sprite, _spriteCtl[s]);
	POKEA(sprite + OFF_SPR_ADL_L, address);
}


void spriteSetPosition(byte s, uint16_t x, uint16_t y) {
	uint16_t sprite = VKY_SP0_CTRL + (s * 8);

	POKEW(sprite + OFF_SPR_POS_X_L, x);
	POKEW(sprite + OFF_SPR_POS_Y_L, y);
}


void spriteSetVisible(byte s, bool v) {
	uint16_t sprite = VKY_SP0_CTRL + (s * 8);

	POKE(sprite, _spriteCtl[s] | v);
}


void spriteReset(void) {
	byte x;
	// Hide all sprites.
	for (x=0; x<64; x++) spriteSetVisible(x, false);
}


#endif
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef WITHOUT_FILE


#include <string.h>

#ifndef F256LIB_AMALGAMATED_BUILD
#include "f_file.h"
#endif


#define MAX_DRIVES 8


static char _dirStream[MAX_DRIVES];


static bool     findName(char *name, int16_t *offset);
static int16_t  kernelRead(uint8_t fd, void *buf, uint16_t nbytes);
static int16_t  kernelWrite(uint8_t fd, void *buf, uint16_t nbytes);
static char    *pathWithoutDrive(char *path, byte *drive);


#pragma push_macro("close")
#undef close
int8_t fileClose(uint8_t *fd) {
	kernelArgs->file.close.stream = *fd;
	kernelCall(File.Close);

	free(fd);

	for (;;) {
		kernelNextEvent();
		switch (kernelEventData.type) {
			case kernelEvent(file.CLOSED):
			case kernelEvent(file.ERROR):
				return -1;
			default:
				continue;
		}
	}

	return 0;
}
#pragma pop_macro("close")


#pragma push_macro("close")
#undef close
int8_t fileCloseDir(char *dir) {
	if (!dir) return -1;

	for (;;) {
		if (*dir) {
			kernelArgs->directory.close.stream = *dir;
			kernelCall(Directory.Close);
			if (!kernelError) {
				*dir = 0;
			}
		}
		kernelNextEvent();
		if (kernelEventData.type == kernelEvent(directory.CLOSED)) {
			dir = NULL;
			return 0;
		}
	}
}
#pragma pop_macro("close")


int8_t fileMakeDir(char *dir) {
	byte  drive;

	dir = pathWithoutDrive(dir, &drive);

	kernelArgs->directory.mkdir.drive = drive;
	kernelArgs->common.buf = dir;
	kernelArgs->common.buflen = strlen(dir);
	kernelCall(Directory.MkDir);
	if (kernelError) return -1;

	for (;;) {
		kernelNextEvent();

		if (kernelEventData.type == kernelEvent(directory.CREATED)) break;
		if (kernelEventData.type == kernelEvent(directory.ERROR))   return -1;
	}

	return 0;
}


uint8_t *fileOpen(char *fname, char *mode) {
	uint8_t  ret = 0;
	uint8_t  m   = 0;  // Default to READ.
	uint8_t *fd;
	byte     drive;
	char    *c;

	fname = pathWithoutDrive(fname, &drive);

	c = mode;
	while (*c != 0) {
		if (*c == 'w') m = 1;  // WRITE
		if (*c == 'a') m = 2;  // APPEND
		c++;
	}

	kernelArgs->common.buf = (uint8_t *)fname;
	kernelArgs->common.buflen = strlen(fname);
	kernelArgs->file.open.drive = drive;
	kernelArgs->file.open.mode = m;
	ret = kernelCall(File.Open);
	if (kernelError) return NULL;

	for (;;) {
		kernelNextEvent();
		switch (kernelEventData.type) {
			case kernelEvent(file.OPENED):
				fd = (uint8_t *)malloc(sizeof(uint8_t));
				*fd = ret;
				return fd;
			case kernelEvent(file.NOT_FOUND):
			case kernelEvent(file.ERROR):
				return NULL;
			default:
				continue;
		}
	}
}


char *fileOpenDir(char *name) {
	byte  drive;
	char  stream;
	char *dir;

	name = pathWithoutDrive(name, &drive);

	if (_dirStream[drive]) return NULL;  // Only one at a time.

	kernelArgs->directory.open.drive = drive;
	kernelArgs->common.buf = name;
	kernelArgs->common.buflen = strlen(name);
	stream = kernelCall(Directory.Open);
	if (kernelError) return NULL;

	for (;;) {
		kernelNextEvent();

		if (kernelEventData.type == kernelEvent(directory.OPENED)) break;
		if (kernelEventData.type == kernelEvent(directory.ERROR))  return NULL;
	}

	_dirStream[drive] = stream;
	dir = &_dirStream[drive];

	return dir;
}


int16_t fileRead(void *buf, uint16_t nbytes, uint16_t nmemb, uint8_t *fd) {
	char    *data     = (char *)buf;
	int16_t  read     = 0;
	uint16_t bytes    = nbytes * nmemb;
	int16_t  returned;

	while (read < bytes) {
		returned = kernelRead(*fd, data + read, bytes - read);
		if (returned < 0) return -1;
		if (returned == 0) break;
		read += returned;
	}

	return read / nbytes;
}


#pragma push_macro("EOF")
#pragma push_macro("FILE")
#undef EOF
#undef FILE
fileDirEntT *fileReadDir(char *dir) {
	static fileDirEntT dirent;
	uint16_t len;

	if (!dir) return NULL;

	kernelArgs->directory.read.stream = *dir;
	kernelCall(Directory.Read);
	if (kernelError) return NULL;

	for (;;) {
		kernelNextEvent();

		switch (kernelEventData.type) {
			case kernelEvent(directory.VOLUME):
				dirent.d_blocks = 0;
				dirent.d_type = 2;
				break;

			case kernelEvent(directory.FILE):
				kernelArgs->common.buf = &dirent.d_blocks;
				kernelArgs->common.buflen = sizeof(dirent.d_blocks);
				kernelCall(ReadExt);
				dirent.d_type = (dirent.d_blocks == 0);
				break;

			case kernelEvent(directory.FREE):
				// dirent doesn't care about these types of records.
				kernelArgs->directory.read.stream = *dir;
				kernelCall(Directory.Read);
				if (!kernelError) continue;
				// Fall through.

			case kernelEvent(directory.EOF):
			case kernelEvent(directory.ERROR):
				return NULL;

			default:
				continue;
		}

		// Copy the name.
		len = kernelEventData.directory.file.len;
		if (len >= sizeof(dirent.d_name)) {
			len = sizeof(dirent.d_name) - 1;
		}

		if (len > 0) {
			kernelArgs->common.buf = &dirent.d_name;
			kernelArgs->common.buflen = len;
			kernelCall(ReadData);
		}
		dirent.d_name[len] = 0;

		return &dirent;
	}
}
#pragma pop_macro("FILE")
#pragma pop_macro("EOF")


int8_t fileRemoveDir(char *dir) {
	byte  drive;

	dir = pathWithoutDrive(dir, &drive);

	kernelArgs->directory.mkdir.drive = drive;
	kernelArgs->common.buf = dir;
	kernelArgs->common.buflen = strlen(dir);
	kernelCall(Directory.RmDir);
	if (kernelError) return -1;

	for (;;) {
		kernelNextEvent();

		if (kernelEventData.type == kernelEvent(directory.DELETED)) break;
		if (kernelEventData.type == kernelEvent(directory.ERROR))   return -1;
	}

	return 0;
}


int8_t fileRename(char *name, char *to) {
	byte    drive;
	byte    drive2;
	int16_t path1;
	int16_t path2;

	name = pathWithoutDrive(name, &drive);
	to = pathWithoutDrive(to, &drive2);

	// ensure that the paths match
	if (false
		|| (drive != drive2)
		|| !findName(name, &path1)
		|| !findName(to, &path2)
		|| (path1 != path2)
		|| (strncmp(name, to, path1) != 0)
		) {
		return -1;
	}

	to += path2;

	kernelArgs->file.delete.drive = drive;
	kernelArgs->common.buf = name;
	kernelArgs->common.buflen = strlen(name);
	kernelArgs->common.ext = to;
	kernelArgs->common.extlen = strlen(to);
	kernelCall(File.Rename);
	if (kernelError) return -1;

	for (;;) {
		kernelNextEvent();
		if (kernelEventData.type == kernelEvent(file.RENAMED)) break;
		if (kernelEventData.type == kernelEvent(file.ERROR))   return -1;
	}

	return 0;
}


void fileReset(void) {
	byte x;

	for (x=0; x<MAX_DRIVES; x++) _dirStream[x] = 0;
}


int8_t fileSeek(uint8_t *fd, uint32_t offset, uint8_t whence) {
	if (whence != SEEK_SET) return -1;

	//***TODO*** We should do this manually for IEC devices.

	kernelArgs->file.seek.stream = *fd;
	kernelArgs->file.seek.offset = offset;
	kernelCall(File.Seek);
	if (kernelError) return -1;

	return 0;
}


int8_t fileUnlink(char *name) {
	byte drive;

	name = pathWithoutDrive(name, &drive);
	kernelArgs->file.delete.drive = drive;
	kernelArgs->common.buf = name;
	kernelArgs->common.buflen = strlen(name);
	kernelCall(File.Delete);
	if (kernelError) return -1;

	for (;;) {
		kernelNextEvent();
		if (kernelEventData.type == kernelEvent(file.DELETED)) break;
		if (kernelEventData.type == kernelEvent(file.ERROR))   return -1;
	}

	return 0;
}


int16_t fileWrite(void *buf, uint16_t nbytes, uint16_t nmemb, uint8_t *fd) {
	uint8_t *data  = (uint8_t *)buf;
	int16_t  total = 0;
	int16_t  bytes = nbytes * nmemb;
	uint8_t  writing;
	int16_t  written;

	while (bytes) {

		if (bytes > 254) {
			writing = 254;
		} else {
			writing = bytes;
		}

		written = kernelWrite(*fd, data + total, writing);
		if (written <= 0) {
			return -1;
		}

		total += written;
		bytes -= written;
	}

	return total / nbytes;
}


static bool findName(char *name, int16_t *offset) {
	int16_t i;
	int16_t pos;

	for (i = pos = 0; name[i]; i++) {
		if (name[i] == '/') {
			pos = i+1;
			if (!name[pos]) {
				// No base name found!
				return false;
			}
		}
	}

	*offset = pos;
	return true;
}


#pragma push_macro("EOF")
#undef EOF
static int16_t kernelRead(uint8_t fd, void *buf, uint16_t nbytes) {

	// STDIN
	if (fd == 0) {
		*(char *)buf = getchar();
		return 1;
	}

	if (nbytes > 256) nbytes = 256;

	kernelArgs->file.read.stream = fd;
	kernelArgs->file.read.buflen = nbytes;
	kernelCall(File.Read);
	if (kernelError) return -1;

	for(;;) {
		kernelNextEvent();
		switch (kernelEventData.type) {
			case kernelEvent(file.DATA):
				kernelArgs->common.buf = buf;
				kernelArgs->common.buflen = kernelEventData.file.data.delivered;
				kernelCall(ReadData);
				if (!kernelEventData.file.data.delivered) return 256;
				return kernelEventData.file.data.delivered;
			case kernelEvent(file.EOF):
				return 0;
			case kernelEvent(file.ERROR):
				return -1;
			default:
				continue;
		}
	}
}
#pragma pop_macro("EOF")


static int16_t kernelWrite(uint8_t fd, void *buf, uint16_t nbytes) {
	int16_t  i;
	char    *text;

	// STDOUT
	if (fd == 1) {
		text = (char *)buf;
		for (i = 0; i < nbytes; i++) {
			__putchar(text[i]);
		}
		return i;
	}

	kernelArgs->file.read.stream = fd;
	kernelArgs->common.buf = buf;
	kernelArgs->common.buflen = nbytes;
	kernelCall(File.Write);
	if (kernelError) return -1;

	for (;;) {
		kernelNextEvent();
		if (kernelEventData.type == kernelEvent(file.WROTE)) return kernelEventData.file.data.delivered;
		if (kernelEventData.type == kernelEvent(file.ERROR)) return -1;
	}
}


static char *pathWithoutDrive(char *path, byte *drive) {
	*drive = 0;

	if (strlen(path) < 2) return path;
	if (path[1] != ':')   return path;
	if ((*path >= '0') && (*path <= '7')) *drive = *path - '0';

	return (path + 2);
}


#endif
/*
 *	Copyright (c) 2024 Scott Duensing, scott@kangaroopunch.com
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */


#ifndef WITHOUT_PLATFORM


#ifndef F256LIB_AMALGAMATED_BUILD
#include "f_platform.h"
#endif


// printf() support.
void __putchar(char c) {
	static char s[2] = { 0, 0 };
	s[0] = c;
	textPrint(s);
}


int getchar(void) {
	while (1) {
		kernelNextEvent();
		if (kernelError) {
			kernelCall(Yield);
			continue;
		}

		if (kernelEventData.type != kernelEvent(key.PRESSED)) continue;
		if (kernelEventData.key.flags) continue;  // Meta key.

		return kernelEventData.key.ascii;
	}
}


#endif
#endif // F256LIB_IMPLEMENTATION
#endif // F256LIB_AMALGAMATED_BUILD
