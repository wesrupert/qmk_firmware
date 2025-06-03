// Copyright 2025 Wes Rupert (@wesrupert)
// SPDX-License-Identifier: GPL-3.0-or-later
#include "action_layer.h"
#include "ora.h"

enum layers {
    LAYER_ENUM_END = LAYER_ENUM_END_USER,
};

enum tap_dances {
    DANCE_RGUI_RALT_LEAD = 0,
    DANCE_LCTL_LGUI_DMC1,
    DANCE_RCTL_RGUI_DMC2,
    X_TAP_DANCE
};

// Advance key aliases
#define LI_ANIT RGB_TOG
#define LI_LDLT LED_LEVEL
#define LI_LYRT TOGGLE_LAYER_COLOR
#define LT_FNEN LT(LAYER_FUNCTION, KC_ENT)
#define LT_FNES LT(LAYER_FUNCTION, KC_ESC)
#define MT_LAEQ LALT_T(KC_EQL)
#define MT_LGEQ LGUI_T(KC_EQL)
#define MT_LCEQ LCTL_T(KC_EQL)
#define MT_LAMN LALT_T(KC_MINS)
#define MT_LGMN LGUI_T(KC_MINS)
#define MT_LCMN LCTL_T(KC_MINS)
#define MT_RABL RALT_T(KC_BSLS)
#define MT_RGBL RGUI_T(KC_BSLS)
#define MT_RCBL RCTL_T(KC_BSLS)
#define MT_RAQT RALT_T(KC_QUOT)
#define MT_RGQT RGUI_T(KC_QUOT)
#define MT_RCQT RCTL_T(KC_QUOT)
#define TD_R2LD TD(DANCE_RGUI_RALT_LEAD)
#define TD_LCM1 TD(DANCE_LCTL_LGUI_DMC1)
#define TD_RCM2 TD(DANCE_RCTL_RGUI_DMC2)
#define TG_NMPD TG(LAYER_NUMPAD)
#define TT_FUNC TT(LAYER_FUNCTION)
#define TT_NUMP TT(LAYER_NUMPAD)

#define HL_FNA  LT(LAYER_FUNCTION, KC_A)
#define HM_LAS  LALT_T(KC_S)
#define HM_LCS  LCTL_T(KC_S)
#define HM_LSD  LSFT_T(KC_D)
#define HM_LCF  LCTL_T(KC_F)
#define HM_LGF  LGUI_T(KC_F)
#define HM_LGG  LGUI_T(KC_G)
#define HM_LAG  LALT_T(KC_G)
#define HM_RGH  RGUI_T(KC_H)
#define HM_RAH  RALT_T(KC_H)
#define HM_RGJ  RGUI_T(KC_J)
#define HM_RCJ  RCTL_T(KC_J)
#define HM_RSK  RSFT_T(KC_K)
#define HM_RCL  RCTL_T(KC_L)
#define HM_RAL  RALT_T(KC_L)
#define HL_FNSC LT(LAYER_FUNCTION, KC_SCLN)

// Include after key definitions in order to use them in the def file
#include "g/keymap_combo.h"

// Expand key groups before passing into layout macro
#define KL(...) LAYOUT(__VA_ARGS__)

// clang-format off

// Handedness definition
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = KL(
    'L', 'L', 'L', 'L', 'L', 'L',    'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',    'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',    'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',    'R', 'R', 'R', 'R', 'R', 'R',
                        '*', 'L',    'R', '*');

// Expand LED matrixes like keymaps
#define CL( \
    k00, k01, k02, k03, k04, k05,    k26, k27, k28, k29, k30, k31, \
    k06, k07, k08, k09, k10, k11,    k32, k33, k34, k35, k36, k37, \
    k12, k13, k14, k15, k16, k17,    k38, k39, k40, k41, k42, k43, \
    k18, k19, k20, k21, k22, k23,    k44, k45, k46, k47, k48, k49, \
                        k24, k25,    k50, k51,              layer) \
  { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k10, k11, k12, \
    k13, k14, k15, k16, k17, k18, k19, k20, k21, k22, k23, k24, k25, \
    k26, k27, k28, k29, k30, k31, k32, k33, k34, k35, k36, k37, k38, \
    k39, k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k50, k51, layer }

