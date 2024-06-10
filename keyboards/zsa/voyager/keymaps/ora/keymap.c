// Copyright 2024 Wes Rupert (@wesrupert)
// SPDX-License-Identifier: GPL-3.0-or-later
#include "ora.h"
#include "g/keymap_combo.h"

enum layers {
    LAYER_FUNCTION = LAYER_ENUM_END_USER,
    LAYER_NUMPAD,
    LAYER_ENUM_END,
};

enum tap_dances {
    TAP_DANCE_ESC_LD_SYMB = 0,
    TAP_DANCE_LEADER_RGUI,
    TAP_DANCE_DMCRO1_LCTL,
    TAP_DANCE_DMCRO2_RCTL,
    TAP_DANCE_KTAB_NUMPAD,
    TAP_DANCE_ESC_NMPD_FF,
    TAP_DANCE_NUMPAD_FNOF,
    X_TAP_DANCE
};

// Advance key aliases
#define LI_ANIT RGB_TOG
#define LI_LDLT LED_LEVEL
#define LI_LYRT TOGGLE_LAYER_COLOR
#define LT_FNEN LT(LAYER_FUNCTION, KC_ENT)
#define LT_FNES LT(LAYER_FUNCTION, KC_ESC)
#define TT_NUMP TT(LAYER_NUMPAD)
#define MT_LGEQ LGUI_T(KC_EQL)
#define MT_LATB LALT_T(KC_TAB)
#define MT_LCMN LCTL_T(KC_MINS)
#define MT_RABL RALT_T(KC_BSLS)
#define MT_RCQU RCTL_T(KC_QUOT)
#define MT_LAGV LALT_T(KC_GRV)
#define TD_LCM1 TD(TAP_DANCE_DMCRO1_LCTL)
#define TD_TBNP TD(TAP_DANCE_KTAB_NUMPAD)
#define TD_ESNP TD(TAP_DANCE_ESC_NMPD_FF)
#define TD_RGLD TD(TAP_DANCE_LEADER_RGUI)
#define TD_RCM2 TD(TAP_DANCE_DMCRO2_RCTL)
#define TG_NUMP TG(LAYER_NUMPAD)
#define TT_FUNC TT(LAYER_FUNCTION)

// Expand key groups before passing into layout macro.
#define KL(...) LAYOUT(__VA_ARGS__)

// Expand LED matrixes like keymaps.
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

// clang-format off

#define _KL_BASE [LAYER_BASE] = KL( /*                   BASE                                                   */ \
    MT_LAGV, __________________QWER_L1__________________,    __________________QWER_R1__________________, KC_BSPC, \
    TD_TBNP, __________________QWER_L2__________________,    __________________QWER_R2__________________, MT_RABL, \
    MT_LCMN, __________________QWER_L3__________________,    _____________QWER__R3_____________, KC_SCLN, MT_RCQU, \
    MT_LGEQ, __________________QWER_L4__________________,    __________________QWER_R4__________________, TD_RGLD, \
                                        LT_FNES, MT_LSSP,    MT_RSSP, LT_FNEN)
#define _CL_BASE [LAYER_BASE] = CL(                                                                                \
    CK_MODT, R_RED,   R_ORANG, R_YELLW, R_YLGRN, R_GREEN,    R_AQGRN, R_AQUA,  R_AQBLU, R_BLUE,  R_PURPL, CK_WARN, \
    CL_NMPD, R_RED,   R_ORANG, R_YELLW, R_YLGRN, R_GREEN,    R_AQGRN, R_AQUA,  R_AQBLU, R_BLUE,  R_PURPL, CK_MODT, \
    CK_MODT, R_RED,   R_ORANG, R_YELLW, R_YLGRN, R_GREEN,    R_AQGRN, R_AQUA,  R_AQBLU, R_BLUE,  R_PURPL, CK_MODT, \
    CK_MODT, R_RED,   R_ORANG, R_YELLW, R_YLGRN, R_GREEN,    R_AQGRN, R_AQUA,  R_AQBLU, R_BLUE,  R_PURPL, CK_META, \
                                        CL_FUNC, C______,    C______, CL_FUNC,                            CL_BASE)

