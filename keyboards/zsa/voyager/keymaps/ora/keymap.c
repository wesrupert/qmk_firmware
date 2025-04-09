// Copyright 2024 Wes Rupert (@wesrupert)
// SPDX-License-Identifier: GPL-3.0-or-later
#include "action_layer.h"
#include "ora.h"

enum layers {
    LAYER_FUNCTION = LAYER_ENUM_END_USER,
    LAYER_NUMPAD,
    LAYER_ENUM_END,
};

enum tap_dances {
    TAP_DANCE_LEADER_RGUI = 0,
    TAP_DANCE_DMCRO1_LCTL,
    TAP_DANCE_DMCRO2_RCTL,
    TAP_DANCE_BS_NMPD_OFF,
    X_TAP_DANCE
};

// Advance key aliases
#define LI_ANIT RGB_TOG
#define LI_LDLT LED_LEVEL
#define LI_LYRT TOGGLE_LAYER_COLOR
#define LT_FNEN LT(LAYER_FUNCTION, KC_ENT)
#define LT_FNES LT(LAYER_FUNCTION, KC_ESC)
#define MT_LAEQ LALT_T(KC_EQL)
#define MT_LCMN LCTL_T(KC_MINS)
#define MT_RABL RALT_T(KC_BSLS)
#define MT_RCSN RCTL_T(KC_SCLN)
#define TD_LCM1 TD(TAP_DANCE_DMCRO1_LCTL)
#define TD_RCM2 TD(TAP_DANCE_DMCRO2_RCTL)
#define TD_RGLD TD(TAP_DANCE_LEADER_RGUI)
#define TG_NMPD TG(LAYER_NUMPAD)
#define TT_FUNC TT(LAYER_FUNCTION)
#define TT_NUMP TT(LAYER_NUMPAD)

// Include after key definitions in order to use them in the def file.
#include "g/keymap_combo.h"

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
    KC_DEL,  __________________QWER_L1__________________,    __________________QWER_R1__________________, KC_BSPC, \
    MT_LGTB, __________________QWER_L2__________________,    __________________QWER_R2__________________, TD_RGLD, \
    MT_LCMN, __________________QWER_L3__________________,    _____________QWER__R3_____________, KC_QUOT, MT_RCSN, \
    MT_LAEQ, __________________QWER_L4__________________,    __________________QWER_R4__________________, MT_RABL, \
                                        LT_FNES, MT_LSSP,    MT_RSSP, LT_FNEN)
#define _CL_BASE [LAYER_BASE] = CL(                                                                                \
    CK_WARN, R_RED,   R_ORANG, R_YELLW, R_YLGRN, R_GREEN,    R_AQGRN, R_AQUA,  R_AQBLU, R_BLUE,  R_PURPL, CK_WARN, \
    CK_MODT, R_RED,   R_ORANG, R_YELLW, R_YLGRN, R_GREEN,    R_AQGRN, R_AQUA,  R_AQBLU, R_BLUE,  R_PURPL, CK_META, \
    CK_MODT, R_RED,   R_ORANG, R_YELLW, R_YLGRN, R_GREEN,    R_AQGRN, R_AQUA,  R_AQBLU, R_BLUE,  R_PURPL, CK_MODT, \
    CK_MODT, R_RED,   R_ORANG, R_YELLW, R_YLGRN, R_GREEN,    R_AQGRN, R_AQUA,  R_AQBLU, R_BLUE,  R_PURPL, CK_MODT, \
                                        CL_FUNC, C______,    C______, CL_FUNC,                            CL_BASE)

#define _KL_GRAPHITE [LAYER_GRAPHITE] = KL( /*         GRAPHITE                                                 */ \
    KC_DEL,  __________________GRPH_L1__________________,    __________________GRPH_R1__________________, KC_BSPC, \
    MT_LGTB, __________________GRPH_L2__________________,    KC_QUOT, _____________GRPH__R2_____________, TD_RGLD, \
    MT_LCMN, __________________GRPH_L3__________________,    __________________GRPH_R3__________________, MT_RCSN, \
    MT_LAEQ, __________________GRPH_L4__________________,    __________________GRPH_R4__________________, MT_RABL, \
                                        LT_FNES, MT_LSSP,    MT_RSSP, LT_FNEN)
#define _CL_GRAPHITE [LAYER_GRAPHITE] = CL(                                                                        \
    CK_WARN, R_PURPL, R_BLUE,  R_AQBLU, R_AQUA,  R_AQGRN,    R_GREEN, R_YLGRN, R_YELLW, R_ORANG, R_RED,   CK_WARN, \
    CK_MODT, R_PURPL, R_BLUE,  R_AQBLU, R_AQUA,  R_AQGRN,    R_GREEN, R_YLGRN, R_YELLW, R_ORANG, R_RED,   CK_META, \
    CK_MODT, R_PURPL, R_BLUE,  R_AQBLU, R_AQUA,  R_AQGRN,    R_GREEN, R_YLGRN, R_YELLW, R_ORANG, R_RED,   CK_MODT, \
    CK_MODT, R_PURPL, R_BLUE,  R_AQBLU, R_AQUA,  R_AQGRN,    R_GREEN, R_YLGRN, R_YELLW, R_ORANG, R_RED,   CK_MODT, \
                                        CL_FUNC, C______,    C______, CL_FUNC,                            CL_BASE)

