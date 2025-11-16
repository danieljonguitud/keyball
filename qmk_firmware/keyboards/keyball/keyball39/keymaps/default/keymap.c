/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_F     , KC_P     , KC_B     ,                            KC_J     , KC_L     , KC_U     , KC_Y     , KC_QUOT  ,
    LCTL_T(KC_A),LALT_T(KC_R),LGUI_T(KC_S),LSFT_T(KC_T),KC_G,                         KC_M,RSFT_T(KC_N),RGUI_T(KC_E),RALT_T(KC_I),RCTL_T(KC_O),
    KC_Z     , KC_X     , KC_C     , KC_D     , KC_V     ,                            KC_K     , KC_H     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    KC_NO    , KC_NO  ,KC_NO,LT(2,KC_CAPS_LOCK),LT(5,KC_SPC),KC_TAB,       LT(4, KC_ENT), LT(3,KC_BSPC),KC_NO, KC_NO , KC_NO    , KC_A
  ),
  // Mouse
  [1] = LAYOUT_universal(
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,                            KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
    KC_NO    , KC_NO    , KC_BTN2  , KC_BTN1  , KC_NO    ,                            KC_NO    , KC_RSFT  , KC_RGUI  , KC_RALT  , KC_RCTL  ,
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,                            KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,      KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO
  ),
  // Media
  [2] = LAYOUT_universal(
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,                            KC_NO    , KC_BRID  , KC_BRIU  , KC_NO    , KC_NO    ,
    KC_LCTL  , KC_LALT  , KC_LGUI  , KC_LSFT  , KC_NO    ,                            KC_NO    , KC_MPRV  , KC_VOLD  , KC_VOLU  , KC_MNXT  ,
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,                            KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,   KC_NO ,       KC_MUTE,   KC_MPLY  , KC_NO    , KC_NO    , KC_NO    , KC_NO
  ),
  // Num
  [3] = LAYOUT_universal(
    KC_LBRC  , KC_7     , KC_8     , KC_9     , KC_RBRC  ,                            KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
    KC_SCLN  , KC_4     , KC_5     , KC_6     , KC_EQL   ,                            KC_NO    , KC_RSFT  , KC_RGUI  , KC_RALT  , KC_RCTL  ,
    KC_GRV   , KC_1     , KC_2     , KC_3     , KC_BSLS  ,                            KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
    KC_NO    , KC_NO    , KC_NO    , KC_DOT   , KC_0     , KC_MINS  ,      KC_NO  ,   KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO
  ),
  // Sym
  [4] = LAYOUT_universal(
    KC_LCBR  , KC_AMPR  , KC_ASTR  , KC_LPRN  , KC_RCBR  ,                            KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
    KC_COLN  , KC_DLR   , KC_PERC  , KC_CIRC  , KC_PLUS  ,                            KC_NO    , KC_RSFT  , KC_RGUI  , KC_RALT  , KC_RCTL  ,
    KC_TILD  , KC_EXLM  , KC_AT    , KC_HASH  , KC_PIPE  ,                            KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
      KC_NO    , KC_NO    , KC_NO    , KC_LPRN  , KC_RPRN  , KC_UNDS  ,      KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO
  ),
  // Nav
  [5] = LAYOUT_universal(
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,                            KC_NO    , KC_LCBR  , KC_RCBR  , KC_LPRN  , KC_LPRN  ,
    KC_LCTL  , KC_LALT  , KC_LGUI  , KC_LSFT  , KC_NO    ,                            KC_NO    , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RIGHT ,
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,                            KC_NO    , KC_LBRC  , KC_RBRC  , KC_LT    , KC_GT    ,
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,   KC_NO ,       KC_ENT,    KC_BSPC  , KC_NO    , KC_NO    , KC_NO    , KC_NO 
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 5 (Nav)
    keyball_set_scroll_mode(get_highest_layer(state) == 5);
    return state;
}

void pointing_device_init_user(void) {
    set_auto_mouse_enable(true); 
}

const uint16_t PROGMEM esc[] = {LCTL_T(KC_A), RCTL_T(KC_O), COMBO_END};
combo_t key_combos[] = {
    COMBO(esc, KC_ESC),
};

#ifdef OLED_ENABLE

#include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