#define _KL_GAMES [LAYER_GAMES] = KL( /*                 GAME                                                   */ \
    KC_TAB,  _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, \
    KC_GRV,  _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, KC_BSLS, \
    KC_LCTL, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, KC_QUOT, \
    KC_LALT, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, \
                                        KC_LSFT, KC_SPC,     _______, _______)
#define _CL_GAMES [LAYER_GAMES] = CL(                                                                              \
    CK_ALPH, R_RED,   R_ORANG, R_YELLW, R_YLGRN, R_GREEN,    R_AQGRN, R_AQUA,  R_AQBLU, R_BLUE,  R_PURPL, CK_WARN, \
    CK_ALPH, R_RED,   C______, R_YELLW, R_YLGRN, R_GREEN,    R_AQGRN, R_AQUA,  R_AQBLU, R_BLUE,  R_PURPL, CK_MODS, \
    CK_MODS, C______, C______, C______, R_YLGRN, R_GREEN,    R_AQGRN, R_AQUA,  R_AQBLU, R_BLUE,  R_PURPL, CK_MODS, \
    CK_MODS, R_RED,   R_ORANG, R_YELLW, R_YLGRN, R_GREEN,    R_AQGRN, R_AQUA,  R_AQBLU, R_BLUE,  R_PURPL, CK_META, \
                                        CK_MODS, CK_ALPH,    CK_ALPH, CL_FUNC,                            CL_GAME)

#define _KL_FUNCTION [LAYER_FUNCTION] = KL( /*         FUNCTION                                                 */ \
    FUNC_11, __________________FUNC_L1__________________,    __________________FUNC_R1__________________, FUNC_12, \
    KC_LALT, KC_BTN2, _____________FUNC__L2_____________,    _____________FUNC__R2_____________, PK_PSCR, KC_RALT, \
    KC_LCTL, KC_BTN1, _____________FUNC__L3_____________,    _____________FUNC__R3_____________, PK_PSCF, KC_RCTL, \
    KC_LGUI, TD_LCM1, __________MEDIA__________, PK_LOCK,    PK_LOCK, __________VOLUM__________, TD_RCM2, KC_RGUI, \
                                        TT_NUMP, CW_TOGG,    CW_TOGG, KC_DEL)
#define _CL_FUNCTION [LAYER_FUNCTION] = CL(                                                                        \
    C______, C______, C______, C______, C______, C______,    C______, C______, C______, C______, C______, C______, \
    CK_MODS, CK_MOUS, CK_NAVG, CK_NAVG, CK_NAVG, CK_NAVG,    CK_NAVG, CK_NAVG, CK_NAVG, CK_NAVG, CK_META, CK_MODS, \
    CK_MODS, CK_MOUS, CK_NAVG, CK_NAVG, CK_NAVG, CK_NAVG,    CK_NAVG, CK_NAVG, CK_NAVG, CK_NAVG, CK_META, CK_MODS, \
    CK_MODS, CK_MODT, CK_MDIA, CK_MDIA, CK_MDIA, CK_WARN,    CK_WARN, CK_MDIA, CK_MDIA, CK_MDIA, CK_MODT, CK_MODS, \
                                        CL_NMPD, CK_MODS,    CK_MODS, CK_WARN,                            CL_FUNC)

#define _KL_NUMPAD [LAYER_NUMPAD] = KL( /*        NUMPAD  /  LIGHTS                                             */ \
    TD_ESNP, KC_PSLS, __________NMPD_1_________, KC_PMNS,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_DEL,  KC_PAST, __________NMPD_2_________, KC_PPLS,    XXXXXXX, LI_HUEU, LI_HUED, LI_ANIT, LI_LYRT, KC_RGUI, \
    KC_BSPC, KC_UP,   __________NMPD_3_________, KC_PEQL,    LI_PREV, LI_SATU, LI_SATD, LI_NEXT, LI_LDLT, KC_RCTL, \
    KC_LEFT, KC_DOWN, KC_RGHT, NMPD__4, KC_PDOT, KC_PENT,    LI_SLOW, LI_VALU, LI_VALD, LI_FAST, XXXXXXX, KC_RALT, \
                                        MT_LATB, MT_LSSP,    MT_RCEN, TG_NUMP)
