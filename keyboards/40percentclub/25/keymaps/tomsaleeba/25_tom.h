#pragma once

#define LAYOUT_ortho_25_2move( \
	L00, L01, L02, L03, L04,           R00, R01, R02, R03, R04, \
	L10, L11, L12, L13, L14,           R10, R11, R12, R13, R14, \
	L20, L21, L22, L23, L24,           R20, R21, R22, R23, R24, \
	L30, L31, L32, L33, L34, L40, R44, R30, R31, R32, R33, R34, \
	          L42, L43, L44, L41, R43, R40, R41, R42            \
) { \
	{ L00, L01, L02, L03, L04 }, \
	{ L10, L11, L12, L13, L14 }, \
	{ L20, L21, L22, L23, L24 }, \
	{ L30, L31, L32, L33, L34 }, \
	{ L40, L41, L42, L43, L44 }, \
	{ R04, R03, R02, R01, R00 }, \
	{ R14, R13, R12, R11, R10 }, \
	{ R24, R23, R22, R21, R20 }, \
	{ R34, R33, R32, R31, R30 }, \
	{ R44, R43, R42, R41, R40 }  \
}

#define LAYOUT_25_2move_wrapper(...)  LAYOUT_ortho_25_2move(__VA_ARGS__)