#define _KL_BASE [LAYER_BASE] = KL( /*                   BASE                                                   */ \
    KC_DEL,  __________________QWER_L1__________________,    __________________QWER_R1__________________, KC_BSPC, \
    MT_LGTB, __________________QWER_L2__________________,    __________________QWER_R2__________________, TD_R2LD, \
    MT_LCMN, HL_FNA,  HM_LAS,  HM_LSD,  HM_LCF,  HM_LGG,     HM_RGH,  HM_RCJ,  HM_RSK,  HM_RAL,  HL_FNSC, MT_RCQT, \
    MT_LAEQ, __________________QWER_L4__________________,    __________________QWER_R4__________________, MT_RABL, \
                                        LT_FNES, MT_LSSP,    MT_RSSP, LT_FNEN)
#define _CL_BASE [LAYER_BASE] = CL(                                                                                \
    CK_WARN, R_RED,   R_ORANG, R_YELLW, R_YLGRN, R_GREEN,    R_AQGRN, R_AQUA,  R_AQBLU, R_BLUE,  R_PURPL, CK_WARN, \
    CK_MODT, R_RED,   R_ORANG, R_YELLW, R_YLGRN, R_GREEN,    R_AQGRN, R_AQUA,  R_AQBLU, R_BLUE,  R_PURPL, CK_META, \
    CK_MODT, R_RED,   R_ORANG, R_YELLW, R_YLGRN, R_GREEN,    R_AQGRN, R_AQUA,  R_AQBLU, R_BLUE,  R_PURPL, CK_MODT, \
    CK_MODT, R_RED,   R_ORANG, R_YELLW, R_YLGRN, R_GREEN,    R_AQGRN, R_AQUA,  R_AQBLU, R_BLUE,  R_PURPL, CK_MODT, \
                                        CL_FUNC, C______,    C______, CL_FUNC,                            CL_BASE)

#define _KL_MAC [LAYER_MAC] = KL( /*                     MAC                                                    */ \
    _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, \
    MT_LATB, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, \
    MT_LGMN, _______, HM_LCS,  HM_LSD,  HM_LGF,  HM_LAG,     HM_RAH,  HM_RGJ,  HM_RSK,  HM_RCL,  _______, MT_RGQT, \
    MT_LCEQ, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, MT_RCBL, \
                                        _______, _______,    _______, _______)
#define _CL_MAC [LAYER_MAC] = CL(                                                                     \
    C______, C______, C______, C______, C______, C______,    C______, C______, C______, C______, C______, C______, \
    C______, C______, C______, C______, C______, C______,    C______, C______, C______, C______, C______, C______, \
    C______, C______, C______, C______, C______, C______,    C______, C______, C______, C______, C______, C______, \
    C______, C______, C______, C______, C______, C______,    C______, C______, C______, C______, C______, C______, \
                                        C______, C______,    C______, C______,                            C______)

#define _KL_GAMES [LAYER_GAMES] = KL( /*                 GAME                                                   */ \
    KC_GRV,  __________________QWER_L1__________________,    _______, _______, _______, _______, _______, _______, \
    KC_TAB,  __________________QWER_L2__________________,    _______, _______, _______, _______, _______, _______, \
    KC_LCTL, __________________QWER_L3__________________,    _______, _______, _______, _______, _______, _______, \
    KC_LALT, __________________QWER_L4__________________,    _______, _______, _______, _______, _______, _______, \
                                        KC_LSFT, KC_SPC,     _______, _______)
#define _CL_GAMES [LAYER_GAMES] = CL(                                                                              \
    R_MGNTA, R_RED,   R_ORANG, R_YELLW, R_YLGRN, R_GREEN,    R_AQGRN, R_AQUA,  R_AQBLU, R_BLUE,  R_PURPL, CK_WARN, \
    R_MGNTA, R_RED,   C______, R_YELLW, R_YLGRN, R_GREEN,    R_AQGRN, R_AQUA,  R_AQBLU, R_BLUE,  R_PURPL, CK_META, \
    CK_MODS, C______, C______, C______, R_YLGRN, R_GREEN,    R_AQGRN, R_AQUA,  R_AQBLU, R_BLUE,  R_PURPL, CK_MODS, \
    CK_MODS, R_RED,   R_ORANG, R_YELLW, R_YLGRN, R_GREEN,    R_AQGRN, R_AQUA,  R_AQBLU, R_BLUE,  R_PURPL, CK_MODS, \
                                        CK_MODS, CL_BASE,    CL_BASE, CL_FUNC,                            CL_GAME)

