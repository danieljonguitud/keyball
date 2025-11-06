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
    KC_LCTL  , KC_LGUI  , KC_LALT, KC_CAPS_LOCK,LT(1,KC_SPC),KC_TAB,       KC_ENT,    KC_BSPC  ,  _______ ,  _______ ,  _______ , KC_A
  ),

  [1] = LAYOUT_universal(
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,                            KC_NO    , KC_LBRC  , KC_RBRC  ,RSFT(KC_9),RSFT(KC_0),
    KC_LCTL  , KC_LALT  , KC_LGUI  , KC_LSFT  , KC_NO    ,                            KC_NO    , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RIGHT ,
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,                            KC_LBRC  , KC_DLR   , KC_PGDN  , KC_BTN3  , KC_F11   ,
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,   KC_NO ,      KC_ENT,     KC_BSPC  , KC_NO    , KC_NO    , KC_NO    , KC_NO 
  ),

  [2] = LAYOUT_universal(
    KC_TAB   , KC_7     , KC_8     , KC_9     , KC_MINS  ,                            KC_NUHS  , _______  , KC_BTN3  , _______  , KC_BSPC  ,
   S(KC_QUOT), KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                            S(KC_9)  , KC_BTN1  , KC_UP    , KC_BTN2  , KC_QUOT  ,
    KC_SLSH  , KC_1     , KC_2     , KC_3     ,S(KC_MINS),                           S(KC_NUHS), KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  ,
    KC_ESC   , KC_0     , KC_DOT   , KC_DEL   , KC_ENT   , KC_BSPC  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  ,                            _______  , _______  , SSNP_HOR , SSNP_VRT , SSNP_FRE ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , SCRL_DVI ,                            _______  , _______  , _______  , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , SCRL_DVD ,                            CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    QK_BOOT  , KBC_RST  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , KBC_RST  , QK_BOOT
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
