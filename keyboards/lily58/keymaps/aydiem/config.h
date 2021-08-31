/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

//#define USE_MATRIX_I2C

/* Select hand configuration */

//This allows for either side to be master when you flash with dfu-split-left & dfu-split-right
#define EE_HANDS

// #define SSD1306OLED

#define USE_SERIAL_PD2

//#define TAPPING_FORCE_HOLD
/* #undef PERMISSIVE_HOLD
#define PERMISSIVE_HOLD */
#define HOLD_ON_OTHER_KEY_PRESS
#define TAPPING_TERM 100
//#define TAPPING_TERM_PER_KEY

//combo configuration
#define COMBO_COUNT 3
#define COMBO_TERM 40

// Underglow
#undef RGBLED_NUM
#define RGBLED_NUM 10
#define RGBLIGHT_SPLIT
#define RGBLED_SPLIT { 5, 5 }
#define RGBLIGHT_LIMIT_VAL 255 //change this to higher number if not bright enough at max
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
// #define RGBLIGHT_SLEEP

// This sets up the encoder
#define ENCODERS_PAD_A { F4 }
#define ENCODERS_PAD_B { F5 }
#define ENCODER_RESOLUTION 4