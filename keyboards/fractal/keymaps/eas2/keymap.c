/* Copyright 2015-2017 Jack Humbert
 * Modified by KeyPCB for the Fractal keyboard
 * Backlight isn't on the Fractal, so I've removed the keycode from the keymaps
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

enum preonic_layers {
  _QWERTY,
  _ME,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  ME,
  LOWER,
  RAISE,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | GRV  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | \    |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |MOrais| Ctrl | Alt  | CMD  | MOme |    Space    |MOlwr |  CMD | Alt  | Ctrl |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_5x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,  \
  MT(MOD_LCTL,KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT)	,  \
  MO(_RAISE), KC_LCTL, KC_LALT, KC_LGUI,   MO(_ME), KC_SPC,  LT(_RAISE,KC_SPC),  MO(_LOWER),   KC_LGUI, KC_RALT, KC_LCTL,   KC_ENT  \
),



/* Me
 * ,-----------------------------------------------------------------------------------.
 * | GRV  |   F1 |   F2 |   F3 |   F4 |   F5 |   F6 |   F7 |   F8 |   F9 | F10  | DEL  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |      |      |      |  PD  |  PU  | INS  |      | PIPE |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ESC  |      |      |      |      |      | LEFT | DOWN |   UP | RIGHT|      |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |      |      |      |      |      | END  | HOME |      |      |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |      |      |      |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_ME] = LAYOUT_ortho_5x12( \
  KC_GRV,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_DEL, \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_PGDN,    KC_PGUP,    KC_INSERT,    KC_TRNS,    KC_PIPE,  \
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_LEFT,    KC_DOWN, KC_UP, KC_RIGHT,    KC_S,    KC_QUOT, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_END,    KC_HOME,    _______,    _______,    _______,  \
  _______, _______, _______, _______,   _______, KC_TRNS,  KC_TRNS,  _______,   _______, _______, _______,   _______  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | MUTE |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | VOL+ |Brit+ |      |      |      |      |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | VOL- |Brit- |      |      |      |      |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_5x12( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_TRNS, KC_MUTE, _______,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______,  \
  KC_TRNS,  KC_VOLU, KC_SLCK,   KC_TRNS, KC_TRNS,   _______,   _______,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, \
  _______, KC_VOLD, KC_PAUS,   KC_TRNS, KC_TRNS,  _______,  _______,S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END, _______, \
  _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   F7 |  F8  |  F9  | F10  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  !   |  @   |   #  |   $  |   %  |      |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |RESET |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_5x12( \
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_BSPC, \
  _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
  _______,  KC_EXLM,   KC_AT,   KC_HASH,   KC_DLR,    KC_PERC,   _______,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, _______,   _______,   _______,   _______,  _______,  _______,  KC_NUHS, KC_NUBS, KC_TRNS, KC_TRNS, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS, KC_TRNS, KC_TRNS, RESET  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|me    |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_5x12( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,  \
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, ME,  _______, _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)


};


void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case 0:
            rgblight_setrgb(220,160, 220);
            break;
        case 1:
            rgblight_setrgb(0,250, 0);
            break;
        case 2:
            rgblight_setrgb(0,16, 64);
            break;
        case 3:
            rgblight_setrgb(100,0, 100);
            break;
        case 4:
            rgblight_setrgb(0,250, 250);
            break;
        default:
            rgblight_setrgb(128,0, 0);
            break;
    }

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;

        case ME:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_ME);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            PORTE &= ~(1<<6);
          } else {
            unregister_code(KC_RSFT);
            PORTE |= (1<<6);
          }
          return false;
          break;
      }
    return true;
};
