#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _GAMING,
  _NUMP,
  _DOTA,
  _LOWER,
  _RAISE,
  _ADJUST,
};
  
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,---------------------------------------------------.                    ,------------------------------------------------.
 * |        | tilde |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  
 * |--------+-------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
 * |        | ESC   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   | Home |
 * |--------+-------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
 * |        | Tab   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   | End  |
 * |--------+-------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
 * |        | Caps  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   | Pgup |
 * |--------+-------+------+------+------+------+------| Mute  |    |Ply/Ps |------+------+------+------+------+------+------|
 * |        |LShift |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  Up  | Pgdn |
 * |---------------------------------------------------|       |    |       |------------------------------------------------|
 * |        |       |      |      | LGUI | LAlt |LCtrl | Enter |    | Bspace| Space| Del  |RCtrl | RGUI | Left | Down |Right |
 * |        |       |      |      |      |      |      | Lower |    | Raise |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------'    '--------------------------------------------------------'
 */
  [_QWERTY] = LAYOUT( \
  XXXXXXX,  KC_TILD,    KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5,                                             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  KC_P2,  KC_ESC,     KC_1,   KC_2,   KC_3,    KC_4,    KC_5,                                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_HOME, \
  KC_P3,  KC_TAB,     KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,                                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,  KC_END, \
  KC_P4,  KC_CAPS,    KC_A,   KC_S,   KC_D,    KC_F,    KC_G,                                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_PGUP, \
  KC_P5,  KC_LSFT,    KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,     KC_MUTE,               KC_MPLY,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_PGDN, \
  KC_P6,  KC_P7,      KC_P8,  KC_P9,  KC_LGUI, KC_LALT, KC_LCTRL, LT(_LOWER, KC_ENT), LT(_RAISE, KC_BSPC), KC_SPC,  KC_DEL,  KC_RCTRL,KC_RGUI, KC_LEFT, KC_DOWN, KC_RIGHT \
),
/* GAMING
 * ,---------------------------------------------------.                    ,------------------------------------------------.
 * | Gaming | tilde |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  
 * |--------+-------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
 * |        | ESC   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   | Home |
 * |--------+-------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
 * |        | Tab   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   | End  |
 * |--------+-------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
 * |        |Cps/Sft|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   | Pgup |
 * |--------+-------+------+------+------+------+------| Mute  |    |Ply/Ps |------+------+------+------+------+------+------|
 * |        |LShift |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  Up  | Pgdn |
 * |---------------------------------------------------|       |    |       |------------------------------------------------|
 * |        |       |      |      | LGUI | Space|LCtrl | Enter |    | Bspace| Space| Del  |RCtrl | RGUI | Left | Down |Right |
 * |        |       |      |      |      |      |      | Lower |    | Raise |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------'    '--------------------------------------------------------'
 */
  [_GAMING] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______,                                             _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______,                                             _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______,                                             _______, _______, _______, _______, _______, _______, _______, \
  KC_LCTRL,_______, _______, _______, _______, _______, _______,                                             _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______, _______, _______, \
  _______,KC_LCTRL, _______, _______, KC_LALT, KC_SPC , _______, _______,                           _______, _______, _______, _______, _______, _______, _______, _______ \
),
/* NUMPAD
 * ,---------------------------------------------------.                    ,------------------------------------------------.
 * |        | tilde |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  
 * |--------+-------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
 * |        | ESC   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   | Home |
 * |--------+-------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
 * |        | Tab   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   | End  |
 * |--------+-------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
 * |        |Cps/Sft|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   | Pgup |
 * |--------+-------+------+------+------+------+------| Mute  |    |Ply/Ps |------+------+------+------+------+------+------|
 * |        |LShift |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  Up  | Pgdn |
 * |---------------------------------------------------|       |    |       |------------------------------------------------|
 * |        |       |      |      | LGUI | LAlt |LCtrl | Enter |    | Bspace| Space| Del  |RCtrl | RGUI | Left | Down |Right |
 * |        |       |      |      |      |      |      | Lower |    | Raise |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------'    '--------------------------------------------------------'
 */
  [_NUMP] = LAYOUT( \
  _______,  KC_TILD,    KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5,                                             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______,  KC_ESC,     KC_1,   KC_2,   KC_3,    KC_4,    KC_5,                                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_HOME, \
  _______,  KC_TAB,     KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,                                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,  KC_END, \
  _______,  KC_CAPS,    KC_A,   KC_S,   KC_D,    KC_F,    KC_G,                                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_PGUP, \
  _______,  KC_LSFT,    KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,     KC_MUTE,               KC_MPLY,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_PGDN, \
  _______,  _______,    _______,_______,KC_LGUI, KC_LALT, KC_LCTRL, LT(_LOWER, KC_ENT), LT(_RAISE, KC_BSPC), KC_SPC,  KC_DEL,  KC_RCTRL,KC_RGUI, KC_LEFT, KC_DOWN, KC_RIGHT \
),
/* LOWER
 * ,---------------------------------------------------.                    ,------------------------------------------------.
 * |        | tilde |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  
 * |--------+-------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
 * |        | ESC   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   | Home |
 * |--------+-------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
 * |        | Tab   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   | End  |
 * |--------+-------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
 * |        |Cps/Sft|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   | Pgup |
 * |--------+-------+------+------+------+------+------| Mute  |    |Ply/Ps |------+------+------+------+------+------+------|
 * |        |LShift |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  Up  | Pgdn |
 * |---------------------------------------------------|       |    |       |------------------------------------------------|
 * |        |       |      |      | LGUI | LAlt |LCtrl | Enter |    | Bspace| Space| Del  |RCtrl | RGUI | Left | Down |Right |
 * |        |       |      |      |      |      |      | Lower |    | Raise |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------'    '--------------------------------------------------------'
 */

  [_LOWER] = LAYOUT( \
  _______,  KC_TILD,    KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5,                   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  XXXXXXX, _______, _______, _______, _______, _______, _______,                   _______, _______,   _______,   _______,   _______,   _______,  _______, \
  _______,KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_MINS, KC_PLUS, KC_EQL,  KC_LCBR, KC_RCBR, KC_PIPE, _______, \
  _______,KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, _______, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, _______, XXXXXXX, KC_UNDS, XXXXXXX, KC_LBRC, KC_RBRC, _______, _______, _______,\
  _______,  _______,    _______,_______,KC_LGUI, KC_LALT, KC_LCTRL, LT(_LOWER, KC_ENT), LT(_RAISE, KC_BSPC), KC_SPC,  KC_DEL,  KC_RCTRL,KC_RGUI, KC_LEFT, KC_DOWN, KC_RIGHT \
),
/* RAISE
 * ,---------------------------------------------------.                    ,------------------------------------------------.
 * |        | tilde |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  
 * |--------+-------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
 * |        | ESC   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   | Home |
 * |--------+-------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
 * |        | Tab   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   | End  |
 * |--------+-------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
 * |        |Cps/Sft|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   | Pgup |
 * |--------+-------+------+------+------+------+------| Mute  |    |Ply/Ps |------+------+------+------+------+------+------|
 * |        |LShift |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  Up  | Pgdn |
 * |---------------------------------------------------|       |    |       |------------------------------------------------|
 * |        |       |      |      | LGUI | LAlt |LCtrl | Enter |    | Bspace| Space| Del  |RCtrl | RGUI | Left | Down |Right |
 * |        |       |      |      |      |      |      | Lower |    | Raise |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------'    '--------------------------------------------------------'
 */
  [_RAISE] = LAYOUT( \
  _______,  KC_TILD,    KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5,                                             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______,  KC_ESC,     KC_1,   KC_2,   KC_3,    KC_4,    KC_5,                                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_HOME, \
  _______,  KC_TAB,     KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,                                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,  KC_END, \
  _______,  KC_CAPS,    KC_A,   KC_S,   KC_D,    KC_F,    KC_G,                                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_PGUP, \
  _______,  KC_LSFT,    KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,     KC_MUTE,               KC_MPLY,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_PGDN, \
  _______,  _______,    _______,_______,KC_LGUI, KC_LALT, KC_LCTRL, LT(_LOWER, KC_ENT), LT(_RAISE, KC_BSPC), KC_SPC,  KC_DEL,  KC_RCTRL,KC_RGUI, KC_LEFT, KC_DOWN, KC_RIGHT \
),
/* ADJUST
 * ,---------------------------------------------------.                    ,------------------------------------------------.
 * |        |       |      |      |      |      |      |                    |      |      |      |      |      |      |RESET |  
 * |--------+-------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
 * |        |       |      |      |      |      |      |                    |      |      |      |      |      |      |      |
 * |--------+-------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
 * |        |       |      |      |      |      |      |                    |      |      |      |      |      |      |      |
 * |--------+-------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
 * |        |       |      |      | DOTA |      |GAMING|-------.    ,-------|      | NUMP |      |      |      |      |      |
 * |--------+-------+------+------+------+------+------|       |    |       |------+------+------+------+------+------+------|
 * |        |       |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |      |
 * |---------------------------------------------------|       |    |       |------------------------------------------------|
 * |        |       |      |      |      |      |      |       |    |       |      |      |      |      |      |      |      |
 * |        |       |      |      |      |      |      |       |    |       |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------'    '--------------------------------------------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,TG(_DOTA),XXXXXXX, TG(_GAMING),                 XXXXXXX,TG(_NUMP),XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
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
        case LSFT_T(KC_CAPS):
          return 200;
          break;
        default:
          return TAPPING_TERM;
          break;
    }
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

/*

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_logo(void);


// Custom OLED Logo
 static void render_logo(void) {
  static const char PROGMEM my_logo[] = {
    
  };
  oled_write_raw_P(my_logo, sizeof(my_logo));
} 

*/

