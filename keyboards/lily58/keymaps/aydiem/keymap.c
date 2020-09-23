#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern uint8_t is_master;

enum layer_number {
  _QWERTY = 0,
  _GAMING,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |CAPS/CTL| A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |  Play/Pause|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/ Enter /     \ BSPC  \-----------------------------------------'
 *                   | LGUI | LAlt |LCTRL | /LOWER  /       \RAISE \  |Space |Delete| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

  [_QWERTY] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL, \
  LCTL_T(KC_CAPS),  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,   KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
              KC_LGUI, KC_LALT, KC_LCTRL, LT(_LOWER, KC_ENT), LT(_RAISE, KC_BSPC), KC_SPC, KC_DEL, KC_RGUI \
),
/* GAMING
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |CAPS  |  A   |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |  Play/Pause|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/ Enter /     \ BSPC \-----------------------------------------'
 *                   | LCTRL| LAlt |Space | /LOWER  /       \RAISE \  |Space |Delete| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_GAMING] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  KC_CAPS, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                            KC_LCTRL, KC_LALT, KC_SPC, _______, _______, _______, _______, _______ \
),
/* LOWER
 * ,-----------------------------------------.                     ,-----------------------------------------.
 * |      |      |      |      |      |      |                     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                     |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.     ,-------|   ^  |   &  |   *  |   (  |   )  |   ~  |
 * |------+------+------+------+------+------|Play/Pause Play/Pause|------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|     |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/ Enter /      \ BSPC \-----------------------------------------'
 *                   | LGUI | LAlt |LCTRL | /LOWER  /        \RAISE \  |Space |Delete| RGUI |
 *                   |      |      |      |/       /          \      \ |      |      |      |
 *                   `----------------------------'            '------''--------------------'
 */

  [_LOWER] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
                             _______, _______, _______, _______, _______,  _______, _______, _______\
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | Home | PgUp |      |-------.    .-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|Play/Pause Ply/Pause|------+------+------+------+------+------|
 * |LShift|Insert|      | End  | PgDn |      |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/ Enter /     \ BSPC \-----------------------------------------'
 *                   | LGUI | LAlt |LCTRL | /LOWER  /       \RAISE \  |Space |Delete| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_RAISE] = LAYOUT( \
  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                          KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGUP, XXXXXXX,                     XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, \
  _______,  KC_INS, XXXXXXX, KC_END, KC_PGDN, XXXXXXX,  KC_MPLY, _______,  KC_PLUS, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, \
                             _______, _______, _______,  _______, _______,  _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |RESET |      |      |      |      |      |                    |      |      |      |PrintS|ScrLck| Pause|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |GAMING|-------.    ,-------|RGB ON| MODE+| HUE+ | SAT+ | VAL+ |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LSHIFT|      |      |      |      |      |-------|    |-------|      | MODE-| HUE- | SAT- | VAL- |RSHIFT|
 * `-----------------------------------------/ Enter /     \ BSPC \-----------------------------------------'
 *                   | LGUI | LAlt |LCTRL | /LOWER  /       \RAISE \  |Space |Delete| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
  RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUSE, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_GAMING),               RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, \
  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_RSFT,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

// set per key tapping terms here
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_CAPS):
            return 200;
        default:
            return TAPPING_TERM;
    }
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_logo(void);

// const char *read_host_led_state(void);

// Custom OLED Logo
static void render_logo(void) {
  static const char PROGMEM my_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 
    0xe0, 0xe0, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0x60, 0x20, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0x60, 
    0x20, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0x60, 0x20, 0x00, 0x00, 0x00, 0x80, 0xc0, 
    0xe0, 0xe0, 0xe0, 0x60, 0x20, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0x60, 0x20, 0x00, 
    0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xe0, 0xfc, 0xff, 0xff, 0xff, 0x8f, 
    0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xc1, 0xf9, 0xff, 0xff, 
    0xff, 0xff, 0x1f, 0x03, 0xc0, 0xe0, 0x70, 0xf8, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0x1f, 0x00, 0x00, 
    0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0x7c, 0x3e, 0x1f, 
    0x0f, 0x07, 0x83, 0xc1, 0xe0, 0xf0, 0xf8, 0x7c, 0x3e, 0x1f, 0x0f, 0x07, 0x83, 0xc1, 0xe0, 0xf0, 
    0xf8, 0x7c, 0x3e, 0x1f, 0x0f, 0x07, 0x83, 0xc1, 0xe0, 0xf0, 0xf8, 0x7c, 0x3e, 0x1f, 0x0f, 0x07, 
    0x83, 0xc1, 0xe0, 0xf0, 0xf8, 0x7c, 0x3e, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x04, 0x07, 0x07, 0x07, 0x07, 0x07, 0xc7, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x07, 0x07, 0x07, 
    0x07, 0x07, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xfe, 0xff, 0xff, 0xff, 0x7f, 
    0x3f, 0x1c, 0x0e, 0x07, 0x01, 0xe0, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x38, 0x1c, 0x0e, 0xc7, 
    0xfb, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0x7c, 0x3e, 0x1f, 0x0f, 0x07, 0x83, 0xc1, 0xe0, 0xf0, 0xf8, 0x7c, 
    0x3e, 0x1f, 0x0f, 0x07, 0x83, 0xc1, 0xe0, 0xf0, 0xf8, 0x7c, 0x3e, 0x1f, 0x0f, 0x07, 0x83, 0xc1, 
    0xe0, 0xf0, 0xf8, 0x7c, 0x3e, 0x1f, 0x0f, 0x07, 0x83, 0xc1, 0xe0, 0xf0, 0xf8, 0x7c, 0x3e, 0x1f, 
    0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0f, 0x0f, 0x0f, 0x07, 0x03, 0x01, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0f, 
    0x0f, 0x0f, 0x0f, 0x0f, 0x0e, 0x0e, 0x0e, 0x0e, 0x06, 0x06, 0x02, 0x00, 0x08, 0x0c, 0x0e, 0x0f, 
    0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x08, 0x0c, 0x0e, 0x0f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 
    0x08, 0x0c, 0x0e, 0x0f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x08, 0x0c, 0x0e, 0x0f, 0x0f, 0x07, 
    0x03, 0x01, 0x00, 0x00, 0x08, 0x0c, 0x0e, 0x0f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };
  oled_write_raw_P(my_logo, sizeof(my_logo));
}

// Add layer names as cases here to have them displayed on OLED
const char *read_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY: 
          return "Layer: QWERTY";
          break;
        case _GAMING: 
          return "Layer: Gaming";
          break;
        case _LOWER: 
          return "Layer: Lower";
          break;
        case _RAISE: 
          return "Layer: Raise";
          break;
        case _ADJUST: 
          return "Layer: Adjust";
          break;
        default: 
          return "Unknown";
          break;
    }
}

// If you want to change the display of OLED, you need to change here
void oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_write_ln(read_layer_state(), false);

    //write the state of capslock and scroll lock
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_ln_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPSLOCK ON") : PSTR(""), false);
    oled_write_ln_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCROLL LOCK ON") : PSTR(""), false);

  } else {
    //oled_write(read_logo(), false);
    render_logo();
  }
}
#endif // OLED_DRIVER_ENABLE

// This block runs as the last step of initializing the keyboard.
void keyboard_post_init_user(void) {
  rgblight_sethsv_noeeprom(20, 255, 255);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    //set oled on-key press stuff here
#endif
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) { 
  if (index == 0) {
    switch(get_highest_layer(layer_state)) {
      case _RAISE://next track and previous track (press is play/pause) **MAYBE change this to RAISE
        if (clockwise) { 
          tap_code(KC_MNXT); 
        } else { 
          tap_code(KC_MPRV); 
        }
        break;
      default://volume up and down (press is mute)
        if (clockwise) { 
          tap_code(KC_VOLU); 
        } else { 
          tap_code(KC_VOLD); 
        }
        break;
    }         
  } 
}

//Everything here runs whenever a layer state is changed
layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  switch (get_highest_layer(state)) {
    case _GAMING:
        rgblight_sethsv_noeeprom(HSV_RED);
        break;
    case _LOWER:
        rgblight_sethsv_noeeprom(HSV_GREEN);
        break;
    case _RAISE:
        rgblight_sethsv_noeeprom(HSV_CYAN);
        break;
    case _ADJUST:
        rgblight_sethsv_noeeprom(HSV_PURPLE);
        break;
    default:
        rgblight_sethsv_noeeprom(20, 255, 255);
        break;
    }
  return state;

}