#define _KL_FUNCTION [LAYER_FUNCTION] = KL( /*         FUNCTION                                                 */ \
    FUNC_11, __________________FUNC_L1__________________,    __________________FUNC_R1__________________, FUNC_12, \
    KC_LGUI, PK_ASST, _____________FUNC__L2_____________,    _____________FUNC__R2_____________, PK_PSCR, _______, \
    KC_LCTL, QK_LOCK, _____________FUNC__L3_____________,    _____________FUNC__R3_____________, PK_PSCF, KC_RCTL, \
    KC_LALT, TD_LCM1, __________MEDIA__________, PK_LOCK,    PK_LOCK, __________VOLUM__________, TD_RCM2, KC_RALT, \
                                        TT_NUMP, CW_TOGG,    CW_TOGG,  TT_NUMP)
#define _CL_FUNCTION [LAYER_FUNCTION] = CL(                                                                        \
    C______, C______, C______, C______, C______, C______,    C______, C______, C______, C______, C______, C______, \
    CK_MODS, CK_META, CK_NAVG, CK_NAVG, CK_NAVG, CK_NAVG,    CK_NAVG, CK_NAVG, CK_NAVG, CK_NAVG, CK_META, CK_META, \
    CK_MODS, CK_META, CK_NAVG, CK_NAVG, CK_NAVG, CK_NAVG,    CK_NAVG, CK_NAVG, CK_NAVG, CK_NAVG, CK_META, CK_MODS, \
    CK_MODS, CK_MODT, CK_MDIA, CK_MDIA, CK_MDIA, CK_META,    CK_META, CK_MDIA, CK_MDIA, CK_MDIA, CK_MODT, CK_MODS, \
                                        CL_NMPD, CK_WARN,    CK_WARN, CK_MODS,                            CL_FUNC)

#define _KL_NUMPAD [LAYER_NUMPAD] = KL( /*        NUMPAD  /  LIGHTS                                             */ \
    KC_DEL,  KC_PSLS, __________NMPD_1_________, KC_PMNS,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_BSPC, KC_PAST, __________NMPD_2_________, KC_PPLS,    XXXXXXX, LI_HUEU, LI_HUED, XXXXXXX, LI_LYRT, _______, \
    MT_LCES, KC_UP,   __________NMPD_3_________, KC_PEQL,    LI_PREV, LI_SATU, LI_SATD, LI_NEXT, LI_ANIT, KC_RCTL, \
    KC_LEFT, KC_DOWN, KC_RGHT, NMPD__4, KC_PDOT, KC_PENT,    LI_SLOW, LI_VALU, LI_VALD, LI_FAST, LI_LDLT, KC_RALT, \
                                        MT_LATB, MT_LSSP,    MT_RCEN, TG_NMPD)
#define _CL_NUMPAD [LAYER_NUMPAD] = CL(                                                                            \
    CK_WARN, CK_ALPH, C______, C______, C______, CK_ALPH,    C_XXXXX, C_XXXXX, C_XXXXX, C_XXXXX, C_XXXXX, C_XXXXX, \
    CK_WARN, CK_ALPH, C______, C______, C______, CK_ALPH,    C_XXXXX, C______, C______, C_XXXXX, CK_WARN, CK_META, \
    CK_WARN, CK_NAVG, C______, C______, C______, CK_ALPH,    C______, C______, C______, C______, CK_WARN, CK_MODS, \
    CK_NAVG, CK_NAVG, CK_NAVG, C______, C______, CK_ALPH,    C______, C______, C______, C______, CK_WARN, CK_MODS, \
                                        CK_MODS, CK_ALPH,    CK_MODS, CK_META,                            CL_NMPD)

/* #define _KL_TEMPLATE [LAYER_TEMPLATE] = KL( / *       TODO                                                  * / \
    _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_,    _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, \
    _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_,    _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, \
    _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_,    _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, \
    _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_,    _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, _TO_DO_, \
                                        _TO_DO_, _TO_DO_,    _TO_DO_, _TO_DO_) */
/* #define _CL_TEMPLATE [LAYER_TEMPLATE] = CL(                                                                     \
    C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO,    C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO, \
    C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO,    C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO, \
    C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO,    C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO, \
    C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO,    C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO, C_TO_DO, \
                                        C_TO_DO, C_TO_DO,    C_TO_DO, C_TO_DO,                            C_TO_DO) */

// clang-format on

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { _KL_BASE, _KL_MAC, _KL_GAMES, _KL_FUNCTION, _KL_NUMPAD };

#if defined(RGB_MATRIX_ENABLE)
const uint8_t PROGMEM ledmaps[][RGB_MATRIX_LED_COUNT+1][3] = { _CL_BASE, _CL_MAC, _CL_GAMES, _CL_FUNCTION, _CL_NUMPAD };
#endif // RGB_MATRIX_ENABLE


