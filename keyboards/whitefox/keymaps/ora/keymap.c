#include "whitefox.h"

// Note: Keycodes must be defined after whitefox.h for SAFE_RANGE
enum keycodes {
    QWERTY = SAFE_RANGE, COLEMAK, DVORAK, PLOVER, LOWER, RAISE, BACKLIT, EXT_PLV,
    MA_OR, MA_AND, MA_PBRC, MA_PCBR, MA_PPRN, MA_PABK, MA_LMBD, MA_BRNL, MA_PCMT
};

enum tap_dances {
    TAP_DANCE_LAYERS = 0,
    TAP_DANCE_DYN_MACRO,
    X_TAP_DANCE
};

enum layers {
    /* Shared maps */ LAYER_SHAREDUSE = 0, LAYER_GAMES, LAYER_WINNAV,
    /* Personal maps */ LAYER_DEVELOPMENT, LAYER_NUMPAD, LAYER_MACNAV, LAYER_SYMBOLS,
    LAYER_ENUM_END
};

// Platform-specific keys
#define MC_LAUNCH SS_LGUI(" ")
#define MC_LLMD KC_LALT
#define MC_LOCK LGUI(LCTL(KC_Q))
#define MC_LRMD KC_LGUI
#define MC_MNXT KC_MFFD
#define MC_MPLY KC_MPLY
#define MC_MPRV KC_MRWD
#define MC_MUTE KC__MUTE
#define MC_PSCF LGUI(LSFT(KC_4))
#define MC_PSCR LGUI(LCTL(LSFT(KC_4)))
#define MC_RLMD KC_RGUI
#define MC_RRMD KC_RALT
#define MC_VOLD KC__VOLDOWN
#define MC_VOLU KC__VOLUP

#define WN_LAUNCH SS_TAP(X_LGUI)
#define WN_LLMD KC_LGUI
#define WN_LOCK LGUI(KC_L)
#define WN_LRMD KC_LALT
#define WN_MNXT KC_MNXT
#define WN_MPLY KC_MPLY
#define WN_MPRV KC_MPRV
#define WN_MUTE KC_MUTE
#define WN_PSCF LGUI(KC_PSCR)
#define WN_PSCR KC_PSCR
#define WN_RLMD KC_RALT
#define WN_RRMD KC_RGUI
#define WN_VOLD KC_VOLD
#define WN_VOLU KC_VOLU

// XY_ABCD alternates
#define __MIS__ KC_NO

#define DM_RCRD DYN_REC_START1
#define DM_STOP DYN_REC_STOP

#define FN_SYSP LT(LAYER_SYMBOLS, KC_SPC)
#define FN_NVES LT(LAYER_MACNAV, KC_ESC)
#define FN_DEVL DF(LAYER_DEVELOPMENT)
#define FN_GAME DF(LAYER_GAMES)
#define FN_SHRD DF(LAYER_SHAREDUSE)

#define WN_NVCA LT(LAYER_WINNAV, KC_CAPS)
#define WN_NVES LT(LAYER_WINNAV, KC_ESC)

#define TD_LYRS TD(TAP_DANCE_LAYERS)
#define TD_DYMC TD(TAP_DANCE_DYN_MACRO)
#define LYRS_DEFAULT KC_LCTL

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAYER_SHAREDUSE] = LAYOUT(
    KC_ESC,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,KC_GRV, WN_LOCK,
    KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,      KC_DEL,
    WN_NVCA,      KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,__MIS__,  KC_ENT,   KC_PGUP,
    KC_LSFT,__MIS__,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,     KC_RSFT,     KC_UP,  KC_PGDN,
    KC_LCTL,WN_LLMD,WN_LRMD,                        KC_SPC,                         WN_RLMD,WN_RRMD,__MIS__,  KC_LEFT,KC_DOWN,KC_RGHT),

[LAYER_GAMES] = LAYOUT(
    KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,KC_DEL, WN_LOCK,
    KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,      KC_DEL,
    WN_NVES,      KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,__MIS__,  KC_ENT,   KC_PGUP,
    KC_LSFT,__MIS__,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,     KC_RSFT,     KC_UP,  KC_PGDN,
    KC_LCTL,WN_LLMD,WN_LRMD,                        KC_SPC,                         WN_RLMD,WN_RRMD,__MIS__,  KC_LEFT,KC_DOWN,KC_RGHT),

