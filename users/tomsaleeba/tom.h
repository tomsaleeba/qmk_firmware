/* Copyright 2018 Tom Saleeba
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

 
#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

// A 'transparent' key code (that falls back to the layers below it).
#define ___ KC_TRANSPARENT

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VRSN,
};

#define BASE 0
#define MDIA 1
#define NUMB 2
#define MOUS 3
#define BRKT 4

#define MED_ESC LT(MDIA, KC_ESC)
#define GUI_ENT RGUI_T(KC_ENT)
#define MSE_CLN LT(MOUS, KC_SCLN)
#define BRK_SLS LT(BRKT, KC_SLSH)

#endif