#define _CL_NUMPAD [LAYER_NUMPAD] = CL(                                                                            \
    CK_WARN, CK_ALPH, C______, C______, C______, CK_ALPH,    C_XXXXX, C_XXXXX, C_XXXXX, C_XXXXX, C_XXXXX, C_XXXXX, \
    CK_WARN, CK_ALPH, C______, C______, C______, CK_ALPH,    C_XXXXX, C______, C______, C______, C______, CK_MODS, \
    CK_WARN, CK_NAVG, C______, C______, C______, CK_ALPH,    C______, C______, C______, C______, C______, CK_MODS, \
    CK_NAVG, CK_NAVG, CK_NAVG, C______, C______, CK_ALPH,    C______, C______, C______, C______, C_XXXXX, CK_MODS, \
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { _KL_BASE, _KL_GAMES, _KL_FUNCTION, _KL_NUMPAD };

#if defined(RGB_MATRIX_ENABLE)
const uint8_t PROGMEM ledmaps[][RGB_MATRIX_LED_COUNT+1][3] = { _CL_BASE, _CL_GAMES, _CL_FUNCTION, _CL_NUMPAD };
#endif // RGB_MATRIX_ENABLE

// clang-format on

DANCE_LEADER_MOD(RGUI)
DANCE_MACRO_MOD(1, LCTL)
DANCE_MACRO_MOD(2, RCTL)

// Simulate tap-toggle for tab/numpad. The finished callback also adds a
// single-tap action to disable the function layer.
td_state_t dance_ktab_numpad_state = 0;
static void dance_ktab_numpad_finished(tap_dance_state_t *state, void *user_data) {
    switch (dance_ktab_numpad_state = cur_dance(state)) {
        case TD_SINGLE_TAP:
            register_code16(KC_TAB);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            tap_code16(KC_TAB);
            register_code16(KC_TAB);
            break;
        case TD_SINGLE_HOLD:
        default:
            layer_on(LAYER_NUMPAD);
            break;
    }
}
static void dance_ktab_numpad_reset(tap_dance_state_t *state, void *user_data) {
    switch (dance_ktab_numpad_state) {
        case TD_SINGLE_TAP:
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code16(KC_TAB);
            break;
        case TD_SINGLE_HOLD:
            layer_off(LAYER_NUMPAD);
            break;
        default:
            break;
    }
}

td_state_t dance_esc_nmpd_ff_state = 0;
static void dance_esc_nmpd_ff_finished(tap_dance_state_t *state, void *user_data) {
    dance_esc_nmpd_ff_state = cur_dance(state);
    if (dance_esc_nmpd_ff_state == TD_SINGLE_TAP) {
        register_code16(KC_ESC);
    }
}
static void dance_esc_nmpd_ff_reset(tap_dance_state_t *state, void *user_data) {
    switch (dance_esc_nmpd_ff_state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_ESC);
            break;
        default:
            layer_off(LAYER_NUMPAD);
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TAP_DANCE_LEADER_RGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_LEADER_RGUI_finished, dance_LEADER_RGUI_reset),
    [TAP_DANCE_DMCRO1_LCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_DMCRO1_LCTL_finished, dance_DMCRO1_LCTL_reset),
    [TAP_DANCE_DMCRO2_RCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_DMCRO2_RCTL_finished, dance_DMCRO2_RCTL_reset),
    [TAP_DANCE_KTAB_NUMPAD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_ktab_numpad_finished, dance_ktab_numpad_reset),
    [TAP_DANCE_ESC_NMPD_FF] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_esc_nmpd_ff_finished, dance_esc_nmpd_ff_reset),
};

bool keyboard_post_init_keymap(void) {
#if defined(RGB_MATRIX_ENABLE)
    if (!keyboard_config.disable_layer_led) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    }
#endif // RGB_MATRIX_ENABLE
    return true;
}

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
    int layer = get_highest_layer(layer_state);
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