[LAYER_WINNAV] = LAYOUT(
    KC_GRV,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_DEL, TD_DYMC,WN_LOCK,
    KC_CAPS,    WN_MPRV,WN_MPLY,WN_MNXT,XXXXXXX,XXXXXXX,KC_HOME,KC_PGDN,KC_PGUP,KC_END, WN_PSCR,WN_PSCF,XXXXXXX,XXXXXXX,      DM_STOP,
    KC_CAPS,      WN_VOLD,WN_MUTE,WN_VOLU,XXXXXXX,XXXXXXX,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,XXXXXXX,XXXXXXX,__MIS__,  WN_MUTE,  KC_HOME,
    _______,__MIS__,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,FN_SHRD,FN_GAME,FN_DEVL,     WN_MPLY,     WN_VOLU,KC_END,
    KC_TRNS,_______,_______,                        _______,                        _______,_______,__MIS__,  WN_MPRV,WN_VOLD,WN_MNXT),

[LAYER_DEVELOPMENT] = LAYOUT(
    KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,KC_DEL, TD_DYMC,
    KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,      KC_LEAD,
    FN_NVES,      KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,__MIS__,  KC_ENT,   KC_HOME,
    KC_LSFT,__MIS__,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,     KC_RSFT,     KC_UP,  KC_END,
    TD_LYRS,MC_LLMD,MC_LRMD,                        FN_SYSP,                        MC_RLMD,MC_RRMD,__MIS__,  KC_LEFT,KC_DOWN,KC_RGHT),

[LAYER_NUMPAD] = LAYOUT(
    KC_NLCK,  KC_PMNS,KC_PPLS,KC_PSLS,KC_PAST,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
    KC_BSPC,    KC_P7,  KC_P8,  KC_P9,  KC_PEQL,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,      XXXXXXX,
    _______,      KC_P4,  KC_P5,  KC_P6,  KC_PCMM,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,__MIS__,  _______,  _______,
    _______,__MIS__,KC_P1,  KC_P2,  KC_P3,  KC_PDOT,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,     _______,     _______,_______,
    KC_TRNS,_______,KC_P0,                          KC_PENT,                        _______,_______,__MIS__,  _______,_______,_______),

[LAYER_MACNAV] = LAYOUT(
    KC_GRV,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_DEL, DM_RCRD,MC_LOCK,
    KC_CAPS,    MC_MPRV,MC_MPLY,MC_MNXT,XXXXXXX,XXXXXXX,KC_HOME,KC_PGDN,KC_PGUP,KC_END, MC_PSCR,MC_PSCF,XXXXXXX,XXXXXXX,      DM_STOP,
    KC_CAPS,      MC_VOLD,MC_MUTE,MC_VOLU,XXXXXXX,XXXXXXX,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,XXXXXXX,XXXXXXX,__MIS__,  MC_MUTE,  KC_PGUP,
    _______,__MIS__,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,FN_SHRD,FN_GAME,FN_DEVL,     MC_MPLY,     MC_VOLU,KC_PGDN,
    KC_TRNS,_______,_______,                        _______,                        _______,_______,__MIS__,  MC_MPRV,MC_VOLD,MC_MNXT),

[LAYER_SYMBOLS] = LAYOUT(
    KC_TILD,  KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_UNDS,KC_PLUS,KC_PIPE,XXXXXXX,MC_LOCK,
    _______,    MA_AND, KC_PIPE,KC_SLSH,KC_MINS,KC_QUES,KC_EXLM,KC_PLUS,KC_ASTR,KC_AMPR,XXXXXXX,XXXXXXX,XXXXXXX,_______,      XXXXXXX,
    _______,      MA_OR,  KC_LBRC,KC_LCBR,KC_LPRN,KC_LABK,KC_RABK,KC_RPRN,KC_RCBR,KC_RBRC,KC_COLN,KC_DQUO,__MIS__,  _______,  _______,
    XXXXXXX,__MIS__,MA_PBRC,MA_PCBR,MA_PPRN,MA_PABK,KC_BSPC,KC_DEL, MA_LMBD,MA_BRNL,MA_PCMT,XXXXXXX,     XXXXXXX,     _______,_______,
    KC_TRNS,_______,_______,                        _______,                        _______,_______,__MIS__,  _______,_______,_______),

/* [LAYER_TYPE] = LAYOUT(
    _______,  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_TRNS,_______,
    _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,      _______,
    _______,      _______,_______,_______,___F___,_______,_______,___J___,_______,_______,_______,_______,__MIS__,  _______,  _______,
    _______,__MIS__,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,     _______,_______,
    KC_TRNS,_______,_______,                        _______,                        _______,_______,__MIS__,  _______,_______,_______), */
};

