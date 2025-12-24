#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        /* * ROW 0: Chrome   | Discord  | Explorer | Next Track 
         * ROW 1: C+A+Del  | Ctrl+C   | Ctrl+V   | Prev Track
         * ROW 2: Lock PC  | Snipping | Game Bar | Win+Tab
         * ROW 3: Ctrl+Z   | Win+E    | Win+D    | Play/Pause (Encoder)
         */
        KC_F13,      KC_F14,      KC_F15,      KC_MNXT,
        LCA(KC_DEL), C(KC_C),     C(KC_V),     KC_MPRV,
        LGUI(KC_L),  G(S(KC_S)),  LGUI(KC_G),  LGUI(KC_TAB),
        C(KC_Z),     LGUI(KC_E),  LGUI(KC_D),  KC_MPLY
    ),
    [1] = LAYOUT(
        RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI,
        XXXXXXX, XXXXXXX, RGB_HUD, RGB_SAD,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        QK_BOOT, _______, XXXXXXX, XXXXXXX
    )
};

// VIAL-compatible encoder logic
// By default, rotation is Volume Up/Down
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}