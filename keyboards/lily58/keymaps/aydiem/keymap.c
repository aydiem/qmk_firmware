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
  _NUMP,
  _NAV,
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
 *                   | LGUI |Delete|LCTRL | /LOWER  /       \RAISE \  |Space |Delete| RGUI |
 *                   |      | LAlt |      |/       /         \      \ |      |RCTRL |      |
 *                   `----------------------------'           '------''--------------------'
 */

  [_QWERTY] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL, \
  LCTL_T(KC_CAPS),  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,   KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
         KC_LGUI, LALT_T(KC_DEL), KC_LCTRL, LT(_LOWER, KC_ENT), LT(_RAISE, KC_BSPC), KC_SPC, RCTL_T(KC_DEL), KC_RGUI \
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
 *                   |      |      |      |/       /         \      \ |      |RCTRL |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_GAMING] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  KC_CAPS, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                            KC_LCTRL, KC_LALT, KC_SPC, _______, _______, _______, _______, _______ \
),
/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |      |      |      |      | NUMP |                    |  DEL |      |   /  |   *  |  -   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Tab |      |      |      |      |      |                    |      |   7  |   8  |   9  |  -   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|   (  |   4  |   5  |   6  |  +   |   )  |
 * |------+------+------+------+------+------|  MUTE |    |Ply/Pau|------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   1  |   2  |   3  |Enter |      |
 * `-----------------------------------------/ Space /     \ BSPC \-----------------------------------------'
 *                   | LGUI |Delete|LCTRL | /LOWER  /       \RAISE \  |   0  |   .  | RGUI |
 *                   |      | LAlt |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_NUMP] = LAYOUT( \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_NUMP),                 KC_DEL,  XXXXXXX, KC_SLSH, KC_ASTR, KC_MINS, XXXXXXX, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_7,    KC_8,    KC_9,    KC_MINS, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_LPRN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_RPRN, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_ENT,  XXXXXXX, \
         KC_LGUI, LALT_T(KC_DEL), KC_LCTRL, LT(_LOWER, KC_SPC), LT(_RAISE, KC_BSPC), KC_0, KC_DOT, KC_RGUI \
),
/* NAVIGATION
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |      |      |      |      | NAV  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Tab |      |      |      |      |      |                    | Redo | PgUp |  UP  | Home |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |LSHIFT|LCTRL |      |-------.    ,-------|      | LEFT | DOWN | RIGHT|      |      |
 * |------+------+------+------+------+------| MUTE  |    |Ply/Pau|------+------+------+------+------+------|
 * |      | Undo |  Cut | Copy |Paste |      |-------|    |-------|      | PgDn |      | End  |      |      |
 * `-----------------------------------------/ Space /     \ BSPC \-----------------------------------------'
 *                   | LGUI |Delete|LCTRL | /LOWER  /       \RAISE \  |Space |Delete| RGUI |
 *                   |      | LAlt |      |/       /         \      \ |      |RCTRL |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_NAV] = LAYOUT( \
  _______, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    TG(_NAV),                  KC_DEL,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,                   LCTL(KC_Y), KC_PGUP, KC_UP,   KC_HOME, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX,   XXXXXXX,   KC_LSFT,   KC_LCTRL,   XXXXXXX,                   XXXXXXX,    KC_LEFT, KC_DOWN, KC_RIGHT,XXXXXXX, XXXXXXX, \
  XXXXXXX, LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_V), XXXXXXX, _______, _______, XXXXXXX,    KC_PGDN, XXXXXXX, KC_END,  XXXXXXX, XXXXXXX, \
         KC_LGUI, LALT_T(KC_DEL), KC_LCTRL, LT(_LOWER, KC_ENT), LT(_RAISE, KC_BSPC), KC_SPC, RCTL_T(KC_DEL), KC_RGUI \
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
 *                   | LGUI |Delete|LCTRL | /LOWER  /        \RAISE \  |Space |Delete| RGUI |
 *                   |      | LAlt |      |/       /          \      \ |      |RCTRL |      |
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
 *                   | LGUI |Delete|LCTRL | /LOWER  /       \RAISE \  |Space |Delete| RGUI |
 *                   |      | LAlt |      |/       /         \      \ |      |RCTRL |      |
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
 * |CSDEL |      |      |      |AltF4 |      |                    |      |      |      |PrintS|ScrLck| Pause|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |CADEL |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      | NUMP |GAMING|-------.    ,-------|      | NAV  |      |      |      |      |
 * |------+------+------+------+------+------|       |    |RESET  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |RGB ON|
 * `-----------------------------------------/ Enter /     \ BSPC \-----------------------------------------'
 *                   | LGUI |Delete|LCTRL | /LOWER  /       \RAISE \  |Space |Delete| RGUI |
 *                   |      | LAlt |      |/       /         \      \ |      |RCTRL |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
  C(S(KC_DEL)), XXXXXXX, XXXXXXX, XXXXXXX, A(KC_F4),   XXXXXXX,                 XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUSE, \
  C(A(KC_DEL)), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, TG(_NUMP), TG(_GAMING),             XXXXXXX, TG(_NAV),XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,\
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
    0x00, 0x00, 0x00, 0xf8, 0x08, 0x08, 0xf8, 0x00, 0x00, 0xf8, 0x08, 0x08, 0xf8, 0x00, 0x00, 0xf8, 
    0x08, 0x08, 0xf8, 0x00, 0x00, 0xf8, 0x08, 0x08, 0xc8, 0xc8, 0x08, 0x08, 0xf8, 0x00, 0x00, 0xf8, 
    0x08, 0x08, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 
    0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x08, 0x08, 
    0xf8, 0x00, 0x00, 0x78, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 
    0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0xc8, 0x08, 0x08, 0xf8, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 
    0x00, 0x00, 0x3f, 0x20, 0x20, 0x27, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0xe7, 0x00, 0x00, 0xff, 
    0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 
    0xe0, 0x30, 0x18, 0x0c, 0x06, 0x03, 0x01, 0x00, 0xf8, 0x0c, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x0c, 0xf8, 0x00, 0xc3, 0xc7, 0xcf, 0xdb, 0xf3, 0xe3, 0xc3, 
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 
    0xff, 0x00, 0x00, 0x9e, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 
    0x92, 0x12, 0x12, 0xf2, 0x02, 0x02, 0xfe, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0x7f, 0x40, 0x40, 0x4f, 0x48, 0x48, 0x49, 
    0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x79, 0x00, 0x00, 0xff, 
    0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xd8, 0xcc, 0xc6, 0xc3, 0xc1, 0xc0, 
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xff, 0x00, 0xc3, 0xc7, 0xcd, 0xd9, 0xf1, 0xe1, 0xc1, 
    0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0xc1, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 
    0xff, 0x00, 0x00, 0xe7, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0xe4, 0x04, 0x04, 0xfc, 0x00, 0x00, 
    0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x13, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 
    0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x00, 0x00, 0x1f, 
    0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 
    0x1f, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x13, 0x13, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x1f, 0x10, 0x10, 
    0x1f, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00
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
        case _NUMP: 
          return "Layer: Numpad";
          break;
        case _NAV: 
          return "Layer: Navigation";
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
    case _NUMP:
        rgblight_sethsv_noeeprom(HSV_PINK);
        break;
    case _NAV:
        rgblight_sethsv_noeeprom(HSV_BLUE);
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