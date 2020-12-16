/* Copyright 2018 Jack Humbert
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

#include QMK_KEYBOARD_H

enum layer_number {
_BASE = 0,
_GAME,
_NUMP,
_FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT(
		KC_HOME, KC_DEL,     KC_PGUP,
		KC_END,  KC_UP,      KC_PGDN,
		KC_LEFT, KC_DOWN,    KC_RIGHT,
		MO(_FN), C(KC_PGUP), C(KC_PGDN)
	),
  
  [_GAME] = LAYOUT(
		S(C(KC_TAB)), KC_DEL,       S(KC_F12),
		KC_END,       KC_UP,        KC_PGDN,
		KC_LEFT,      KC_DOWN,      KC_RIGHT,
		MO(_FN),      MEH(KC_QUOT), MEH(KC_SCLN)
	),

  [_NUMP] = LAYOUT(
		KC_7, KC_8, KC_9,
		KC_4, KC_5, KC_6,
		KC_1, KC_2, KC_3,
		MO(_FN), KC_0, KC_DOT
	),
  
	[_FN] = LAYOUT(
		RGB_TOG, RGB_MOD, RGB_M_P,
		RGB_HUI, RGB_SAI, RGB_VAI,
		RGB_HUD, RGB_SAD, RGB_VAD,
		_______, A(KC_F4),TG(_NUMP)
	)
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
}

void oled_task_user(void) {
  switch (get_highest_layer(layer_state)) {
    case _BASE:
      oled_write_ln_P(PSTR(""), false);
      break;
    case _FN:
      oled_write_ln_P(PSTR("FN"), false);
      break;
    case _GAME:
      oled_write_ln_P(PSTR("GAME MODE"), false);
      break;
    case _NUMP:
      oled_write_ln_P(PSTR("NUM  PAD"), false);
      break;
    default:
      // Or use the write_ln shortcut over adding '\n' to the end of your string
      oled_write_ln_P(PSTR("Undef"), false);
  }

  // Host Keyboard LED Status
  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NLCK ") : PSTR("     "), false);
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPS ") : PSTR("       "), false);
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLK") : PSTR("       "), false);
}
#endif


void encoder_update_user(uint8_t index, bool clockwise) { 
  if (index == 0) {
    switch(get_highest_layer(layer_state)) {
      case _BASE:
        if (clockwise) { 
          tap_code16(C(KC_Y)); 
        } else { 
          tap_code16(C(KC_Z)); 
        }
        break;
      case _NUMP:
        if (clockwise) { 
          tap_code(KC_DEL); 
        } else { 
          tap_code(KC_BSPC); 
        }
        break;
      case _FN:
        if (clockwise) { 
          if (IS_LAYER_OFF(_GAME)) {
            layer_on(_GAME);
          } else if (IS_LAYER_OFF(_NUMP)) {
            layer_on(_NUMP);
          }
        } else { 
          if (IS_LAYER_ON(_NUMP)) {
            layer_off(_NUMP);
          } else if (IS_LAYER_ON(_GAME)) {
            layer_off(_GAME);
          } 
        }
        break;
      default:
        if (clockwise) { 
          tap_code(KC_VOLU); 
        } else { 
          tap_code(KC_VOLD); 
        }
        break;
    }         
  } 
}