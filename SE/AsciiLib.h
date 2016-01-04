#ifndef __AsciiLib_H
#define __AsciiLib_H  

/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include <inttypes.h>

/* Font defines --------------------------------------------------------------*/
#define MS_GOTHIC_8x16  0x00
#define SYSTEM_8x16 	0x01
#define FONT6x8 		0X02
#define FONT8x8 		0X03

/* Private define ------------------------------------------------------------*/


static const unsigned char FONT6x8_table[95][8] = {
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}, // space
	{0x20,0x20,0x20,0x20,0x20,0x00,0x20,0x00}, // !
	{0x50,0x50,0x50,0x00,0x00,0x00,0x00,0x00}, // "
	{0x50,0x50,0xF8,0x50,0xF8,0x50,0x50,0x00}, // #
	{0x20,0x78,0xA0,0x70,0x28,0xF0,0x20,0x00}, // $
	{0xC0,0xC8,0x10,0x20,0x40,0x98,0x18,0x00}, // %
	{0x40,0xA0,0xA0,0x40,0xA8,0x90,0x68,0x00}, // &
	{0x30,0x30,0x20,0x40,0x00,0x00,0x00,0x00}, // '
	{0x10,0x20,0x40,0x40,0x40,0x20,0x10,0x00}, // (
	{0x40,0x20,0x10,0x10,0x10,0x20,0x40,0x00}, // )
	{0x00,0x20,0xA8,0x70,0x70,0xA8,0x20,0x00}, // *
	{0x00,0x20,0x20,0xF8,0x20,0x20,0x00,0x00}, // +
	{0x00,0x00,0x00,0x00,0x30,0x30,0x20,0x40}, // ,
	{0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x00}, // -
	{0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00}, // .
	{0x00,0x08,0x10,0x20,0x40,0x80,0x00,0x00}, // /
	{0x70,0x88,0x88,0xA8,0x88,0x88,0x70,0x00}, // 0
	{0x20,0x60,0x20,0x20,0x20,0x20,0x70,0x00}, // 1
	{0x70,0x88,0x08,0x70,0x80,0x80,0xF8,0x00}, // 2
	{0xF8,0x08,0x10,0x30,0x08,0x88,0x70,0x00}, // 3
	{0x10,0x30,0x50,0x90,0xF8,0x10,0x10,0x00}, // 4
	{0xF8,0x80,0xF0,0x08,0x08,0x88,0x70,0x00}, // 5
	{0x38,0x40,0x80,0xF0,0x88,0x88,0x70,0x00}, // 6
	{0xF8,0x08,0x08,0x10,0x20,0x40,0x80,0x00}, // 7
	{0x70,0x88,0x88,0x70,0x88,0x88,0x70,0x00}, // 8
	{0x70,0x88,0x88,0x78,0x08,0x10,0xE0,0x00}, // 9
	{0x00,0x00,0x20,0x00,0x20,0x00,0x00,0x00}, // :
	{0x00,0x00,0x20,0x00,0x20,0x20,0x40,0x00}, // ;
	{0x08,0x10,0x20,0x40,0x20,0x10,0x08,0x00}, // <
	{0x00,0x00,0xF8,0x00,0xF8,0x00,0x00,0x00}, // =
	{0x40,0x20,0x10,0x08,0x10,0x20,0x40,0x00}, // >
	{0x70,0x88,0x08,0x30,0x20,0x00,0x20,0x00}, // ?
	{0x70,0x88,0xA8,0xB8,0xB0,0x80,0x78,0x00}, // @
	{0x20,0x50,0x88,0x88,0xF8,0x88,0x88,0x00}, // A
	{0xF0,0x88,0x88,0xF0,0x88,0x88,0xF0,0x00}, // B
	{0x70,0x88,0x80,0x80,0x80,0x88,0x70,0x00}, // C
	{0xF0,0x88,0x88,0x88,0x88,0x88,0xF0,0x00}, // D
	{0xF8,0x80,0x80,0xF0,0x80,0x80,0xF8,0x00}, // E
	{0xF8,0x80,0x80,0xF0,0x80,0x80,0x80,0x00}, // F
	{0x78,0x88,0x80,0x80,0x98,0x88,0x78,0x00}, // G
	{0x88,0x88,0x88,0xF8,0x88,0x88,0x88,0x00}, // H
	{0x70,0x20,0x20,0x20,0x20,0x20,0x70,0x00}, // I
	{0x38,0x10,0x10,0x10,0x10,0x90,0x60,0x00}, // J
	{0x88,0x90,0xA0,0xC0,0xA0,0x90,0x88,0x00}, // K
	{0x80,0x80,0x80,0x80,0x80,0x80,0xF8,0x00}, // L
	{0x88,0xD8,0xA8,0xA8,0xA8,0x88,0x88,0x00}, // M
	{0x88,0x88,0xC8,0xA8,0x98,0x88,0x88,0x00}, // N
	{0x70,0x88,0x88,0x88,0x88,0x88,0x70,0x00}, // O
	{0xF0,0x88,0x88,0xF0,0x80,0x80,0x80,0x00}, // P
	{0x70,0x88,0x88,0x88,0xA8,0x90,0x68,0x00}, // Q
	{0xF0,0x88,0x88,0xF0,0xA0,0x90,0x88,0x00}, // R
	{0x70,0x88,0x80,0x70,0x08,0x88,0x70,0x00}, // S
	{0xF8,0xA8,0x20,0x20,0x20,0x20,0x20,0x00}, // T
	{0x88,0x88,0x88,0x88,0x88,0x88,0x70,0x00}, // U
	{0x88,0x88,0x88,0x88,0x88,0x50,0x20,0x00}, // V
	{0x88,0x88,0x88,0xA8,0xA8,0xA8,0x50,0x00}, // W
	{0x88,0x88,0x50,0x20,0x50,0x88,0x88,0x00}, // X
	{0x88,0x88,0x50,0x20,0x20,0x20,0x20,0x00}, // Y
	{0xF8,0x08,0x10,0x70,0x40,0x80,0xF8,0x00}, // Z
	{0x78,0x40,0x40,0x40,0x40,0x40,0x78,0x00}, // [
	{0x00,0x80,0x40,0x20,0x10,0x08,0x00,0x00}, //
	{0x78,0x08,0x08,0x08,0x08,0x08,0x78,0x00}, // ]
	{0x20,0x50,0x88,0x00,0x00,0x00,0x00,0x00}, // ^
	{0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x00}, // _
	{0x60,0x60,0x20,0x10,0x00,0x00,0x00,0x00}, // `
	{0x00,0x00,0x60,0x10,0x70,0x90,0x78,0x00}, // a
	{0x80,0x80,0xB0,0xC8,0x88,0xC8,0xB0,0x00}, // b
	{0x00,0x00,0x70,0x88,0x80,0x88,0x70,0x00}, // c
	{0x08,0x08,0x68,0x98,0x88,0x98,0x68,0x00}, // d
	{0x00,0x00,0x70,0x88,0xF8,0x80,0x70,0x00}, // e
	{0x10,0x28,0x20,0x70,0x20,0x20,0x20,0x00}, // f
	{0x00,0x00,0x70,0x98,0x98,0x68,0x08,0x70}, // g
	{0x80,0x80,0xB0,0xC8,0x88,0x88,0x88,0x00}, // h
	{0x20,0x00,0x60,0x20,0x20,0x20,0x70,0x00}, // i
	{0x10,0x00,0x10,0x10,0x10,0x90,0x60,0x00}, // j
	{0x80,0x80,0x90,0xA0,0xC0,0xA0,0x90,0x00}, // k
	{0x60,0x20,0x20,0x20,0x20,0x20,0x70,0x00}, // l
	{0x00,0x00,0xD0,0xA8,0xA8,0xA8,0xA8,0x00}, // m
	{0x00,0x00,0xB0,0xC8,0x88,0x88,0x88,0x00}, // n
	{0x00,0x00,0x70,0x88,0x88,0x88,0x70,0x00}, // o
	{0x00,0x00,0xB0,0xC8,0xC8,0xB0,0x80,0x80}, // p
	{0x00,0x00,0x68,0x98,0x98,0x68,0x08,0x08}, // q
	{0x00,0x00,0xB0,0xC8,0x80,0x80,0x80,0x00}, // r
	{0x00,0x00,0x78,0x80,0x70,0x08,0xF0,0x00}, // s
	{0x20,0x20,0xF8,0x20,0x20,0x28,0x10,0x00}, // t
	{0x00,0x00,0x88,0x88,0x88,0x98,0x68,0x00}, // u
	{0x00,0x00,0x88,0x88,0x88,0x50,0x20,0x00}, // v
	{0x00,0x00,0x88,0x88,0xA8,0xA8,0x50,0x00}, // w
	{0x00,0x00,0x88,0x50,0x20,0x50,0x88,0x00}, // x
	{0x00,0x00,0x88,0x88,0x78,0x08,0x88,0x70}, // y
	{0x00,0x00,0xF8,0x10,0x20,0x40,0xF8,0x00}, // z
	{0x10,0x20,0x20,0x40,0x20,0x20,0x10,0x00}, // {
	{0x20,0x20,0x20,0x00,0x20,0x20,0x20,0x00}, // |
	{0x40,0x20,0x20,0x10,0x20,0x20,0x40,0x00}, // }
	{0x40,0xA8,0x10,0x00,0x00,0x00,0x00,0x00}, // ~
};

