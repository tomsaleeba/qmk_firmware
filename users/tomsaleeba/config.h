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

#pragma once

// Sets good default for the speed of the mouse.
#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_DELAY
#undef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_MAX_SPEED

#define MOUSEKEY_INTERVAL       16
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    40
#define MOUSEKEY_MAX_SPEED      7

#undef MOUSEKEY_WHEEL_MAX_SPEED
#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#undef MOUSEKEY_WHEEL_DELAY

#define MOUSEKEY_WHEEL_MAX_SPEED    8
#define MOUSEKEY_WHEEL_TIME_TO_MAX  8
#define MOUSEKEY_WHEEL_DELAY        2

#undef LEADER_TIMEOUT
#define LEADER_TIMEOUT 300

#undef TAPPING_TERM
#define TAPPING_TERM    200

#define COMBO_COUNT 25
#undef COMBO_TERM
#define COMBO_TERM 13 // milliseconds

#undef TAPPING_TERM_PER_KEY
// https://github.com/qmk/qmk_firmware/blob/master/docs/custom_quantum_functions.md#custom-tapping-term
#define TAPPING_TERM_PER_KEY

#define UNICODE_SELECTED_MODES UC_LNX

// get pin names from https://docs.qmk.fm/#/easy_maker?id=direct-pin
#define UD_PIN         B5
#define LR_PIN         B6
