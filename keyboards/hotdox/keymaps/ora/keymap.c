#include QMK_KEYBOARD_H
#include "version.h"

// Note: Keycodes must be defined after QMK_KEYBOARD_H for SAFE_RANGE
enum keycodes {
    QWERTY = SAFE_RANGE, COLEMAK, DVORAK, PLOVER, LOWER, RAISE, BACKLIT, EXT_PLV,
    MA_OR, MA_AND, MA_PBRC, MA_PCBR, MA_PPRN, MA_PABK, MA_LMBD, MA_BRNL, MA_PCMT
};

enum tap_dances {
    TAP_DANCE_DYN_MACRO_1 = 0,
    TAP_DANCE_DYN_MACRO_2,
    TAP_DANCE_PLAYPAUSE_SPOTIFY,
    X_TAP_DANCE
};

enum layers {
    LAYER_BASE = 0, LAYER_WIN, LAYER_GAMES,
    LAYER_FUNCTION, LAYER_WINFUN,
    LAYER_SYMBOLS, LAYER_NUMPAD,
    LAYER_ENUM_END
};

#define LAUNCH_APP(string) do { \
    SEND_STRING(MC_LAUNCH); \
    wait_ms(250); \
    SEND_STRING(string); \
    wait_ms(250); \
    SEND_STRING(SS_TAP(X_ENTER)); \
} while (false)

// Platform-specific keys
#define MC_LAUNCH SS_LGUI(" ")
#define MC_LOCK LGUI(LCTL(KC_Q))
#define MC_MNXT KC_MFFD
#define MC_MPLY KC_MPLY
#define MC_MPRV KC_MRWD
#define MC_MUTE KC__MUTE
#define MC_PSCF LGUI(LSFT(KC_4))
#define MC_PSCR LGUI(LCTL(LSFT(KC_4)))
#define MC_VOLD KC__VOLDOWN
#define MC_VOLU KC__VOLUP

#define WN_LAUNCH SS_TAP(X_LGUI)
#define WN_LOCK LGUI(KC_L)
#define WN_MNXT KC_MNXT
#define WN_MPLY KC_MPLY
#define WN_MPRV KC_MPRV
#define WN_MUTE KC_MUTE
#define WN_PSCF LGUI(KC_PSCR)
#define WN_PSCR KC_PSCR
#define WN_VOLD KC_VOLD
#define WN_VOLU KC_VOLU

#define LT_FNES LT(LAYER_FUNCTION, KC_ESC)
#define LT_WFNE LT(LAYER_WINFUN, KC_ESC)
#define LT_SYBS LT(LAYER_SYMBOLS, KC_BSPC)
#define LT_SYEN LT(LAYER_SYMBOLS, KC_ENT)
#define LT_NMPD TT(LAYER_NUMPAD)
#define MT_LSSP LSFT_T(KC_SPC)
#define MT_RSSP RSFT_T(KC_SPC)
#define MT_LCES LCTL_T(KC_ESC)
#define MT_RCEN RCTL_T(KC_ENT)

#define TD_DMC1 TD(TAP_DANCE_DYN_MACRO_1)
#define TD_DMC2 TD(TAP_DANCE_DYN_MACRO_2)
#define TD_PLSP TD(TAP_DANCE_PLAYPAUSE_SPOTIFY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAYER_BASE] = LAYOUT_ergodox_pretty(
    KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,       KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,    KC_EQL,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    MT_LCES, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, MT_RCEN,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,     KC_SCLN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LALT, KC_LEFT, KC_DOWN, KC_RGHT, KC_LGUI,                                        KC_RGUI, MC_MPRV, TD_PLSP, MC_MNXT, KC_RALT,
                                                 LT_NMPD, TD_DMC1,    TD_DMC2, KC_LEAD,
                                        /*-----\ /-----*/ KC_BSPC,    KC_BSPC, /*-----\ /-----*/
                                        MT_LSSP, LT_SYBS, LT_FNES,    LT_FNES, LT_SYEN, MT_RSSP)
,
[LAYER_WIN] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                                        _______, WN_MPRV, WN_MPLY, WN_MNXT, _______,
                                                 _______, _______,    _______, _______,
                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/
                                        _______, _______, LT_WFNE,    LT_WFNE, _______, _______)