// Functions / Macros {{{

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_dynamic_macro(keycode, record)) { return false; }
    switch (keycode) {
        case MA_OR:
            if (record->event.pressed) {
                SEND_STRING("||");
            }
            break;
        case MA_AND:
            if (record->event.pressed) {
                SEND_STRING("&&");
            }
            break;
        case MA_PBRC:
            if (record->event.pressed) {
                SEND_STRING("[]"SS_TAP(X_LEFT));
            }
            break;
        case MA_PCBR:
            if (record->event.pressed) {
                SEND_STRING("{}"SS_TAP(X_LEFT));
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

void dance_layers(qk_tap_dance_state_t *state, void *user_data) {
    if (state->pressed || state->count == 1) { register_code(LYRS_DEFAULT); }
}

void dance_layers_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code(LYRS_DEFAULT);

    // Compare against count to skip shared layers.
    int selected_layer = state->count + LAYER_DEVELOPMENT - 1;
    for (int i = LAYER_DEVELOPMENT; i < LAYER_ENUM_END; i++) {
        if (i == selected_layer) { layer_on(i); } else { layer_off(i); }
    }
}

void dance_dynamic_macro(qk_tap_dance_state_t *state, void *user_data) {
    keyrecord_t kr;
    if (state->count == 1)
    {
        kr.event.pressed = false;
        process_dynamic_macro(DYN_MACRO_PLAY1, &kr);
    }
    else if (state->count == 2)
    {
        kr.event.pressed = true;
        process_dynamic_macro(DYN_REC_STOP, &kr);
    }
    else if (state->count == 3)
    {
        kr.event.pressed = false;
        process_dynamic_macro(DYN_REC_START1, &kr);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TAP_DANCE_LAYERS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_layers, dance_layers_reset),
    [TAP_DANCE_DYN_MACRO] = ACTION_TAP_DANCE_FN(dance_dynamic_macro),
};

#define LAUNCH_APP(string) SEND_STRING(MC_LAUNCH string SS_TAP(X_ENTER))

LEADER_EXTERNS();
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;

        SEQ_THREE_KEYS (KC_L, KC_P, KC_D) { set_single_persistent_default_layer(LAYER_DEVELOPMENT); return; }
        SEQ_THREE_KEYS (KC_L, KC_P, KC_G) { set_single_persistent_default_layer(LAYER_GAMES);       return; }
        SEQ_THREE_KEYS (KC_L, KC_P, KC_S) { set_single_persistent_default_layer(LAYER_SHAREDUSE);   return; }

        SEQ_TWO_KEYS (KC_L, KC_F) { layer_invert (LAYER_MACNAV);  return; }
        SEQ_TWO_KEYS (KC_L, KC_W) { layer_invert (LAYER_WINNAV);  return; }
        SEQ_TWO_KEYS (KC_L, KC_N) { layer_invert (LAYER_NUMPAD);  return; }
        SEQ_TWO_KEYS (KC_L, KC_Y) { layer_invert (LAYER_SYMBOLS); return; }

        SEQ_TWO_KEYS (KC_O, KC_A) { LAUNCH_APP("cisco any"); return; }
        SEQ_TWO_KEYS (KC_O, KC_C) { LAUNCH_APP("chime");     return; }
        SEQ_TWO_KEYS (KC_O, KC_E) { LAUNCH_APP("excel");     return; }
        SEQ_TWO_KEYS (KC_O, KC_F) { LAUNCH_APP("firefox");   return; }
        SEQ_TWO_KEYS (KC_O, KC_H) { LAUNCH_APP("chrome");    return; }
        SEQ_TWO_KEYS (KC_O, KC_N) { LAUNCH_APP("stickies");  return; }
        SEQ_TWO_KEYS (KC_O, KC_O) { LAUNCH_APP("outlook");   return; }
        SEQ_TWO_KEYS (KC_O, KC_R) { LAUNCH_APP("reminders"); return; }
        SEQ_TWO_KEYS (KC_O, KC_S) { LAUNCH_APP("spotify");   return; }
        SEQ_TWO_KEYS (KC_O, KC_T) { LAUNCH_APP("iterm");     return; }
        SEQ_TWO_KEYS (KC_O, KC_V) { LAUNCH_APP("neovim");    return; }
        SEQ_TWO_KEYS (KC_O, KC_W) { LAUNCH_APP("word");      return; }

        // No chord pressed
        tap_code(KC_DEL);
    }
}

// }}}

// vim: foldmethod=marker cursorcolumn
