/* Copyright 2019 Chip
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT_UltiPad( \
	K00, K01, K02, K03,           \
	K10, K11, K12, K13, K14,      \
	K20, K21, K22,                \
	K30, K31, K32, K33,           \
	K40, K41, K42,                \
	     K51, K52, K53, K54, K55  \
) { \
	{ K00,   K01,   K02,   K03,   KC_NO, KC_NO }, \
	{ K10,   K11,   K12,   K13,   K14,   KC_NO }, \
	{ K20,   K21,   K22,   KC_NO, KC_NO, KC_NO }, \
	{ K30,   K31,   K32,   K33,   KC_NO, KC_NO }, \
	{ K40,   K41,   K42,   KC_NO, KC_NO, KC_NO }, \
	{ KC_NO, K51,   K52,   K53,   K54,   K55 }  \
}

//#define LAYOUT_UltiPad LAYOUT_10Key


