#if defined (VOYAGER_USER_LEDS)

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LED_LEVEL:
            if (record->event.pressed) {
                keyboard_config.led_level ^= 1;
                eeconfig_update_kb(keyboard_config.raw);
                if (keyboard_config.led_level) {
                    layer_state_set_kb(layer_state);
                } else {
                    STATUS_LED_1(false);
                    STATUS_LED_2(false);
                    STATUS_LED_3(false);
                    STATUS_LED_4(false);
                }
            }
            return false;
    }
    return true;
}

#endif // VOYAGER_USER_LEDS

DANCE_PLATMOD_MACRO(LCTL, LGUI, 1)
DANCE_PLATMOD_MACRO(RCTL, RGUI, 2)
DANCE_PLATMOD_LEADER(RGUI, RALT)

tap_dance_action_t tap_dance_actions[] = {
    [DANCE_LCTL_LGUI_DMC1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_DMC1_LCTL_LGUI_finished, dance_DMC1_LCTL_LGUI_reset),
    [DANCE_RCTL_RGUI_DMC2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_DMC2_RCTL_RGUI_finished, dance_DMC2_RCTL_RGUI_reset),
    [DANCE_RGUI_RALT_LEAD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_LEAD_RGUI_RALT_finished, dance_LEAD_RGUI_RALT_reset),
};

bool keyboard_post_init_keymap(void) {
#if defined(RGB_MATRIX_ENABLE)
    if (!keyboard_config.disable_layer_led) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    }
#endif // RGB_MATRIX_ENABLE
    return true;
}

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            rgb_matrix_set_color_all(RGB_WHITE);
            break;
        case OS_WINDOWS:
            rgb_matrix_set_color_all(RGB_BLUE);
            break;
        case OS_LINUX:
            rgb_matrix_set_color_all(RGB_ORANGE);
            break;
        case OS_UNSURE:
            rgb_matrix_set_color_all(RGB_RED);
            break;
    }

    return true;
}

#if defined (VOYAGER_USER_LEDS)

layer_state_t layer_state_set_kb(layer_state_t state) {
    state = layer_state_set_user(state);
    if (voyager_is_launching || !keyboard_config.led_level) return state;

    STATUS_LED_1(layer_state_cmp(state, LAYER_NUMPAD));
    STATUS_LED_2(layer_state_cmp(state, LAYER_FUNCTION));
    STATUS_LED_3(layer_state_cmp(state, LAYER_GAMES));
    STATUS_LED_4(layer_state_cmp(state, LAYER_MAC));

    return state;
}


#endif // VOYAGER_USER_LEDS

#if defined(RGB_MATRIX_ENABLE)

bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return false;
    }
#if RGB_MATRIX_TIMEOUT > 0
    if (last_input_activity_elapsed() > (uint32_t)RGB_MATRIX_TIMEOUT) {
        rgb_matrix_set_color_all(0, 0, 0);
        return true;
    }
#endif // RGB_MATRIX_TIMEOUT > 0
    u_int8_t layer = get_highest_layer(layer_state);
    if (layer == LAYER_BASE || layer == LAYER_MAC) layer = get_highest_layer(default_layer_state);
    if (layer < LAYER_ENUM_END) {
        HSV layer_hsv = {
            .h = pgm_read_byte(&ledmaps[layer][RGB_MATRIX_LED_COUNT][0]),
            .s = pgm_read_byte(&ledmaps[layer][RGB_MATRIX_LED_COUNT][1]),
            .v = pgm_read_byte(&ledmaps[layer][RGB_MATRIX_LED_COUNT][2]),
        };
        for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
            HSV hsv = {
                .h = pgm_read_byte(&ledmaps[layer][i][0]),
                .s = pgm_read_byte(&ledmaps[layer][i][1]),
                .v = pgm_read_byte(&ledmaps[layer][i][2]),
            };
            if (HSV_IS_TRANS(hsv)) {
                // "Transparent" color
                RGB rgb = hsv_to_rgb(layer_hsv);
                float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
                rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
            } else if (hsv.h || hsv.s || hsv.v) {
                RGB rgb = hsv_to_rgb(hsv);
                float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
                rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
            } else {
                rgb_matrix_set_color(i, 0, 0, 0);
            }
        }
    } else if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
        rgb_matrix_set_color_all(0, 0, 0);
    }
    return true;
}
#endif // RGB_MATRIX_ENABLE
