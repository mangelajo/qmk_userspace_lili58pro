#include QMK_KEYBOARD_H
#include <stdio.h>

#include "i18n.h"

#define SPLIT_WPM_ENABLE

//uint8_t get_current_wpm(void);


enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

// tap dance is used to program keys that have different functions when tapped once or twice (quickly)
// tap dance examples : https://docs.qmk.fm/features/tap_dance#simple-example
enum {
    TD_COPY_PASTE, // tap once for copy, twice for paste
    TD_ESC_LOCK, // tap once for ESC, twice for lock screen on Mac OS
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for System Lock
      [TD_COPY_PASTE] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_C), LGUI(KC_V)),
      [TD_ESC_LOCK] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, LCTL(LGUI(KC_Q))),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |ESC+L |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   q  |   w  |   e  |   r  |   t  |                    |   y  |   u  |   i  |   o  |   p  |  +   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   a  |   s  |   d  |   f  |   g  |-------.    ,-------|   h  |   j  |   k  |   l  |   ñ  |  ´   |
 * |------+------+------+------+------+------|  C&P  |    | BackSP|------+------+------+------+------+------|
 * |LShift|   z  |   x  |   c  |   v  |   b  |-------|    |-------|   n  |   m  |   ;  |   .  |  -   |RShift
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Space \  |RAISE |RAlt RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  TD(TD_ESC_LOCK),KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    ES_GRV,
  KC_TAB,         KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    ES_PLUS,
  KC_LCTL,        KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,        KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, TD(TD_COPY_PASTE),       KC_BSPC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                          KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,                    KC_SPC, MO(_RAISE), KC_LALT, KC_RGUI
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |  [   |   ]  |  ¿   |  ?   |      | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   º  |      |      |      |      |-------.    ,-------|  {   |   }  |      |      |      |  '   |
 * |------+------+------+------+------+------|  C&P  |    | Bkspc |------+------+------+------+------+------|
 * |      |   ª  |      |      |      |      |-------|    |-------|  <   |  >   |      |   ^  |   *  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE | RAlt | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______  , KC_F1    ,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  _______  , _______  , _______, _______, _______, _______,                    ES_LBRC, ES_RBRC, KC_PLUS, KC_UNDS, _______,  KC_F12,
  _______  , KC_GRV   , _______, _______, _______, _______,                    ES_LCBR, ES_RCBR, _______, _______, _______, ES_APOS,
  _______  , S(KC_GRV), _______, _______, _______, _______, _______, _______,  ES_LESS, ES_GRTR, _______, KC_LCBR, KC_RCBR, ES_PIPE,
                                _______, _______, _______, _______, KC_ENT ,  _______, _______, _______
),


/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  ¡   |      |      |      |      |                    |      |  \   |      |      |      |  ?   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | Stop | Vol+ | Play |                    |      | PgUp |  Up  | PgDn |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | P.Trk| Vol- | N.Trk|-------.    ,-------| <<<  | Left | Down | Right| >>>  |      |
 * |------+------+------+------+------+------|  C&P  |    | Bkspc |------+------+------+------+------+------|
 * |      |      |      |      | Mute |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Bkspc  /       \Space \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, ES_IEXL, _______, _______, _______, _______,                     _______, ES_BSLS,  _______, _______, _______, KC_UNDS,
  _______, _______, _______, KC_MSTP, KC_VOLU, KC_MPLY,                     _______,KC_PAGE_UP,  KC_UP, KC_PGDN, _______, _______,
  _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT,                     C(KC_A), KC_LEFT,  KC_DOWN, KC_RGHT, C(KC_E), _______,
  _______, _______, _______, _______, KC_MUTE, _______,  _______, _______,  _______, _______,  _______, _______, _______, _______,
                             _______, _______, _______,  KC_BSPC, _______,  _______, _______,  _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Space \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return OLED_ROTATION_270;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
void set_timelog(void);
const char *read_timelog(void);

const char *read_wpm(void) {
  static char wpm_str[16] = {};
  snprintf(wpm_str, sizeof(wpm_str), "WPM: %3d", get_current_wpm());
  return wpm_str;
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln("\n", false);
    oled_write_ln(read_wpm(), false);
    oled_write_ln("\n", false);
    oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    oled_write_ln("      ", false);
  } else {
    oled_write(read_logo(), false);
  }
  return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
    // set_timelog();
  }
  return true;
}