static const unsigned char FONT8x8_table[95][8] = {
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}, // space
	{0x30,0x78,0x78,0x30,0x30,0x00,0x30,0x00}, // !
	{0x6C,0x6C,0x6C,0x00,0x00,0x00,0x00,0x00}, // "
	{0x6C,0x6C,0xFE,0x6C,0xFE,0x6C,0x6C,0x00}, // #
	{0x18,0x3E,0x60,0x3C,0x06,0x7C,0x18,0x00}, // $
	{0x00,0x63,0x66,0x0C,0x18,0x33,0x63,0x00}, // %
	{0x1C,0x36,0x1C,0x3B,0x6E,0x66,0x3B,0x00}, // &
	{0x30,0x30,0x60,0x00,0x00,0x00,0x00,0x00}, // '
	{0x0C,0x18,0x30,0x30,0x30,0x18,0x0C,0x00}, // (
	{0x30,0x18,0x0C,0x0C,0x0C,0x18,0x30,0x00}, // )
	{0x00,0x66,0x3C,0xFF,0x3C,0x66,0x00,0x00}, // *
	{0x00,0x30,0x30,0xFC,0x30,0x30,0x00,0x00}, // +
	{0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x30}, // ,
	{0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x00}, // -
	{0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00}, // .
	{0x03,0x06,0x0C,0x18,0x30,0x60,0x40,0x00}, // /
	{0x3E,0x63,0x63,0x6B,0x63,0x63,0x3E,0x00}, // 0
	{0x18,0x38,0x58,0x18,0x18,0x18,0x7E,0x00}, // 1
	{0x3C,0x66,0x06,0x1C,0x30,0x66,0x7E,0x00}, // 2
	{0x3C,0x66,0x06,0x1C,0x06,0x66,0x3C,0x00}, // 3
	{0x0E,0x1E,0x36,0x66,0x7F,0x06,0x0F,0x00}, // 4
	{0x7E,0x60,0x7C,0x06,0x06,0x66,0x3C,0x00}, // 5
	{0x1C,0x30,0x60,0x7C,0x66,0x66,0x3C,0x00}, // 6
	{0x7E,0x66,0x06,0x0C,0x18,0x18,0x18,0x00}, // 7
	{0x3C,0x66,0x66,0x3C,0x66,0x66,0x3C,0x00}, // 8
	{0x3C,0x66,0x66,0x3E,0x06,0x0C,0x38,0x00}, // 9
	{0x00,0x18,0x18,0x00,0x00,0x18,0x18,0x00}, // :
	{0x00,0x18,0x18,0x00,0x00,0x18,0x18,0x30}, // ;
	{0x0C,0x18,0x30,0x60,0x30,0x18,0x0C,0x00}, // <
	{0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00}, // =
	{0x30,0x18,0x0C,0x06,0x0C,0x18,0x30,0x00}, // >
	{0x3C,0x66,0x06,0x0C,0x18,0x00,0x18,0x00}, // ?
	{0x3E,0x63,0x6F,0x69,0x6F,0x60,0x3E,0x00}, // @
	{0x18,0x3C,0x66,0x66,0x7E,0x66,0x66,0x00}, // A
	{0x7E,0x33,0x33,0x3E,0x33,0x33,0x7E,0x00}, // B
	{0x1E,0x33,0x60,0x60,0x60,0x33,0x1E,0x00}, // C
	{0x7C,0x36,0x33,0x33,0x33,0x36,0x7C,0x00}, // D
	{0x7F,0x31,0x34,0x3C,0x34,0x31,0x7F,0x00}, // E
	{0x7F,0x31,0x34,0x3C,0x34,0x30,0x78,0x00}, // F
	{0x1E,0x33,0x60,0x60,0x67,0x33,0x1F,0x00}, // G
	{0x66,0x66,0x66,0x7E,0x66,0x66,0x66,0x00}, // H
	{0x3C,0x18,0x18,0x18,0x18,0x18,0x3C,0x00}, // I
	{0x0F,0x06,0x06,0x06,0x66,0x66,0x3C,0x00}, // J
	{0x73,0x33,0x36,0x3C,0x36,0x33,0x73,0x00}, // K
	{0x78,0x30,0x30,0x30,0x31,0x33,0x7F,0x00}, // L
	{0x63,0x77,0x7F,0x7F,0x6B,0x63,0x63,0x00}, // M
	{0x63,0x73,0x7B,0x6F,0x67,0x63,0x63,0x00}, // N
	{0x3E,0x63,0x63,0x63,0x63,0x63,0x3E,0x00}, // O
	{0x7E,0x33,0x33,0x3E,0x30,0x30,0x78,0x00}, // P
	{0x3C,0x66,0x66,0x66,0x6E,0x3C,0x0E,0x00}, // Q
	{0x7E,0x33,0x33,0x3E,0x36,0x33,0x73,0x00}, // R
	{0x3C,0x66,0x30,0x18,0x0C,0x66,0x3C,0x00}, // S
	{0x7E,0x5A,0x18,0x18,0x18,0x18,0x3C,0x00}, // T
	{0x66,0x66,0x66,0x66,0x66,0x66,0x7E,0x00}, // U
	{0x66,0x66,0x66,0x66,0x66,0x3C,0x18,0x00}, // V
	{0x63,0x63,0x63,0x6B,0x7F,0x77,0x63,0x00}, // W
	{0x63,0x63,0x36,0x1C,0x1C,0x36,0x63,0x00}, // X
	{0x66,0x66,0x66,0x3C,0x18,0x18,0x3C,0x00}, // Y
	{0x7F,0x63,0x46,0x0C,0x19,0x33,0x7F,0x00}, // Z
	{0x3C,0x30,0x30,0x30,0x30,0x30,0x3C,0x00}, // [
	{0x60,0x30,0x18,0x0C,0x06,0x03,0x01,0x00}, //
	{0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x3C,0x00}, // ]
	{0x08,0x1C,0x36,0x63,0x00,0x00,0x00,0x00}, // ^
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF}, // _
	{0x18,0x18,0x0C,0x00,0x00,0x00,0x00,0x00}, // `
	{0x00,0x00,0x3C,0x06,0x3E,0x66,0x3B,0x00}, // a
	{0x70,0x30,0x3E,0x33,0x33,0x33,0x6E,0x00}, // b
	{0x00,0x00,0x3C,0x66,0x60,0x66,0x3C,0x00}, // c
	{0x0E,0x06,0x3E,0x66,0x66,0x66,0x3B,0x00}, // d
	{0x00,0x00,0x3C,0x66,0x7E,0x60,0x3C,0x00}, // e
	{0x1C,0x36,0x30,0x78,0x30,0x30,0x78,0x00}, // f
	{0x00,0x00,0x3B,0x66,0x66,0x3E,0x06,0x7C}, // g
	{0x70,0x30,0x36,0x3B,0x33,0x33,0x73,0x00}, // h
	{0x18,0x00,0x38,0x18,0x18,0x18,0x3C,0x00}, // i
	{0x06,0x00,0x06,0x06,0x06,0x66,0x66,0x3C}, // j
	{0x70,0x30,0x33,0x36,0x3C,0x36,0x73,0x00}, // k
	{0x38,0x18,0x18,0x18,0x18,0x18,0x3C,0x00}, // l
	{0x00,0x00,0x66,0x7F,0x7F,0x6B,0x63,0x00}, // m
	{0x00,0x00,0x7C,0x66,0x66,0x66,0x66,0x00}, // n
	{0x00,0x00,0x3C,0x66,0x66,0x66,0x3C,0x00}, // o
	{0x00,0x00,0x6E,0x33,0x33,0x3E,0x30,0x78}, // p
	{0x00,0x00,0x3B,0x66,0x66,0x3E,0x06,0x0F}, // q
	{0x00,0x00,0x6E,0x3B,0x33,0x30,0x78,0x00}, // r
	{0x00,0x00,0x3E,0x60,0x3C,0x06,0x7C,0x00}, // s
	{0x08,0x18,0x3E,0x18,0x18,0x1A,0x0C,0x00}, // t
	{0x00,0x00,0x66,0x66,0x66,0x66,0x3B,0x00}, // u
	{0x00,0x00,0x66,0x66,0x66,0x3C,0x18,0x00}, // v
	{0x00,0x00,0x63,0x6B,0x7F,0x7F,0x36,0x00}, // w
	{0x00,0x00,0x63,0x36,0x1C,0x36,0x63,0x00}, // x
	{0x00,0x00,0x66,0x66,0x66,0x3E,0x06,0x7C}, // y
	{0x00,0x00,0x7E,0x4C,0x18,0x32,0x7E,0x00}, // z
	{0x0E,0x18,0x18,0x70,0x18,0x18,0x0E,0x00}, // {
	{0x0C,0x0C,0x0C,0x00,0x0C,0x0C,0x0C,0x00}, // |
	{0x70,0x18,0x18,0x0E,0x18,0x18,0x70,0x00}, // }
	{0x3B,0x6E,0x00,0x00,0x00,0x00,0x00,0x00}, // ~
};

