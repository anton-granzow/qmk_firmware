 /* Copyright 2017 F_YUUCHI
  * Copyright 2020 Drashna Jaelre <@drashna>
  * Copyright 2020 Ben Roesner (keycapsss.com)
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


extern uint8_t is_master;

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _EXTRA,
    _ADJUST,
    _GAMING,
    _GAMING2, 
    _LOL1
};

// Layers
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define EXTRA OSL(_EXTRA)
#define GAMING TG(_GAMING)
#define GAMING2 TG(_GAMING2)
#define ADJUST TG(_ADJUST)

// Layer Taps
#define SPC_RAISE LT(_RAISE, KC_SPC)
#define BSPC_RAISE LT(_RAISE, KC_BSPC)
#define ENT_LOWER LT(_LOWER, KC_ENT)
#define DEL_LOWER LT(_LOWER, KC_DEL)


// Homerow Mods
//  left
#define HR_A MT(MOD_LALT, KC_A)
#define HR_S MT(MOD_LGUI, KC_S)
#define HR_D MT(MOD_LCTL, KC_A)
#define HR_F MT(MOD_LSFT, KC_F)
//  right
#define HR_SCLN MT(MOD_LALT, KC_SCLN)
#define HR_L    MT(MOD_LGUI, KC_L)
#define HR_K    MT(MOD_LCTL, KC_K)
#define HR_J    MT(MOD_LSFT, KC_J)


// Special Binds

// LOL
#define LOL_Q MT(MOD_LSFT | KC_Q, KC_Q)
#define LOL_W MT(MOD_LSFT | KC_W, KC_W)
#define LOL_E MT(MOD_LSFT | KC_E, KC_E)
#define LOL_R MT(MOD_LSFT | KC_R, KC_R)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|Pause/Play| | Mouse3|------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RCTRL |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \BackSP\  |Lower |Raise | RAlt |
 *                   |      |      |      |/ Raise /         \Raise \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
   KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,   KC_9,        KC_0,     KC_DEL,
   KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,   KC_O,        KC_P,     KC_BSPC,
  KC_LSHIFT, HR_A,   HR_S,    HR_D,    HR_F,    KC_G,                     KC_H,    HR_J,    HR_K,    HR_L,     HR_SCLN,     KC_ENT,
  KC_LCTRL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MPLY,  KC_MS_BTN3,  KC_N,    KC_M,    KC_COMM, KC_DOT,  EXTRA,    KC_RCTRL,
                             KC_LALT, KC_LGUI,ENT_LOWER, SPC_RAISE,   BSPC_RAISE,   DEL_LOWER,   HYPR_T(KC_ESC), KC_RALT
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      | Del  ||
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   `  |   _  |   [  |   ]  |   ^  |                    |   !  |   <  |   >  |   =  |   &  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   \  |   /  |   {  |   }  |   *  |-------.    ,-------|   ?  |   (  |   )  |   -  |   :  |Enter |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   #  |   $  |   |  |   ~  |   '  |-------|    |-------|   +  |   %  |  "   |   ;  |  @   |RCTRL |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \BackSP\  |Lower |Raise | RAlt |
 *                   |      |      |      |/ Raise /         \Raise \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______,  _______, _______,
  _______,  KC_GRV, KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC,                   KC_EXLM,   KC_LT,   KC_GT, KC_EQL,  KC_AMPR,  _______,
  XXXXXXX, KC_BSLS,	KC_SLSH, KC_LCBR, KC_RCBR, KC_ASTR,                   KC_QUES, KC_LPRN, KC_RPRN, KC_MINS,  KC_COLN, _______, 
  _______, KC_HASH, KC_DLR,  KC_PIPE, KC_TILD, KC_QUOT, _______, _______, KC_PLUS, KC_PERC, KC_DQUO, KC_SCLN,   KC_AT, _______,
                             _______, _______, _______, _______, _______,  _______, _______, ADJUST 
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | PgDn |BackSP|  Up  | Del  | PgUp |                    |   /  |   7  |   8  |   9  |   -  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Pos1 | Left | Down |Right |  End |-------.    ,-------|   *  |   4  |   5  |   6  |   +  |Enter |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | ESC  | Cut  | Copy |Paste | Undo |-------|    |-------|   =  |   1  |   2  |   3  |   ;  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \BackSP\  |   0  |   ,  |  .   |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
    KC_F1,    KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,                       KC_F7, KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
  _______,  KC_PGDN,   KC_BSPC, KC_UP,    KC_DEL,  KC_PGUP,                   KC_SLSH,  KC_7,    KC_8,     KC_9,  KC_MINS, _______,
  XXXXXXX,  KC_HOME, KC_LEFT, KC_DOWN,  KC_RGHT, KC_END,                      KC_ASTR,  KC_4,    KC_5,     KC_6,  KC_PLUS,  _______,
  _______,   KC_ESC,  KC_CUT, KC_COPY,  KC_PSTE,  KC_UNDO,   _______, _______, KC_EQL,  KC_1,    KC_2,    KC_3,    KC_SCLN, _______,
                             _______, _______, _______,  _______, XXXXXXX,  KC_0, KC_COMM, KC_DOT
),
/* EXTRA Characters
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |   €  |      |      |                    |      |   Ü  |      |   Ö  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Ä  |   ß  |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \BackSP\  |Lower |Raise | RAlt |
 *                   |      |      |      |/ Raise /         \Raise \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_EXTRA] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, ALGR(KC_E), XXXXXXX, XXXXXXX,             XXXXXXX, ALGR(KC_Y), XXXXXXX, ALGR(KC_P), XXXXXXX, XXXXXXX,
  _______, ALGR(KC_Q), ALGR(KC_S), XXXXXXX, KC_LSHIFT, XXXXXXX,             XXXXXXX, KC_LSHIFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  ),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |Gaming|-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      | CSGO |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \BackSP\  |Lower |Raise | RAlt |
 *                   |      |      |      |/ Raise /         \Raise \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GAMING,                   XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
  XXXXXXX, XXXXXXX, XXXXXXX, GAMING2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,
                             _______, _______, _______, _______, _______,  _______, _______, ADJUST
  ),
/* GAMING
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |BackSP|   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |Enter |   |
 * |------+------+------+------+------+------|Pause/Play| | Mouse3|------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RCTRL |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \BackSP\  |Lower |Raise | RAlt |
 *                   |      |      |      |/ Raise /         \Raise \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_GAMING] = LAYOUT(
   KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,   KC_9,        KC_0,     KC_DEL,
   KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,   KC_O,        KC_P,     KC_BSPC,
  KC_LSHIFT, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,     KC_ENT,
  KC_LCTRL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MPLY,  KC_BTN3,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RCTRL,
                             KC_LALT, KC_LGUI,KC_LSHIFT, KC_SPC,   BSPC_RAISE,   LOWER,   RAISE, GAMING
),
/* GAMING2
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |BackSP|   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |Enter |   |
 * |------+------+------+------+------+------|Pause/Play| | Mouse3|------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RCTRL |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \BackSP\  |Lower |Raise | RAlt |
 *                   |      |      |      |/ Raise /         \Raise \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_GAMING2] = LAYOUT(
   KC_ESC,   KC_5,   KC_1,   KC_2,    KC_3,    KC_4,                     KC_6,    KC_7,    KC_8,   KC_9,        KC_0,     KC_DEL,
   KC_TAB,   KC_T,   KC_Q,   KC_W,    KC_E,    KC_R,                     KC_Y,    KC_U,    KC_I,   KC_O,        KC_P,     KC_BSPC,
  KC_LSHIFT, KC_G,   KC_A,   KC_S,    KC_D,    KC_F,                     KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,     KC_ENT,
  KC_LCTRL,  KC_B,   KC_Z,   KC_X,    KC_C,    KC_V, KC_MPLY,  KC_BTN3,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RCTRL,
                             KC_LALT, KC_LGUI,KC_LSHIFT, KC_SPC,   BSPC_RAISE,   LOWER,   RAISE, GAMING
),
/* LOL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |BackSP|   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |Enter |   |
 * |------+------+------+------+------+------|Pause/Play| | Mouse3|------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RCTRL |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \BackSP\  |Lower |Raise | RAlt |
 *                   |      |      |      |/ Raise /         \Raise \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_LOL1] = LAYOUT(
   KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,   KC_9,        KC_0,     KC_DEL,
   KC_TAB,   LOL_Q,  LOL_W,   LOL_E,   LOL_R,   KC_T,                     KC_Y,    KC_U,    KC_I,   KC_O,        KC_P,     KC_BSPC,
  KC_LSHIFT, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,     KC_ENT,
  KC_LCTRL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MPLY,  KC_BTN3,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RCTRL,
                             KC_LALT, KC_LGUI,KC_LSHIFT, KC_SPC,   BSPC_RAISE,   LOWER,   RAISE, GAMING
),
};


// layer_state_t layer_state_set_user(layer_state_t state) {
//     state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
//     return state;
// }

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_0;
    }
}

void render_lily58_logo(void) {
    static const char PROGMEM lily58_logo[] = {
    // 'logo', 128x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xc0, 0x40, 0x40, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00,
    0x80, 0xe0, 0x70, 0x3c, 0x0e, 0x06, 0x0e, 0x3c, 0x70, 0xe0, 0x80, 0x00, 0x00, 0xc0, 0xc0, 0x00,
    0xc0, 0xc0, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x80,
    0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0xc0, 0x80, 0x80, 0x80, 0x81, 0x83, 0x83,
    0x07, 0x07, 0x0c, 0x18, 0x70, 0xe0, 0x80, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x80, 0xb6, 0xb6, 0x80,
    0xb0, 0xb0, 0x00, 0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf1, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x00, 0x00, 0x00, 0x30, 0xf0, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xf0,
    0x30, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xe1, 0x71, 0x71, 0xf1, 0xf1, 0xe1, 0xc1, 0x81, 0x00, 0x00,
    0x00, 0x00, 0x0c, 0x3f, 0xff, 0xf3, 0xe1, 0xc1, 0xc1, 0x81, 0x81, 0xc3, 0xff, 0x7f, 0x1c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x70, 0x78, 0xdc, 0xcc, 0x86, 0x06, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x03, 0x02, 0x06, 0x84, 0xe1, 0xfb, 0x38, 0x1c, 0x0c, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x03, 0x03, 0x06, 0x86, 0xcc, 0xdc, 0x78, 0x70, 0x20, 0x00, 0xff, 0xff, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1f, 0x7e, 0xf8, 0xe0, 0xf0, 0x7e, 0x1f, 0x03, 0x00,
    0x00, 0x00, 0x00, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0xc0, 0xe1, 0xff, 0x7f, 0x3f, 0x00,
    0x00, 0x00, 0x3e, 0xff, 0xff, 0xc1, 0xc0, 0x80, 0x81, 0x81, 0xc3, 0xc3, 0xff, 0xfe, 0x3c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x06, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04, 0x06,
    0x06, 0x02, 0x03, 0x01, 0x01, 0x00, 0x01, 0x01, 0x03, 0x02, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04,
    0x06, 0x06, 0x06, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x01, 0x00, 0x00, 0x60, 0x60, 0x70, 0x38, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00
};
    oled_write_raw_P(lily58_logo, sizeof(lily58_logo));
}


#    define KEYLOG_LEN 6
char     keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

void render_keylogger_status(void) {
    oled_write_P(PSTR("KLogr"), false);
    oled_write(keylog_str, false);
}

void render_default_layer_state(void) {
    oled_write_P(PSTR("Layer"), false);
    oled_write_P(PSTR(" "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QRTY"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("LOW"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("HIGH"), false);
            break;
        case _EXTRA:
            oled_write_P(PSTR("EXTRA"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("ADJ"), false);
            break;
        case _GAMING:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

void render_keylock_status(led_t led_state) {
    oled_write_ln_P(PSTR("Lock"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_state.num_lock);
    oled_write_P(PSTR("C"), led_state.caps_lock);
    oled_write_ln_P(PSTR("S"), led_state.scroll_lock);
}

void render_mod_status(uint8_t modifiers) {
    oled_write_ln_P(PSTR("Mods"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
}

void render_status_main(void) {
    // Show keyboard layout
    render_default_layer_state();
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Show host keyboard led status
    render_keylock_status(host_keyboard_led_state());
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Show modifier status
    render_mod_status(get_mods());
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    render_keylogger_status();
}

bool oled_task_user(void) {
  update_log();
  if (is_keyboard_master()) {
    render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  } else {
    render_lily58_logo();
  }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        add_keylog(keycode);
    }
    return true;
}
#endif // OLED_ENABLE


// Rotary encoder related code
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { // Encoder on master side
    if(IS_LAYER_ON(_LOWER)) { // on Raise layer
      // Cursor control
      if (clockwise) {
          tap_code(KC_MNXT);
      } else {
          tap_code(KC_MPRV);
      }
    }
    else {
      if (clockwise) {
          tap_code(KC_VOLU);
      } else {
          tap_code(KC_VOLD);
      }
    }
  }
  else if (index == 1) { // Encoder on slave side
    if(IS_LAYER_ON(_LOWER)) { // on Lower layer
      //
      if (clockwise) {
          tap_code(KC_RIGHT);
      } else {
          tap_code(KC_LEFT);
      }
    }
    else {
      if (clockwise) {
          tap_code(KC_DOWN);
      } else {
          tap_code(KC_UP);
      }
    }
  }
    return true;
}
#endif