,
[LAYER_GAMES] = LAYOUT_ergodox_pretty(
    KC_GRV,  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    KC_LCTL, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,                                          _______, _______, _______, _______, _______,
                                                 TD_DMC1, TD_DMC2,    LT_NMPD, _______,
                                        /*-----\ /-----*/ KC_BSPC,    _______, /*-----\ /-----*/
                                        KC_SPC,  KC_LALT, LT_WFNE,    _______, _______, _______)
,
[LAYER_FUNCTION] = LAYOUT_ergodox_pretty(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    KC_CAPS, XXXXXXX, MC_VOLD, MC_MUTE, MC_VOLU, XXXXXXX, XXXXXXX,    XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  MC_PSCR, KC_CAPS,
    KC_ESC,  XXXXXXX, MC_MPRV, MC_MPLY, MC_MNXT, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, MC_PSCF, KC_ENT,
    KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL,
    _______, _______, KC_UP,   _______, _______,                                        _______, MC_VOLD, MC_MUTE, MC_VOLU, _______,
                                                 RESET,   _______,    _______, MC_LOCK,
                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/
                                        _______, _______, _______,    _______, _______, _______)
,
[LAYER_WINFUN] = LAYOUT_ergodox_pretty(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    KC_CAPS, XXXXXXX, WN_VOLD, WN_MUTE, WN_VOLU, XXXXXXX, XXXXXXX,    XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  WN_PSCR, KC_CAPS,
    KC_ESC,  XXXXXXX, WN_MPRV, WN_MPLY, WN_MNXT, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, WN_PSCF, KC_ENT,
    KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL,
    _______, _______, KC_UP,   _______, _______,                                        _______, WN_VOLD, WN_MUTE, WN_VOLU, _______,
                                                 RESET,   _______,    _______, WN_LOCK,
                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/
                                        _______, _______, _______,    _______, _______, _______)
,
[LAYER_SYMBOLS] = LAYOUT_ergodox_pretty(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,    KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, MA_BRNL, MA_LMBD, _______,
    _______, MA_OR,   KC_PIPE, KC_SLSH, KC_MINS, KC_QUES, KC_UNDS,    KC_PLUS, KC_EXLM, KC_PLUS, KC_ASTR, KC_AMPR, MA_AND,  _______,
    _______, MA_AND,  KC_LBRC, KC_LCBR, KC_LPRN, KC_LABK,                      KC_RABK, KC_RPRN, KC_RCBR, KC_RBRC, MA_OR,   _______,
    _______, XXXXXXX, MA_PBRC, MA_PCBR, MA_PPRN, MA_PABK, KC_TILD,    KC_COLN, MA_PABK, MA_PPRN, MA_PCBR, MA_PBRC, MA_PCMT, _______,
    _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______,
                                                 _______, _______,    _______, MC_LOCK,
                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/
                                        _______, _______, _______,    _______, _______, _______)
,
[LAYER_NUMPAD] = LAYOUT_ergodox_pretty(
     KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, KC_PSLS, XXXXXXX,    XXXXXXX, KC_PSLS, KC_PSLS, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
     KC_NLCK, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PAST, XXXXXXX,    XXXXXXX, KC_PAST, KC_P7,   KC_P8,   KC_P9,   XXXXXXX, KC_NLCK,
     _______, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PMNS,                      KC_PMNS, KC_P4,   KC_P5,   KC_P6,   XXXXXXX, _______,
     _______, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PPLS, KC_PEQL,    KC_PEQL, KC_PPLS, KC_P1,   KC_P2,   KC_P3,   XXXXXXX, _______,
     _______, XXXXXXX, KC_PEQL, KC_PDOT, KC_P0,                                          KC_P0,   KC_PDOT, KC_PEQL, XXXXXXX, _______,
                                                  _______, _______,    _______, _______,
                                         /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/
                                         KC_PENT, _______, _______,    _______, _______, KC_PENT)

//[LAYER_] = LAYOUT_ergodox_pretty(
//    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______,
//                                                 _______, _______,    _______, _______,
//                                        /*-----\ /-----*/ _______,    _______, /*-----\ /-----*/
//                                        _______, _______, _______,    _______, _______, _______)
};

