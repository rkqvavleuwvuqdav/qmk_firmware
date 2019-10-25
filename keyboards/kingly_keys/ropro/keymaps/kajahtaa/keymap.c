/* Copyright 2019 Garret G. (TheRoyalSweatshirt)
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

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define MT_RSFT_ENT MT(MOD_RSFT, KC_ENT)
#define CTL_ESC MT(MOD_LCTL,KC_ESC)
#define RCMD_LEFT RCMD_T(KC_LEFT)
#define LCMD_RIGHT LGUI_T(KC_RIGHT)
#define RALT_DOWN RALT_T(KC_DOWN)
#define RCTL_UP RCTL_T(KC_UP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   *        ,-----------------------------------------------------------------------------------.
   *        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10  | F11 |  F12 |
   *        |------+------+------+------+------+-------------+------+------+------+------+------|
   *        |  GRV |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | BACK |
   *        |+------+------+------+------+-----+------+------+------+------+------+------+------|--------------.
   *        | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   \  | Rotary Click |
   * ,------+------+------+------+------+------+------+------+------+------+------+------+------|--------------'
   * | PgUp | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------|
   * | Lower| Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      | Ctrl | ALT  | GUI  |Lower |SPACE |SPACE | RAISE| Left | Down |  Up  |Right |
   * `------------------------------------------------------------------------------------------'
   */
  	[_BASE] = LAYOUT(
              KC_F1,     KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,    KC_F12,
              KC_GRV,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,      KC_0,    KC_BSPC,
KC_TRNS,      KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,      KC_P,     KC_BSLS,
    KC_TRNS,  CTL_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,      KC_SCLN,  KC_QUOT,
    KC_TRNS,    KC_LSHIFT, KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,    KC_SLSH,   MT_RSFT_ENT,
    KC_TRNS,  KC_TRNS,    KC_RCTRL, KC_LALT,  LCMD_RIGHT,  LOWER,    KC_SPC,   KC_SPC,   RAISE,   RCMD_LEFT,  RALT_DOWN,   RCTL_UP,    KC_RGHT
  ),

  /* RAISE
   *        ,-----------------------------------------------------------------------------------.
   *        |      |      |      |      |      |      |      |      |      |      |      |      |
   *        |------+------+------+------+------+-------------+------+------+------+------+------|
   *        |      |      |      |      |      |      |      |      |      |      |      |  DEL |
   *        |+------+------+------+------+-----+------+------+------+------+------+------+------|--------------.
   *        |      |      |      |      |      |      |      |      |      |      |      | PIPE |              |
   * ,------+------+------+------+------+------+------+------+------+------+------+------+------|--------------'
   * |      |      |      |      |      |      |      |      |   -  |  =   |  [   |  ]   |      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `------------------------------------------------------------------------------------------'
   */
    [_RAISE] = LAYOUT(
              KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
              KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
KC_NLCK,      KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LBRC,  KC_RBRC,  KC_PIPE,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  /* LOWER
   *        ,-----------------------------------------------------------------------------------.
   *        |TOGRGB|      |      |      |Sat(-)|Hue(-)|Hue(+)|Sat(+)|      |      |Brght-|Brght+|
   *        |------+------+------+------+------+-------------+------+------+------+------+------|
   *        |  `   |      |      |      |      |      |      |      |      |      |      |      |
   *        |+------+------+------+------+-----+------+------+------+------+------+------+------|--------------.
   *        |      |      |      |      |      |      |      |   PD |  PU  |  INS |      | PIPE |    NumLock   |
   * ,------+------+------+------+------+------+------+------+------+------+------+------+------|--------------'
   * |      |      |      |      |      |      |      | LEFT | DOWN |  UP  |RIGHT |      |      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      | END  | HOME |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `------------------------------------------------------------------------------------------'
   */
    [_LOWER] = LAYOUT(
              RGB_TOG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_SAD,  RGB_HUD,  RGB_HUI,  RGB_SAI,  KC_TRNS,  KC_TRNS,  RGB_VAD,  RGB_VAI,
              KC_GRAVE, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_EQUAL,
KC_NLCK,      KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LBRC,  KC_RBRC,  KC_PIPE,
    KC_HOME,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_RGHT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_END,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
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

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_WH_L);
        } else {
            tap_code(KC_WH_R);
        }
    }
}
