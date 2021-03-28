#include "ora.h"

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

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
        SEQ_ONE_KEY(KC_P) { LAUNCH_APP("spotify");   return; }
        SEQ_ONE_KEY(KC_R) { LAUNCH_APP("reminders"); return; }
        SEQ_ONE_KEY(KC_S) { LAUNCH_APP("slack");     return; }
        SEQ_ONE_KEY(KC_T) { LAUNCH_APP("iterm");     return; }
        SEQ_ONE_KEY(KC_U) { LAUNCH_APP("neovim");    return; }
        SEQ_ONE_KEY(KC_V) { LAUNCH_APP("vimr");      return; }
        SEQ_ONE_KEY(KC_W) { layer_move(LAYER_BASE); layer_on(LAYER_WIN); return; }

        tap_code(KC_DEL);
    }
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

void dance_mac_playpause_spotify(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) { tap_code(MC_MPLY); } else if (state->count == 2) { LAUNCH_APP("spotify"); }
}

void dance_win_playpause_spotify(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) { tap_code(WN_MPLY); } else if (state->count == 2) { LAUNCH_APP("spotify"); }
}

__attribute__ ((weak))
qk_tap_dance_action_t tap_dance_actions[] = {
    [TAP_DANCE_DYN_MACRO_1] = ACTION_TAP_DANCE_FN(dance_dynamic_macro_1),
    [TAP_DANCE_DYN_MACRO_2] = ACTION_TAP_DANCE_FN(dance_dynamic_macro_2),
    [TAP_DANCE_MAC_PLAYPAUSE_SPOTIFY] = ACTION_TAP_DANCE_FN(dance_mac_playpause_spotify),
    [TAP_DANCE_WIN_PLAYPAUSE_SPOTIFY] = ACTION_TAP_DANCE_FN(dance_win_playpause_spotify),
};

