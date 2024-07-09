#include QMK_KEYBOARD_H

void keyboard_pre_init_user(void) {
    // Set our LED pin as output
    setPinOutput(24);
    // Turn the LED off
    // (Due to technical reasons, high is off and low is on)
    writePinHigh(24);
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT(   KC_GRV,        KC_1,         KC_2,    KC_3,    KC_4,     KC_5,                          KC_6,    KC_7,     KC_8,    KC_9,     KC_0,     KC_EQL,
                KC_TAB,        KC_Q,         KC_W,    KC_E,    KC_R,     KC_T,                          KC_Y,    KC_U,     KC_I,    KC_O,     KC_P,     KC_MINS,
                KC_BSPC,       KC_A,         KC_S,    KC_D,    KC_F,     KC_G,                          KC_H,    KC_J,     KC_K,    KC_L,     KC_SCLN,  KC_QUOT,
                KC_LSFT,       KC_Z,         KC_X,    KC_C,    KC_V,     KC_B,      KC_L,   KC_R,       KC_N,    KC_M,     KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,
                KC_LCTL,       KC_LGUI,      KC_LALT, KC_BSLS, KC_SPC,   MO(1),     KC_ESC, KC_DEL,     MO(2),   KC_ENT,   KC_LEFT, KC_DOWN,  KC_UP,    KC_RGHT
),
[1] = LAYOUT(   KC_F11,        KC_F1,       KC_F2,    KC_F3,   KC_F4,    KC_F5,                         KC_F6,   KC_F7,    KC_F8,   KC_F9,    KC_F10,   KC_F12,
                KC_TRNS,       KC_TRNS,     KC_TRNS,  KC_TRNS, KC_PLUS,  KC_LBRC,                       KC_RBRC, KC_EQL,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
                KC_TRNS,       KC_TRNS,     KC_TRNS,  KC_TRNS, KC_MINS,  KC_LCBR,                       KC_RCBR, KC_UNDS,   KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
                KC_TRNS,       KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS,  KC_LPRN,   KC_TRNS, KC_TRNS,   KC_RPRN, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
                KC_TRNS,       KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,  KC_HOME, KC_PGDN,  KC_PGUP,  KC_END
),
[2] = LAYOUT(   KC_TRNS,       KC_P1,       KC_P2,    KC_P3,   KC_P4,    KC_P5,                         KC_P6,   KC_P7,    KC_P8,   KC_P9,    KC_P0,    KC_TRNS,
                KC_TRNS,       KC_TRNS,     KC_TRNS,  KC_TRNS, KC_PLUS,  KC_LBRC,                       KC_RBRC, KC_EQL,   KC_TRNS, KC_TRNS,  KC_MPLY,  KC_TRNS,
                KC_TRNS,       KC_TRNS,     KC_TRNS,  KC_TRNS, KC_MINS,  KC_LCBR,                       KC_RCBR, KC_UNDS,   KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
                KC_TRNS,       KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS,  KC_LPRN,   KC_TRNS, KC_TRNS,   KC_RPRN, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
                KC_TRNS,       KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,  KC_HOME, KC_PGDN,  KC_PGUP,  KC_END
)

};

// clang-format on

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
    // Initialize RGB to static black
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_WHITE);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

void housekeeping_task_user(void) {
    rgblight_setrgb_at(RGB_WHITE, 0);
}

#endif

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

// #ifdef ENCODER_ENABLE
// bool encoder_update_user(uint8_t index, bool clockwise) {
//     // 0 is left-half encoder
//     // 1 is right-half encoder
//     if (index == 0) {
//         if (clockwise) {
//             tap_code(KC_VOLU);
//         } else {
//             tap_code(KC_VOLD);
//         }

//     } else if (index == 1) {
//         if (clockwise) {
//             tap_code(KC_PGDN);
//         } else {
//             tap_code(KC_PGUP);
//         }
//     }
//     return false;
// }
// #endif
