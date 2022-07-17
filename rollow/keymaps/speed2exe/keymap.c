#include QMK_KEYBOARD_H
#include <stdio.h>
#include "keylogger.c"

enum rollow_layers {
    _BASE,
    _NUM,
    _SYM,
    _NAV,
    _FN,
};

// homerow mod for left hand
#define HM_S LCTL_T(KC_S)
#define HM_H LALT_T(KC_H)
#define HM_N LSFT_T(KC_N)
#define HM_T LGUI_T(KC_T)

// homerow mod for right hand
#define HM_A RGUI_T(KC_A)
#define HM_E RSFT_T(KC_E)
#define HM_O RALT_T(KC_O)
#define HM_I RCTL_T(KC_I)

// layer taps for thumb keys
#define LT_NUM LT(_NUM, KC_SPC)
#define LT_NAV LT(_NAV, KC_ESC)
#define LT_FN  LT(_FN, KC_ENT)
#define LT_SYM LT(_SYM, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //             ┌─────┐                                                         ┌─────┐
    //       ┌─────┤  R  ├─────┬─────┐                                 ┌─────┬─────┤  U  ├─────┐
    // ┌─────┤  L  ├─────┤  B  │     │                                 │     │  Q  ├─────┤  D  ├─────┐
    // │  W  ├─────┤  N  ├─────┼─────┤                                 ├─────┼─────┤  E  ├─────┤  J  │
    // ├─────┤  H  ├─SFT─┤  T  │  Z  │                                 │  G  │  A  ├─SFT─┤  O  ├─────┤
    // │  S  ├─ALT─┤  V  ├─GUI─┼─────┤                                 ├─────┼─GUI─┤  X  ├─ALT─┤  I  │
    // ├─CTL─┤  M  ├─────┤  C  │     │                                 │     │  P  ├─────┤  K  ├─CTL─┤
    // │  F  ├─────┘     └─────┴─────┘                                 └─────┴─────┘     └─────┤  Y  │
    // └─────┘               ┌─────┐                                      ┌─────┐              └─────┘
    //                       │     ├─────┐                          ┌─────┤     │
    //                       └─────┤ SPC ├─────┐              ┌─────┤ SPC ├─────┘
    //                             └─num─┤ ESC │              │ RET ├─sym─┘
    //                                   └─nav─┘              └─fn──┘
    [_BASE] = LAYOUT_split_3x5_3 (
        KC_W,    KC_L,    KC_R,    KC_B,    _______,          _______, KC_Q,    KC_U,    KC_D,    KC_J,
        HM_S,    HM_H,    HM_N,    HM_T,    KC_Z,             KC_G,    HM_A,    HM_E,    HM_O,    HM_I,
        KC_F,    KC_M,    KC_V,    KC_C,    _______,          _______, KC_P,    KC_X,    KC_K,    KC_Y,
                          _______, LT_NUM,  LT_NAV,           LT_FN,   LT_SYM,  _______
    ),

    //             ┌─────┐                                                         ┌─────┐
    //       ┌─────┤     ├─────┬─────┐                                 ┌─────┬─────┤  8  ├─────┐
    // ┌─────┤     ├─────┤     │     │                                 │     │  7  ├─────┤  9  ├─────┐
    // │     ├─────┤ SFT ├─────┼─────┤                                 ├─────┼─────┤  5  ├─────┤  0  │
    // ├─────┤ ALT ├─────┤ GUI │     │                                 │     │  4  ├─────┤  6  ├─────┤
    // │ CTL ├─────┤     ├─────┼─────┤                                 ├─────┼─────┤  2  ├─────┤  ;  │
    // ├─────┤     ├─────┤     │     │                                 │     │  1  ├─────┤  3  ├─────┤
    // │     ├─────┘     └─────┴─────┘                                 └─────┴─────┘     └─────┤     │
    // └─────┘               ┌─────┐                                      ┌─────┐              └─────┘
    //                       │     ├─────┐                          ┌─────┤     │
    //                       └─────┤ TAB ├─────┐              ┌─────┤ BSP ├─────┘
    //                             └─────┤     │              │     ├─────┘
    //                                   └─────┘              └─────┘
    [_NUM] = LAYOUT_split_3x5_3 (
        _______, _______, _______, _______, _______,          _______, KC_7,    KC_8,   KC_9,     KC_0,
        KC_LCTL, KC_LALT, KC_LSFT, KC_RGUI, _______,          _______, KC_4,    KC_5,   KC_6,     KC_SCLN,
        _______, _______, _______, _______, _______,          _______, KC_1,    KC_2,   KC_3,     _______,
                          _______, _______, _______,          _______, KC_BSPC, _______
    ),

    //             ┌─────┐                                                         ┌─────┐
    //       ┌─────┤  [  ├─────┬─────┐                                 ┌─────┬─────┤     ├─────┐
    // ┌─────┤  `  ├─────┤  ]  │     │                                 │     │     ├─────┤     ├─────┐
    // │     ├─────┤  ,  ├─────┼─────┤                                 ├─────┼─────┤ SFT ├─────┤     │
    // ├─────┤  '  ├─────┤  .  │     │                                 │     │ GUI ├─────┤ ALT ├─────┤
    // │  /  ├─────┤  -  ├─────┼─────┤                                 ├─────┼─────┤ Rep ├─────┤ CTL │
    // ├─────┤  \  ├─────┤  =  │     │                                 │     │     ├─────┤     ├─────┤
    // │ CAP ├─────┘     └─────┴─────┘                                 └─────┴─────┘     └─────┤     │
    // └─────┘               ┌─────┐                                      ┌─────┐              └─────┘
    //                       │     ├─────┐                          ┌─────┤     │
    //                       └─────┤     ├─────┐              ┌─────┤     ├─────┘
    //                             └─────┤     │              │     ├─────┘
    //                                   └─────┘              └─────┘
    [_SYM] = LAYOUT_split_3x5_3 (
        _______, KC_GRV,  KC_LBRC, KC_RBRC, _______,          _______, _______, _______, _______, _______,
        KC_SLSH, KC_QUOT, KC_COMM, KC_DOT,  _______,          _______, KC_RGUI, KC_RSFT, KC_RALT, KC_RCTL,
        KC_CAPS, KC_BSLS, KC_MINS, KC_EQL,  _______,          _______, _______, _______, _______, _______,
                          _______, KC_TAB,  _______,          _______, _______, _______
    ),

    //             ┌─────┐                                                         ┌─────┐
    //       ┌─────┤     ├─────┬─────┐                                 ┌─────┬─────┤  ↑  ├─────┐
    // ┌─────┤     ├─────┤     │     │                                 │     │ Ins ├─────┤ VlU ├─────┐
    // │     ├─────┤ SFT ├─────┼─────┤                                 ├─────┼─────┤  ↓  ├─────┤ VlD │
    // ├─────┤ ALT ├─────┤ GUI │     │                                 │ Del │  ←  ├─────┤  →  ├─────┤
    // │ CTL ├─────┤     ├─────┼─────┤                                 ├─────┼─────┤ PgU ├─────┤ Mut │
    // ├─────┤     ├─────┤     │     │                                 │     │ PgD ├─────┤ Hom ├─────┤
    // │     ├─────┘     └─────┴─────┘                                 └─────┴─────┘     └─────┤ End │
    // └─────┘               ┌─────┐                                      ┌─────┐              └─────┘
    //                       │     ├─────┐                          ┌─────┤     │
    //                       └─────┤     ├─────┐              ┌─────┤     ├─────┘
    //                             └─────┤     │              │     ├─────┘
    //                                   └─────┘              └─────┘
    [_NAV] = LAYOUT_split_3x5_3 (
        _______, _______, _______, _______, _______,          _______, KC_INS,  KC_UP,   KC_VOLU, KC_VOLD,
        KC_LCTL, KC_LALT, KC_LSFT, KC_RGUI, _______,          KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_MUTE,
        _______, _______, _______, _______, _______,          _______, KC_PGDN, KC_PGUP, KC_HOME, KC_END,
                          _______, _______, _______,          _______, _______, _______
    ),

    //             ┌─────┐                                                         ┌─────┐
    //       ┌─────┤ F3  ├─────┬─────┐                                 ┌─────┬─────┤     ├─────┐
    // ┌─────┤ F2  ├─────┤ F4  │     │                                 │     │     ├─────┤     ├─────┐
    // │ F1  ├─────┤ F7  ├─────┼─────┤                                 ├─────┼─────┤ SFT ├─────┤     │
    // ├─────┤ F6  ├─────┤ F8  │     │                                 │     │ GUI ├─────┤ ALT ├─────┤
    // │ F5  ├─────┤ F11 ├─────┼─────┤                                 ├─────┼─────┤     ├─────┤ CTL │
    // ├─────┤ F10 ├─────┤ F12 │     │                                 │     │     ├─────┤     ├─────┤
    // │ F9  ├─────┘     └─────┴─────┘                                 └─────┴─────┘     └─────┤     │
    // └─────┘               ┌─────┐                                      ┌─────┐              └─────┘
    //                       │     ├─────┐                          ┌─────┤     │
    //                       └─────┤     ├─────┐              ┌─────┤     ├─────┘
    //                             └─────┤     │              │     ├─────┘
    //                                   └─────┘              └─────┘
    [_FN] = LAYOUT_split_3x5_3 (
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,          _______, _______, _______, _______, _______,
        KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,          _______, KC_RGUI, KC_RSFT, KC_RALT, KC_RCTL,
        KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,          _______, _______, _______, _______, _______,
                          _______, _______, _______,          _______, _______, _______
    ),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] = {
        // left encoder thumb motion, -> <-
        ENCODER_CCW_CW(_______, KC_TAB),

        // right encoder thumb motion, -> <-
        ENCODER_CCW_CW(KC_BSPC, _______),
    },
    [_NUM] = {
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(KC_RGHT, _______)
    },
    [_SYM] = {
        ENCODER_CCW_CW(_______, KC_LEFT),
        ENCODER_CCW_CW(_______, _______),
    },
    [_NAV] = {
        ENCODER_CCW_CW(_______, _______),
        ENCODER_CCW_CW(KC_VOLU, KC_VOLD),
    },
    [_FN] = {
        ENCODER_CCW_CW(KC_BRIU, KC_BRID),
        ENCODER_CCW_CW(_______, _______),
    },
};
#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };
    oled_write_P(qmk_logo, false);
}