#define _KL_GAMES [LAYER_GAMES] = KL( /*                 GAME                                                   */ \
    KC_GRV,  __________________QWER_L1__________________,    __________________QWER_R1__________________, KC_BSPC, \
    KC_TAB,  __________________QWER_L2__________________,    __________________QWER_R2__________________, TD_RGLD, \
    KC_LCTL, __________________QWER_L3__________________,    _____________QWER__R3_____________, KC_QUOT, KC_QUOT, \
    KC_LALT, __________________QWER_L4__________________,    __________________QWER_R4__________________, KC_BSLS, \
                                        KC_LSFT, KC_SPC,     MT_RSSP, LT_FNEN)
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
                                        TT_NUMP, KC_BSPC,    KC_DEL,  CW_TOGG)
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { _KL_BASE, _KL_GRAPHITE, _KL_GAMES, _KL_FUNCTION, _KL_NUMPAD };

#if defined(RGB_MATRIX_ENABLE)
const uint8_t PROGMEM ledmaps[][RGB_MATRIX_LED_COUNT+1][3] = { _CL_BASE, _CL_GRAPHITE, _CL_GAMES, _CL_FUNCTION, _CL_NUMPAD };
#endif // RGB_MATRIX_ENABLE

// clang-format on

DANCE_LEADER_MOD(RGUI)
DANCE_MACRO_MOD(1, LCTL)
DANCE_MACRO_MOD(2, RCTL)

tap_dance_action_t tap_dance_actions[] = {
    [TAP_DANCE_LEADER_RGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_LEADER_RGUI_finished, dance_LEADER_RGUI_reset),
    [TAP_DANCE_DMCRO1_LCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_DMCRO1_LCTL_finished, dance_DMCRO1_LCTL_reset),
    [TAP_DANCE_DMCRO2_RCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_DMCRO2_RCTL_finished, dance_DMCRO2_RCTL_reset),
};

bool keyboard_post_init_keymap(void) {
#if defined(RGB_MATRIX_ENABLE)
    if (!keyboard_config.disable_layer_led) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    }
#endif // RGB_MATRIX_ENABLE
    return true;
}

bool leader_end_keymap(void) {
    /* Layr: Base */ if (leader_sequence_two_keys(KC_L, KC_D) || leader_sequence_two_keys(KC_L, KC_L)) { set_single_default_layer(LAYER_BASE); layer_move(LAYER_BASE); return false; }
    /* Layr: Grph */ if (leader_sequence_two_keys(KC_L, KC_G) || leader_sequence_two_keys(KC_L, KC_I)) { set_single_default_layer(LAYER_GRAPHITE); layer_move(LAYER_GRAPHITE); return false; }
    /* Layr: Func */ if (leader_sequence_two_keys(KC_L, KC_F) || leader_sequence_two_keys(KC_L, KC_K)) { layer_move(LAYER_BASE); layer_on(LAYER_FUNCTION); return false; }
    /* Layr: Nump */ if (leader_sequence_two_keys(KC_L, KC_N) || leader_sequence_two_keys(KC_L, KC_I)) { layer_move(LAYER_BASE); layer_on(LAYER_NUMPAD); return false; }
    /* Layr: Grph */ if (leader_sequence_two_keys(KC_L, KC_G)) { set_single_default_layer(LAYER_GRAPHITE); layer_move(LAYER_GRAPHITE); return false; }
    /* Dflt: Qwer */ if (leader_sequence_two_keys(KC_D, KC_Q)) { set_single_persistent_default_layer(LAYER_BASE); return false; }
    /* Dflt: Grph */ if (leader_sequence_two_keys(KC_D, KC_G)) { set_single_persistent_default_layer(LAYER_GRAPHITE); return false; }
    return true;
}

#if defined(COMBO_SHOULD_TRIGGER)

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    int layer = get_highest_layer(layer_state);
    if (layer == LAYER_BASE) layer = get_highest_layer(default_layer_state);
    if (layer == LAYER_BASE) {
        switch (combo_index) {
        case COMBO_GRPH_AND:
        case COMBO_GRPH_LBRC:
        case COMBO_GRPH_LCBR:
        case COMBO_GRPH_LPRN:
        case COMBO_GRPH_LABK:
        case COMBO_GRPH_RABK:
        case COMBO_GRPH_RPRN:
        case COMBO_GRPH_RCBR:
        case COMBO_GRPH_RBRC:
        case COMBO_GRPH_OR:
        case COMBO_GRPH_GRV:
        case COMBO_GRPH_EXLM:
        case COMBO_GRPH_AT:
        case COMBO_GRPH_HASH:
        case COMBO_GRPH_DLR:
        case COMBO_GRPH_PERC:
        case COMBO_GRPH_CIRC:
        case COMBO_GRPH_AMPR:
        case COMBO_GRPH_ASTR:
        case COMBO_GRPH_PIPE:
        case COMBO_GRPH_PLUS:
        case COMBO_GRPH_RSET:
            return false;
        default: return true;
        }
    } else if (layer == LAYER_GRAPHITE) {
        switch (combo_index) {
        case COMBO_QWER_AND:
        case COMBO_QWER_LBRC:
        case COMBO_QWER_LCBR:
        case COMBO_QWER_LPRN:
        case COMBO_QWER_LABK:
        case COMBO_QWER_RABK:
        case COMBO_QWER_RPRN:
        case COMBO_QWER_RCBR:
        case COMBO_QWER_RBRC:
        case COMBO_QWER_OR:
        case COMBO_QWER_GRV:
        case COMBO_QWER_EXLM:
        case COMBO_QWER_AT:
        case COMBO_QWER_HASH:
        case COMBO_QWER_DLR:
        case COMBO_QWER_PERC:
        case COMBO_QWER_CIRC:
        case COMBO_QWER_AMPR:
        case COMBO_QWER_ASTR:
        case COMBO_QWER_PIPE:
        case COMBO_QWER_PLUS:
        case COMBO_QWER_RSET:
            return false;
        default: return true;
        }
    }
    return false;
}

#endif // COMBO_SHOULD_TRIGGER

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
    if (layer == LAYER_BASE) layer = get_highest_layer(default_layer_state);
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