// Functions / Macros {{{

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_dynamic_macro(keycode, record)) { return false; }
    switch (keycode) {
        case MA_OR:
            if (record->event.pressed) {
                SEND_STRING(" || ");
            }
            break;
        case MA_AND:
            if (record->event.pressed) {
                SEND_STRING(" && ");
            }
            break;
        case MA_PBRC:
            if (record->event.pressed) {
                SEND_STRING("[]"SS_TAP(X_LEFT));
            }
            break;
        case MA_PCBR:
            if (record->event.pressed) {
                SEND_STRING("{  }"SS_TAP(X_LEFT)SS_TAP(X_LEFT));
            }
            break;
        case MA_PPRN:
            if (record->event.pressed) {
                SEND_STRING("()"SS_TAP(X_LEFT));
            }
            break;
        case MA_PABK:
            if (record->event.pressed) {
                SEND_STRING("<>"SS_TAP(X_LEFT));
            }
            break;
        case MA_PCMT:
            if (record->event.pressed) {
                SEND_STRING("/*  */"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
            }
            break;
        case MA_LMBD:
            if (record->event.pressed) {
                SEND_STRING("() => {  }"SS_TAP(X_LEFT)SS_TAP(X_LEFT));
            }
            break;
        case MA_BRNL:
            if (record->event.pressed) {
                SEND_STRING("{"SS_TAP(X_ENTER)SS_TAP(X_ENTER)"}"SS_TAP(X_UP)SS_TAP(X_END));
            }
            break;
    }
    return true;
}

void dance_dynamic_macro_1(qk_tap_dance_state_t *state, void *user_data) {
    keyrecord_t kr;
    if (state->count == 1) {
        kr.event.pressed = false;
        process_dynamic_macro(DYN_MACRO_PLAY1, &kr);
    } else if (state->count == 2) {
        kr.event.pressed = true;
        process_dynamic_macro(DYN_REC_STOP, &kr);
    } else if (state->count == 3) {
        kr.event.pressed = false;
        process_dynamic_macro(DYN_REC_START1, &kr);
    }
}

void dance_dynamic_macro_2(qk_tap_dance_state_t *state, void *user_data) {
    keyrecord_t kr;
    if (state->count == 1) {
        kr.event.pressed = false;
        process_dynamic_macro(DYN_MACRO_PLAY2, &kr);
    } else if (state->count == 2) {
        kr.event.pressed = true;
        process_dynamic_macro(DYN_REC_STOP, &kr);
    } else if (state->count == 3) {
        kr.event.pressed = false;
        process_dynamic_macro(DYN_REC_START2, &kr);
    }
}

void dance_playpause_spotify(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(MC_MPLY);
    } else if (state->count == 2) {
        LAUNCH_APP("spotify");
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TAP_DANCE_DYN_MACRO_1] = ACTION_TAP_DANCE_FN(dance_dynamic_macro_1),
    [TAP_DANCE_DYN_MACRO_2] = ACTION_TAP_DANCE_FN(dance_dynamic_macro_2),
    [TAP_DANCE_PLAYPAUSE_SPOTIFY] = ACTION_TAP_DANCE_FN(dance_playpause_spotify),
};


LEADER_EXTERNS();
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        SEQ_ONE_KEY(KC_A) { LAUNCH_APP("cisco any"); return; }
        SEQ_ONE_KEY(KC_C) { LAUNCH_APP("chime");     return; }
        SEQ_ONE_KEY(KC_E) { LAUNCH_APP("excel");     return; }
        SEQ_ONE_KEY(KC_F) { LAUNCH_APP("firefox");   return; }
        SEQ_ONE_KEY(KC_G) { layer_move(LAYER_BASE); layer_on(LAYER_WIN); layer_on(LAYER_GAMES); return; }
        SEQ_ONE_KEY(KC_H) { LAUNCH_APP("chrome");    return; }
        SEQ_ONE_KEY(KC_M) { layer_move(LAYER_BASE);  return; }
        SEQ_ONE_KEY(KC_N) { LAUNCH_APP("stickies");  return; }
        SEQ_ONE_KEY(KC_O) { LAUNCH_APP("outlook");   return; }
        SEQ_ONE_KEY(KC_R) { LAUNCH_APP("reminders"); return; }
        SEQ_ONE_KEY(KC_S) { LAUNCH_APP("slack");     return; }
        SEQ_ONE_KEY(KC_T) { LAUNCH_APP("iterm");     return; }
        SEQ_ONE_KEY(KC_U) { LAUNCH_APP("neovim");    return; }
        SEQ_ONE_KEY(KC_V) { LAUNCH_APP("vimr");      return; }
        SEQ_ONE_KEY(KC_W) { layer_move(LAYER_BASE); layer_on(LAYER_WIN); return; }
    }
}

// }}}

// vim: foldmethod=marker cursorcolumn