char pos_log[32] = {};
void set_pos_log(keyrecord_t *record) {
    snprintf(pos_log, sizeof(pos_log),
            "ROW      %dCOL      %d",
            record->event.key.row,
            record->event.key.col);
}

char key_log[16] = {};
void set_key_log(uint16_t keycode) {
    const char* keyname = get_keyname(keycode);
    snprintf(key_log, sizeof(key_log), "KEY\n %s", keyname);
}

char mod_log[32] = {};
#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))
#define MODS_CTRL_MASK   (MOD_BIT(KC_LCTL)   | MOD_BIT(KC_RCTRL))
#define MODS_ALT_MASK    (MOD_BIT(KC_LALT)   | MOD_BIT(KC_RALT))
#define MODS_GUI_MASK    (MOD_BIT(KC_LGUI)   | MOD_BIT(KC_RGUI))
void set_mod_log(void) {
    uint8_t mods = get_mods();
    snprintf(mod_log, sizeof(mod_log),
            "MOD\n%s%s%s%s",
            ((mods & MODS_SHIFT_MASK) ? " SHFT" : "\n"),
            ((mods & MODS_CTRL_MASK) ? " CTRL" : "\n"),
            ((mods & MODS_ALT_MASK) ? "  ALT" : "\n"),
            ((mods & MODS_GUI_MASK) ? "  GUI" : "\n")
    );
}

void oled_write_layer(void) {
    oled_write_P(PSTR("LAYER"), false);
    // Print current layer
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR(" BASE"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("  NUM"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("  SYM"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("  NAV"), false);
            break;
        case _FN:
            oled_write_P(PSTR("   FN"), false);
            break;
        default:
            oled_write_P(PSTR("    ?"), false);
    }
}

void oled_write_caps(void) {
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CAPS"), false);
    if (led_usb_state.caps_lock) {
        oled_write_P(PSTR("   ON"), led_usb_state.caps_lock);
    } else {
        oled_write_P(PSTR("  OFF"), led_usb_state.caps_lock);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_pos_log(record);
        // set_key_log(keycode);
        set_mod_log();
    }
  return true;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_layer();
        oled_write_caps();
        oled_write(pos_log, false);
        // oled_write(key_log, false);
        oled_write(mod_log, false);
    } else {
        render_logo();
    }
    return false;
}

#endif
