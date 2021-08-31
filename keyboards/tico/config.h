/*
Copyright 2021 Aydiem

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x6589  //ascii values of 'AY'
#define PRODUCT_ID      0x8467  //ascii values of 'TC'
#define DEVICE_VER      0x0001
#define MANUFACTURER    Aydiem
#define PRODUCT         TiCo
#define DESCRIPTION     6x14 + 2 keys + 2 encoders, tilted columnar-staggered tenkeyless keyboard.

/* key matrix size */
#define MATRIX_ROWS 11
#define MATRIX_COLS 8

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
*/
#define MATRIX_ROW_PINS { F7, D7, B1, E6, B3, B4, B2, B5, B6, B7, F0 }
#define MATRIX_COL_PINS { D3, D2, D4, C6, F6, F5, F4, B0 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

//defines how dual purpose (tap-hold) keys will behave
#define HOLD_ON_OTHER_KEY_PRESS
#define TAPPING_TERM 100


//combo configuration
#define COMBO_COUNT 3
#define COMBO_TERM 40

// This sets up the encoders
#define ENCODERS_PAD_A { F1, D5 }
#define ENCODERS_PAD_B { C7, C7 }
#define ENCODER_RESOLUTION 4