// Add layer names as cases here to have them displayed on OLED
const char *read_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY: 
          return "Layer: QWERTY";
          break;
        case _GAMING: 
          return "Layer: Gaming";
          break;
        case _NUMP: 
          return "Layer: Numpad";
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
    oled_write_ln(read_layer_state(), false);

    //write the state of capslock and scroll lock
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_ln_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPSLOCK ON") : PSTR(""), false);
    oled_write_ln_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCROLL LOCK ON") : PSTR(""), false);

}
#endif // OLED_DRIVER_ENABLE

// This block runs as the last step of initializing the keyboard.
void keyboard_post_init_user(void) {
}

// This section defines combo key functionality
enum combos {
  JL_ENT,
  JK_RSFT,
  DF_LSFT
};

const uint16_t PROGMEM jl_combo[] = {KC_L, KC_J, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [JK_RSFT] = COMBO(jk_combo, KC_RSFT),
  [JL_ENT] = COMBO(jl_combo, KC_ENT),
  [DF_LSFT] = COMBO(df_combo, KC_LSFT)
};


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
      case _RAISE://next track and previous track (press is play/pause) 
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
  } else {
    if (clockwise) { 
      tap_code(KC_1); 
    } else { 
      tap_code(KC_0); 
    }
  } 
}

//Everything here runs whenever a layer state is changed
layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  switch (get_highest_layer(state)) {
    case _GAMING:
      combo_disable()
      break;
    case _DOTA:
      combo_disable()
      break;
    case _NUMP:
        break;
    case _LOWER:
        break;
    case _RAISE:
        break;
    case _ADJUST:
        break;
    default:
      combo_enable()
        break;
    }
  return state;
}