static unsigned char const MS_GOTHIC_8x16_table[95][16] = {

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*" ",0*/

{0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,0x18,0x18,0x00,0x00},/*"!",1*/

{0x36,0x24,0x48,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*""",2*/

{0x00,0x24,0x24,0x24,0x24,0xFE,0x48,0x48,0x48,0x48,0xFC,0x48,0x48,0x48,0x48,0x00},/*"#",3*/

{0x10,0x38,0x54,0x92,0x92,0x50,0x30,0x18,0x14,0x12,0x92,0x92,0x54,0x38,0x10,0x00},/*"$",4*/

{0x00,0x62,0x92,0x94,0x94,0x68,0x08,0x10,0x20,0x2C,0x52,0x52,0x92,0x8C,0x00,0x00},/*"%",5*/

{0x00,0x30,0x48,0x48,0x48,0x48,0x30,0x20,0x54,0x94,0x88,0x88,0x94,0x62,0x00,0x00},/*"&",6*/

{0x30,0x30,0x10,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"'",7*/

{0x04,0x08,0x10,0x10,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x10,0x10,0x08,0x04,0x00},/*"(",8*/

{0x40,0x20,0x10,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x10,0x10,0x20,0x40,0x00},/*")",9*/

{0x00,0x00,0x00,0x10,0x92,0x54,0x38,0x10,0x38,0x54,0x92,0x10,0x00,0x00,0x00,0x00},/*"*",10*/

{0x00,0x00,0x00,0x00,0x10,0x10,0x10,0xFE,0x10,0x10,0x10,0x00,0x00,0x00,0x00,0x00},/*"+",11*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x10,0x20,0x00},/*",",12*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"-",13*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00},/*".",14*/

{0x00,0x02,0x02,0x04,0x04,0x08,0x08,0x10,0x20,0x20,0x40,0x40,0x80,0x80,0x00,0x00},/*"/",15*/

{0x00,0x30,0x48,0x84,0x84,0x84,0x84,0x84,0x84,0x84,0x84,0x84,0x48,0x30,0x00,0x00},/*"0",16*/

{0x00,0x10,0x70,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00},/*"1",17*/

{0x00,0x30,0x48,0x84,0x84,0x04,0x08,0x08,0x10,0x20,0x20,0x40,0x80,0xFC,0x00,0x00},/*"2",18*/

{0x00,0x30,0x48,0x84,0x84,0x04,0x08,0x30,0x08,0x04,0x84,0x84,0x48,0x30,0x00,0x00},/*"3",19*/

{0x00,0x08,0x08,0x18,0x18,0x28,0x28,0x48,0x48,0x88,0xFC,0x08,0x08,0x08,0x00,0x00},/*"4",20*/

{0x00,0xFC,0x80,0x80,0x80,0xB0,0xC8,0x84,0x04,0x04,0x04,0x84,0x48,0x30,0x00,0x00},/*"5",21*/

{0x00,0x30,0x48,0x84,0x84,0x80,0xB0,0xC8,0x84,0x84,0x84,0x84,0x48,0x30,0x00,0x00},/*"6",22*/

{0x00,0xFC,0x04,0x04,0x08,0x08,0x08,0x10,0x10,0x10,0x20,0x20,0x20,0x20,0x00,0x00},/*"7",23*/

{0x00,0x30,0x48,0x84,0x84,0x84,0x48,0x30,0x48,0x84,0x84,0x84,0x48,0x30,0x00,0x00},/*"8",24*/

{0x00,0x30,0x48,0x84,0x84,0x84,0x84,0x4C,0x34,0x04,0x84,0x84,0x48,0x30,0x00,0x00},/*"9",25*/

{0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00},/*":",26*/

{0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,0x00,0x30,0x30,0x10,0x20,0x00},/*";",27*/

{0x00,0x00,0x04,0x08,0x10,0x20,0x40,0x80,0x40,0x20,0x10,0x08,0x04,0x00,0x00,0x00},/*"<",28*/

{0x00,0x00,0x00,0x00,0x00,0x7C,0x00,0x00,0x00,0x7C,0x00,0x00,0x00,0x00,0x00,0x00},/*"=",29*/

{0x00,0x00,0x80,0x40,0x20,0x10,0x08,0x04,0x08,0x10,0x20,0x40,0x80,0x00,0x00,0x00},/*">",30*/

{0x00,0x30,0x48,0x84,0x84,0x04,0x08,0x10,0x20,0x20,0x00,0x00,0x30,0x30,0x00,0x00},/*"?",31*/

{0x00,0x38,0x44,0x82,0x9A,0xAA,0xAA,0xAA,0xAA,0xAA,0x9C,0x80,0x42,0x3C,0x00,0x00},/*"@",32*/

{0x00,0x10,0x10,0x28,0x28,0x28,0x28,0x44,0x44,0x44,0x7C,0x82,0x82,0x82,0x00,0x00},/*"A",33*/

{0x00,0xF8,0x84,0x82,0x82,0x82,0x84,0xF8,0x84,0x82,0x82,0x82,0x84,0xF8,0x00,0x00},/*"B",34*/

{0x00,0x38,0x44,0x82,0x82,0x80,0x80,0x80,0x80,0x80,0x82,0x82,0x44,0x38,0x00,0x00},/*"C",35*/

{0x00,0xF8,0x84,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x84,0xF8,0x00,0x00},/*"D",36*/

{0x00,0xFE,0x80,0x80,0x80,0x80,0x80,0xFC,0x80,0x80,0x80,0x80,0x80,0xFE,0x00,0x00},/*"E",37*/

{0x00,0xFE,0x80,0x80,0x80,0x80,0x80,0xFC,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00},/*"F",38*/

{0x00,0x38,0x44,0x82,0x82,0x80,0x80,0x80,0x8E,0x82,0x82,0x82,0x46,0x3A,0x00,0x00},/*"G",39*/

{0x00,0x82,0x82,0x82,0x82,0x82,0x82,0xFE,0x82,0x82,0x82,0x82,0x82,0x82,0x00,0x00},/*"H",40*/

{0x00,0x38,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x38,0x00,0x00},/*"I",41*/

{0x00,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x84,0x84,0x48,0x30,0x00,0x00},/*"J",42*/

{0x00,0x82,0x84,0x84,0x88,0x90,0x90,0xA0,0xD0,0x88,0x88,0x84,0x82,0x82,0x00,0x00},/*"K",43*/

{0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xFE,0x00,0x00},/*"L",44*/

{0x00,0x82,0x82,0xC6,0xC6,0xC6,0xC6,0xAA,0xAA,0xAA,0xAA,0x92,0x92,0x92,0x00,0x00},/*"M",45*/

{0x00,0x82,0x82,0xC2,0xC2,0xA2,0xA2,0x92,0x92,0x8A,0x8A,0x86,0x86,0x82,0x00,0x00},/*"N",46*/

{0x00,0x38,0x44,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x44,0x38,0x00,0x00},/*"O",47*/

{0x00,0xF8,0x84,0x82,0x82,0x82,0x84,0xF8,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00},/*"P",48*/

{0x00,0x38,0x44,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x92,0x8A,0x44,0x3A,0x00,0x00},/*"Q",49*/

{0x00,0xF8,0x84,0x82,0x82,0x82,0x84,0xF8,0x88,0x88,0x84,0x84,0x82,0x82,0x00,0x00},/*"R",50*/

{0x00,0x38,0x44,0x82,0x82,0x80,0x60,0x18,0x04,0x02,0x82,0x82,0x44,0x38,0x00,0x00},/*"S",51*/

{0x00,0xFE,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00},/*"T",52*/

{0x00,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x44,0x38,0x00,0x00},/*"U",53*/

{0x00,0x82,0x82,0x82,0x44,0x44,0x44,0x44,0x28,0x28,0x28,0x10,0x10,0x10,0x00,0x00},/*"V",54*/

{0x00,0x92,0x92,0x92,0x92,0xAA,0xAA,0xAA,0xAA,0x44,0x44,0x44,0x44,0x44,0x00,0x00},/*"W",55*/

{0x00,0x82,0x82,0x44,0x44,0x28,0x28,0x10,0x28,0x28,0x44,0x44,0x82,0x82,0x00,0x00},/*"X",56*/

{0x00,0x82,0x82,0x44,0x44,0x28,0x28,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00},/*"Y",57*/

{0x00,0xFE,0x02,0x04,0x04,0x08,0x08,0x10,0x20,0x20,0x40,0x40,0x80,0xFE,0x00,0x00},/*"Z",58*/

{0x7C,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x7C,0x00},/*"[",59*/

{0x00,0x82,0x82,0x44,0x44,0x28,0x28,0x7C,0x10,0x10,0x7C,0x10,0x10,0x10,0x00,0x00},/*"\",60*/

{0x7C,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x7C,0x00},/*"]",61*/

{0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"^",62*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF},/*"_",63*/

{0x30,0x30,0x10,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"'",64*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x84,0x04,0x3C,0x44,0x84,0x8C,0x76,0x00,0x00},/*"a",65*/

{0x00,0x80,0x80,0x80,0x80,0x80,0xB8,0xC4,0x82,0x82,0x82,0x82,0xC4,0xB8,0x00,0x00},/*"b",66*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x80,0x80,0x80,0x80,0x42,0x3C,0x00,0x00},/*"c",67*/

{0x00,0x02,0x02,0x02,0x02,0x02,0x3A,0x46,0x82,0x82,0x82,0x82,0x46,0x3A,0x00,0x00},/*"d",68*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x44,0x82,0xFE,0x80,0x80,0x42,0x3C,0x00,0x00},/*"e",69*/

{0x00,0x18,0x20,0x20,0x20,0x20,0xF8,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00},/*"f",70*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x3A,0x44,0x44,0x38,0x40,0x7C,0x82,0x82,0x7C,0x00},/*"g",71*/

{0x00,0x80,0x80,0x80,0x80,0x80,0xB8,0xC4,0x82,0x82,0x82,0x82,0x82,0x82,0x00,0x00},/*"h",72*/

{0x00,0x00,0x10,0x10,0x00,0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00},/*"i",73*/

{0x00,0x00,0x10,0x10,0x00,0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x60,0x00},/*"j",74*/

{0x00,0x80,0x80,0x80,0x80,0x80,0x84,0x88,0x90,0xA0,0xD0,0x88,0x84,0x82,0x00,0x00},/*"k",75*/

{0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00},/*"l",76*/

{0x00,0x00,0x00,0x00,0x00,0x00,0xAC,0xD2,0x92,0x92,0x92,0x92,0x92,0x92,0x00,0x00},/*"m",77*/

{0x00,0x00,0x00,0x00,0x00,0x00,0xB8,0xC4,0x82,0x82,0x82,0x82,0x82,0x82,0x00,0x00},/*"n",78*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x44,0x82,0x82,0x82,0x82,0x44,0x38,0x00,0x00},/*"o",79*/

{0x00,0x00,0x00,0x00,0x00,0x00,0xB8,0xC4,0x82,0x82,0x82,0xC4,0xB8,0x80,0x80,0x00},/*"p",80*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x3A,0x46,0x82,0x82,0x82,0x46,0x3A,0x02,0x02,0x00},/*"q",81*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x2E,0x30,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00},/*"r",82*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x82,0x80,0x60,0x1C,0x02,0x82,0x7C,0x00,0x00},/*"s",83*/

{0x00,0x00,0x20,0x20,0x20,0x20,0xF8,0x20,0x20,0x20,0x20,0x20,0x20,0x18,0x00,0x00},/*"t",84*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x82,0x82,0x82,0x82,0x82,0x82,0x46,0x3A,0x00,0x00},/*"u",85*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x82,0x82,0x44,0x44,0x28,0x28,0x10,0x10,0x00,0x00},/*"v",86*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x92,0x92,0x92,0xAA,0xAA,0x44,0x44,0x44,0x00,0x00},/*"w",87*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x82,0x44,0x28,0x10,0x10,0x28,0x44,0x82,0x00,0x00},/*"x",88*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x82,0x82,0x44,0x44,0x28,0x28,0x10,0x20,0xC0,0x00},/*"y",89*/

{0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x04,0x08,0x10,0x20,0x40,0x80,0xFE,0x00,0x00},/*"z",90*/

{0x1C,0x10,0x10,0x10,0x10,0x10,0x10,0x20,0x10,0x10,0x10,0x10,0x10,0x10,0x1C,0x00},/*"{",91*/

{0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10},/*"|",92*/

{0x70,0x10,0x10,0x10,0x10,0x10,0x10,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x70,0x00},/*"}",93*/

{0x64,0x98,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"~",94*/

};

static unsigned char const SYSTEM_8x16_table[95][16] = {
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*" ",0*/

{0x00,0x00,0x00,0x18,0x3C,0x3C,0x3C,0x18,0x18,0x00,0x18,0x18,0x00,0x00,0x00,0x00},/*"!",1*/

{0x00,0x00,0x00,0x66,0x66,0x66,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*""",2*/

{0x00,0x00,0x00,0x36,0x36,0x7F,0x36,0x36,0x36,0x7F,0x36,0x36,0x00,0x00,0x00,0x00},/*"#",3*/

{0x00,0x18,0x18,0x3C,0x66,0x60,0x30,0x18,0x0C,0x06,0x66,0x3C,0x18,0x18,0x00,0x00},/*"$",4*/

{0x00,0x00,0x70,0xD8,0xDA,0x76,0x0C,0x18,0x30,0x6E,0x5B,0x1B,0x0E,0x00,0x00,0x00},/*"%",5*/

{0x00,0x00,0x00,0x38,0x6C,0x6C,0x38,0x60,0x6F,0x66,0x66,0x3B,0x00,0x00,0x00,0x00},/*"&",6*/

{0x00,0x00,0x00,0x18,0x18,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"'",7*/

{0x00,0x00,0x00,0x0C,0x18,0x18,0x30,0x30,0x30,0x30,0x30,0x18,0x18,0x0C,0x00,0x00},/*"(",8*/

{0x00,0x00,0x00,0x30,0x18,0x18,0x0C,0x0C,0x0C,0x0C,0x0C,0x18,0x18,0x30,0x00,0x00},/*")",9*/

{0x00,0x00,0x00,0x00,0x00,0x36,0x1C,0x7F,0x1C,0x36,0x00,0x00,0x00,0x00,0x00,0x00},/*"*",10*/

{0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x7E,0x18,0x18,0x00,0x00,0x00,0x00,0x00,0x00},/*"+",11*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x1C,0x0C,0x18,0x00,0x00},/*",",12*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"-",13*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x1C,0x00,0x00,0x00,0x00},/*".",14*/

{0x00,0x00,0x00,0x06,0x06,0x0C,0x0C,0x18,0x18,0x30,0x30,0x60,0x60,0x00,0x00,0x00},/*"/",15*/

{0x00,0x00,0x00,0x1E,0x33,0x37,0x37,0x33,0x3B,0x3B,0x33,0x1E,0x00,0x00,0x00,0x00},/*"0",16*/

{0x00,0x00,0x00,0x0C,0x1C,0x7C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x00,0x00,0x00,0x00},/*"1",17*/

{0x00,0x00,0x00,0x3C,0x66,0x66,0x06,0x0C,0x18,0x30,0x60,0x7E,0x00,0x00,0x00,0x00},/*"2",18*/

{0x00,0x00,0x00,0x3C,0x66,0x66,0x06,0x1C,0x06,0x66,0x66,0x3C,0x00,0x00,0x00,0x00},/*"3",19*/

{0x00,0x00,0x00,0x30,0x30,0x36,0x36,0x36,0x66,0x7F,0x06,0x06,0x00,0x00,0x00,0x00},/*"4",20*/

{0x00,0x00,0x00,0x7E,0x60,0x60,0x60,0x7C,0x06,0x06,0x0C,0x78,0x00,0x00,0x00,0x00},/*"5",21*/

{0x00,0x00,0x00,0x1C,0x18,0x30,0x7C,0x66,0x66,0x66,0x66,0x3C,0x00,0x00,0x00,0x00},/*"6",22*/

{0x00,0x00,0x00,0x7E,0x06,0x0C,0x0C,0x18,0x18,0x30,0x30,0x30,0x00,0x00,0x00,0x00},/*"7",23*/

{0x00,0x00,0x00,0x3C,0x66,0x66,0x76,0x3C,0x6E,0x66,0x66,0x3C,0x00,0x00,0x00,0x00},/*"8",24*/

{0x00,0x00,0x00,0x3C,0x66,0x66,0x66,0x66,0x3E,0x0C,0x18,0x38,0x00,0x00,0x00,0x00},/*"9",25*/

{0x00,0x00,0x00,0x00,0x00,0x1C,0x1C,0x00,0x00,0x00,0x1C,0x1C,0x00,0x00,0x00,0x00},/*":",26*/

{0x00,0x00,0x00,0x00,0x00,0x1C,0x1C,0x00,0x00,0x00,0x1C,0x1C,0x0C,0x18,0x00,0x00},/*";",27*/

{0x00,0x00,0x00,0x06,0x0C,0x18,0x30,0x60,0x30,0x18,0x0C,0x06,0x00,0x00,0x00,0x00},/*"<",28*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x00,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"=",29*/

{0x00,0x00,0x00,0x60,0x30,0x18,0x0C,0x06,0x0C,0x18,0x30,0x60,0x00,0x00,0x00,0x00},/*">",30*/

{0x00,0x00,0x00,0x3C,0x66,0x66,0x0C,0x18,0x18,0x00,0x18,0x18,0x00,0x00,0x00,0x00},/*"?",31*/

{0x00,0x00,0x00,0x7E,0xC3,0xC3,0xCF,0xDB,0xDB,0xCF,0xC0,0x7F,0x00,0x00,0x00,0x00},/*"@",32*/

{0x00,0x00,0x00,0x18,0x3C,0x66,0x66,0x66,0x7E,0x66,0x66,0x66,0x00,0x00,0x00,0x00},/*"A",33*/

{0x00,0x00,0x00,0x7C,0x66,0x66,0x66,0x7C,0x66,0x66,0x66,0x7C,0x00,0x00,0x00,0x00},/*"B",34*/

{0x00,0x00,0x00,0x3C,0x66,0x66,0x60,0x60,0x60,0x66,0x66,0x3C,0x00,0x00,0x00,0x00},/*"C",35*/

{0x00,0x00,0x00,0x78,0x6C,0x66,0x66,0x66,0x66,0x66,0x6C,0x78,0x00,0x00,0x00,0x00},/*"D",36*/

{0x00,0x00,0x00,0x7E,0x60,0x60,0x60,0x7C,0x60,0x60,0x60,0x7E,0x00,0x00,0x00,0x00},/*"E",37*/

{0x00,0x00,0x00,0x7E,0x60,0x60,0x60,0x7C,0x60,0x60,0x60,0x60,0x00,0x00,0x00,0x00},/*"F",38*/

{0x00,0x00,0x00,0x3C,0x66,0x66,0x60,0x60,0x6E,0x66,0x66,0x3E,0x00,0x00,0x00,0x00},/*"G",39*/

{0x00,0x00,0x00,0x66,0x66,0x66,0x66,0x7E,0x66,0x66,0x66,0x66,0x00,0x00,0x00,0x00},/*"H",40*/

{0x00,0x00,0x00,0x3C,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x3C,0x00,0x00,0x00,0x00},/*"I",41*/

{0x00,0x00,0x00,0x06,0x06,0x06,0x06,0x06,0x06,0x66,0x66,0x3C,0x00,0x00,0x00,0x00},/*"J",42*/

{0x00,0x00,0x00,0x66,0x66,0x6C,0x6C,0x78,0x6C,0x6C,0x66,0x66,0x00,0x00,0x00,0x00},/*"K",43*/

{0x00,0x00,0x00,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x7E,0x00,0x00,0x00,0x00},/*"L",44*/

{0x00,0x00,0x00,0x63,0x63,0x77,0x6B,0x6B,0x6B,0x63,0x63,0x63,0x00,0x00,0x00,0x00},/*"M",45*/

{0x00,0x00,0x00,0x63,0x63,0x73,0x7B,0x6F,0x67,0x63,0x63,0x63,0x00,0x00,0x00,0x00},/*"N",46*/

{0x00,0x00,0x00,0x3C,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3C,0x00,0x00,0x00,0x00},/*"O",47*/

{0x00,0x00,0x00,0x7C,0x66,0x66,0x66,0x7C,0x60,0x60,0x60,0x60,0x00,0x00,0x00,0x00},/*"P",48*/

{0x00,0x00,0x00,0x3C,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3C,0x0C,0x06,0x00,0x00},/*"Q",49*/

{0x00,0x00,0x00,0x7C,0x66,0x66,0x66,0x7C,0x6C,0x66,0x66,0x66,0x00,0x00,0x00,0x00},/*"R",50*/

{0x00,0x00,0x00,0x3C,0x66,0x60,0x30,0x18,0x0C,0x06,0x66,0x3C,0x00,0x00,0x00,0x00},/*"S",51*/

{0x00,0x00,0x00,0x7E,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00,0x00},/*"T",52*/

{0x00,0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3C,0x00,0x00,0x00,0x00},/*"U",53*/

{0x00,0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3C,0x18,0x00,0x00,0x00,0x00},/*"V",54*/

{0x00,0x00,0x00,0x63,0x63,0x63,0x6B,0x6B,0x6B,0x36,0x36,0x36,0x00,0x00,0x00,0x00},/*"W",55*/

{0x00,0x00,0x00,0x66,0x66,0x34,0x18,0x18,0x2C,0x66,0x66,0x66,0x00,0x00,0x00,0x00},/*"X",56*/

{0x00,0x00,0x00,0x66,0x66,0x66,0x66,0x3C,0x18,0x18,0x18,0x18,0x00,0x00,0x00,0x00},/*"Y",57*/

{0x00,0x00,0x00,0x7E,0x06,0x06,0x0C,0x18,0x30,0x60,0x60,0x7E,0x00,0x00,0x00,0x00},/*"Z",58*/

{0x00,0x00,0x00,0x3C,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x3C,0x00},/*"[",59*/

{0x00,0x00,0x00,0x60,0x60,0x30,0x30,0x18,0x18,0x0C,0x0C,0x06,0x06,0x00,0x00,0x00},/*"\",60*/

{0x00,0x00,0x00,0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x3C,0x00},/*"]",61*/

{0x00,0x18,0x3C,0x66,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"^",62*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00},/*"_",63*/

{0x00,0x00,0x00,0x18,0x18,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"'",64*/

{0x00,0x00,0x00,0x00,0x00,0x3C,0x06,0x06,0x3E,0x66,0x66,0x3E,0x00,0x00,0x00,0x00},/*"a",65*/

{0x00,0x00,0x00,0x60,0x60,0x7C,0x66,0x66,0x66,0x66,0x66,0x7C,0x00,0x00,0x00,0x00},/*"b",66*/

{0x00,0x00,0x00,0x00,0x00,0x3C,0x66,0x60,0x60,0x60,0x66,0x3C,0x00,0x00,0x00,0x00},/*"c",67*/

{0x00,0x00,0x00,0x06,0x06,0x3E,0x66,0x66,0x66,0x66,0x66,0x3E,0x00,0x00,0x00,0x00},/*"d",68*/

{0x00,0x00,0x00,0x00,0x00,0x3C,0x66,0x66,0x7E,0x60,0x60,0x3C,0x00,0x00,0x00,0x00},/*"e",69*/

{0x00,0x00,0x00,0x1E,0x30,0x30,0x30,0x7E,0x30,0x30,0x30,0x30,0x00,0x00,0x00,0x00},/*"f",70*/

{0x00,0x00,0x00,0x00,0x00,0x3E,0x66,0x66,0x66,0x66,0x66,0x3E,0x06,0x06,0x7C,0x00},/*"g",71*/

{0x00,0x00,0x00,0x60,0x60,0x7C,0x66,0x66,0x66,0x66,0x66,0x66,0x00,0x00,0x00,0x00},/*"h",72*/

{0x00,0x00,0x18,0x18,0x00,0x78,0x18,0x18,0x18,0x18,0x18,0x7E,0x00,0x00,0x00,0x00},/*"i",73*/

{0x00,0x00,0x0C,0x0C,0x00,0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x78,0x00},/*"j",74*/

{0x00,0x00,0x00,0x60,0x60,0x66,0x66,0x6C,0x78,0x6C,0x66,0x66,0x00,0x00,0x00,0x00},/*"k",75*/

{0x00,0x00,0x00,0x78,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x7E,0x00,0x00,0x00,0x00},/*"l",76*/

{0x00,0x00,0x00,0x00,0x00,0x7E,0x6B,0x6B,0x6B,0x6B,0x6B,0x63,0x00,0x00,0x00,0x00},/*"m",77*/

{0x00,0x00,0x00,0x00,0x00,0x7C,0x66,0x66,0x66,0x66,0x66,0x66,0x00,0x00,0x00,0x00},/*"n",78*/

{0x00,0x00,0x00,0x00,0x00,0x3C,0x66,0x66,0x66,0x66,0x66,0x3C,0x00,0x00,0x00,0x00},/*"o",79*/

{0x00,0x00,0x00,0x00,0x00,0x7C,0x66,0x66,0x66,0x66,0x66,0x7C,0x60,0x60,0x60,0x00},/*"p",80*/

{0x00,0x00,0x00,0x00,0x00,0x3E,0x66,0x66,0x66,0x66,0x66,0x3E,0x06,0x06,0x06,0x00},/*"q",81*/

{0x00,0x00,0x00,0x00,0x00,0x66,0x6E,0x70,0x60,0x60,0x60,0x60,0x00,0x00,0x00,0x00},/*"r",82*/

{0x00,0x00,0x00,0x00,0x00,0x3E,0x60,0x60,0x3C,0x06,0x06,0x7C,0x00,0x00,0x00,0x00},/*"s",83*/

{0x00,0x00,0x00,0x30,0x30,0x7E,0x30,0x30,0x30,0x30,0x30,0x1E,0x00,0x00,0x00,0x00},/*"t",84*/

{0x00,0x00,0x00,0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x66,0x3E,0x00,0x00,0x00,0x00},/*"u",85*/

{0x00,0x00,0x00,0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x3C,0x18,0x00,0x00,0x00,0x00},/*"v",86*/

{0x00,0x00,0x00,0x00,0x00,0x63,0x6B,0x6B,0x6B,0x6B,0x36,0x36,0x00,0x00,0x00,0x00},/*"w",87*/

{0x00,0x00,0x00,0x00,0x00,0x66,0x66,0x3C,0x18,0x3C,0x66,0x66,0x00,0x00,0x00,0x00},/*"x",88*/

{0x00,0x00,0x00,0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x66,0x3C,0x0C,0x18,0xF0,0x00},/*"y",89*/

{0x00,0x00,0x00,0x00,0x00,0x7E,0x06,0x0C,0x18,0x30,0x60,0x7E,0x00,0x00,0x00,0x00},/*"z",90*/

{0x00,0x00,0x00,0x0C,0x18,0x18,0x18,0x30,0x60,0x30,0x18,0x18,0x18,0x0C,0x00,0x00},/*"{",91*/

{0x00,0x00,0x00,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00},/*"|",92*/

{0x00,0x00,0x00,0x30,0x18,0x18,0x18,0x0C,0x06,0x0C,0x18,0x18,0x18,0x30,0x00,0x00},/*"}",93*/

{0x00,0x00,0x00,0x71,0xDB,0x8E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"~",94*/
};

/* Private function prototypes -----------------------------------------------*/
void GetASCIICode(unsigned char* pBuffer, unsigned char ASCII, uint16_t FONTx);

#endif 