#ifndef __RENDER_H_
#define __RENDER_H_

#include <r0ketlib/fonts.h>

// ARM supports byte flip natively. Yay!
#define flip(byte) \
	__asm("rbit %[value], %[value];" \
		  "rev  %[value], %[value];" \
			: [value] "+r" (byte) : )

/* Alternatively you could use normal byte flipping:
#define flip(c) do {\
	c = ((c>>1)&0x55)|((c<<1)&0xAA); \
	c = ((c>>2)&0x33)|((c<<2)&0xCC); \
	c = (c>>4) | (c<<4); \
	}while(0)
*/

void setIntFont(const struct FONT_DEF * font);
void setExtFont(const char *file);
int getFontHeight(void);
int DoString(int sx, int sy, const char *s);
int DoChar(int sx, int sy, int c);

#define START_FONT 0
#define SEEK_EXTRAS 1
#define GET_EXTRAS 2
#define SEEK_WIDTH 3
#define GET_WIDTH 4
#define SEEK_DATA 5
#define GET_DATA 6
#define PEEK_DATA 7

int _getFontData(int type, int offset);

#define MAXCHR (30*20)
extern uint8_t charBuf[MAXCHR];

#endif
