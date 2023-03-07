// Copyright 2022 Wes Rupert (@wesrupert)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "ora.h"
#include "g/keymap_combo.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_dynamic_macro(keycode, record)) {
        return false;
    }
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
                SEND_STRING("[]" SS_TAP(X_LEFT));
            }
            break;
        case MA_PCBR:
            if (record->event.pressed) {
                SEND_STRING("{  }" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
            }
            break;
        case MA_PPRN:
            if (record->event.pressed) {
                SEND_STRING("()" SS_TAP(X_LEFT));
            }
            break;
        case MA_PABK:
            if (record->event.pressed) {
                SEND_STRING("<>" SS_TAP(X_LEFT));
            }
            break;
        case MA_PCMT:
            if (record->event.pressed) {
                SEND_STRING("/*  */" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
            }
            break;
        case MA_LMBD:
            if (record->event.pressed) {
                SEND_STRING("() => {  }" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
            }
            break;
        case MA_BRNL:
            if (record->event.pressed) {
                SEND_STRING("{" SS_TAP(X_ENTER) SS_TAP(X_ENTER) "}" SS_TAP(X_UP) SS_TAP(X_END));
            }
            break;
    }
    return true;
}

// clang-format off

LEADER_EXTERNS();
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;

        /* Calendar */ SEQ_ONE_KEY(KC_C) LAUNCH_APP_RET("google calendar", "google calendar");
        /* Edit     */ SEQ_ONE_KEY(KC_E) LAUNCH_APP_RET("goneovim", "goneovim");
        /* Notes    */ SEQ_ONE_KEY(KC_N) LAUNCH_APP_RET("obsidian", "obsidian");
        /* Mail     */ SEQ_ONE_KEY(KC_M) LAUNCH_APP_RET("gmail", "gmail");
        /* Play     */ SEQ_ONE_KEY(KC_P) LAUNCH_APP_RET("spotify", "spotify");
        /* Slack    */ SEQ_ONE_KEY(KC_S) LAUNCH_APP_RET("slack", "slack");
        /* Term     */ SEQ_ONE_KEY(KC_T) LAUNCH_APP_RET("terminal", "iterm");
        /* Web      */ SEQ_ONE_KEY(KC_W) LAUNCH_APP_RET("firefox", "firefox");

        /* Layer: Games */ SEQ_TWO_KEYS(KC_L, KC_G) { layer_move(LAYER_WIN); layer_on(LAYER_GAMES); return; }
        /* Layer:   Mac */ SEQ_TWO_KEYS(KC_L, KC_M) { layer_move(LAYER_MAC); return; }
        /* Layer:   Win */ SEQ_TWO_KEYS(KC_L, KC_W) { layer_move(LAYER_WIN); return; }
        /* Default: Mac */ SEQ_TWO_KEYS(KC_D, KC_M) { layer_move(LAYER_MAC); set_single_persistent_default_layer(LAYER_MAC); return; }
        /* Default: Win */ SEQ_TWO_KEYS(KC_D, KC_W) { layer_move(LAYER_WIN); set_single_persistent_default_layer(LAYER_WIN); return; }

        /* Layer:   Mac */ SEQ_TWO_KEYS(KC_L, KC_O) { layer_move(LAYER_MAC); return; }
        /* Layer:   Win */ SEQ_TWO_KEYS(KC_L, KC_L) { layer_move(LAYER_WIN); return; }
        /* Layer: Games */ SEQ_TWO_KEYS(KC_L, KC_DOT) { layer_move(LAYER_WIN); layer_on(LAYER_GAMES); return; }
        /* Default: Mac */ SEQ_TWO_KEYS(KC_D, KC_I) { layer_move(LAYER_MAC); set_single_persistent_default_layer(LAYER_MAC); return; }
        /* Default: Win */ SEQ_TWO_KEYS(KC_D, KC_K) { layer_move(LAYER_WIN); set_single_persistent_default_layer(LAYER_WIN); return; }

        tap_code(KC_DEL);
    }
}

// clang-format on

#if defined(TAP_DANCE_ENABLE)

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else
            return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted)
            return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return TD_DOUBLE_HOLD;
        else
            return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed)
            return TD_TRIPLE_TAP;
        else
            return TD_TRIPLE_HOLD;
    } else
        return TD_UNKNOWN;
}

// Prioritizes held combos. Useful for infrequently-tapped keys.
// Since we aren't monitoring interrupts, we don't support tap{x}-hold dances here.
td_state_t hold_cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        return state->pressed ? TD_SINGLE_HOLD : TD_SINGLE_TAP;
    } else if (state->count == 2) {
        return state->pressed ? TD_DOUBLE_HOLD : TD_DOUBLE_TAP;
    } else if (state->count == 3) {
        return state->pressed ? TD_TRIPLE_HOLD : TD_TRIPLE_TAP;
    }
    return TD_UNKNOWN;
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
        if (IS_LAYER_ON(LAYER_WIN)) {
            tap_code(WN_MPLY);
        } else {
            tap_code(MC_MPLY);
        }
    } else if (state->count == 2) {
        LAUNCH_APP_RET("spotify", "spotify");
    }
}

td_state_t dance_lctl_state = 0;

void dance_lctl_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_lctl_state = hold_cur_dance(state);
    switch (dance_lctl_state) {
        case TD_SINGLE_TAP:
            qk_leader_start();
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LCTL);
            break;
        default:
            break;
    }
}

void dance_lctl_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (dance_lctl_state) {
        case TD_SINGLE_HOLD:
            unregister_code(KC_LCTL);
            break;
        default:
            break;
    }
    dance_lctl_state = 0;
}

td_state_t dance_rctl_state = 0;

void dance_rctl_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_rctl_state = hold_cur_dance(state);
    switch (dance_rctl_state) {
        case TD_SINGLE_TAP:
            qk_leader_start();
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_RCTL);
            break;
        default:
            break;
    }
}

void dance_rctl_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (dance_rctl_state) {
        case TD_SINGLE_HOLD:
            unregister_code(KC_RCTL);
            break;
        default:
            break;
    }
    dance_rctl_state = 0;
}

td_state_t dance_lalt_state = 0;

void dance_lalt_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_lalt_state = hold_cur_dance(state);
    switch (dance_lalt_state) {
        case TD_SINGLE_TAP:
            layer_invert(LAYER_NUMPAD);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LALT);
            break;
        default:
            break;
    }
}

void dance_lalt_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (dance_lalt_state) {
        case TD_SINGLE_HOLD:
            unregister_code(KC_LALT);
            break;
        default:
            break;
    }
    dance_lalt_state = 0;
}

td_state_t dance_ralt_state = 0;

void dance_ralt_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_ralt_state = hold_cur_dance(state);
    switch (dance_ralt_state) {
        case TD_SINGLE_TAP:
            layer_invert(LAYER_NUMPAD);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_RALT);
            break;
        default:
            break;
    }
}

void dance_ralt_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (dance_ralt_state) {
        case TD_SINGLE_HOLD:
            unregister_code(KC_RALT);
            break;
        default:
            break;
    }
    dance_ralt_state = 0;
}

// clang-format off

__attribute__((weak)) qk_tap_dance_action_t tap_dance_actions[] = {
    [TAP_DANCE_DYN_MACRO_1] = ACTION_TAP_DANCE_FN(dance_dynamic_macro_1),
    [TAP_DANCE_DYN_MACRO_2] = ACTION_TAP_DANCE_FN(dance_dynamic_macro_2),
    [TAP_DANCE_PLAYPAUSE_SPOTIFY] = ACTION_TAP_DANCE_FN(dance_playpause_spotify),
    [TAP_DANCE_LEADER_LCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lctl_finished, dance_lctl_reset),
    [TAP_DANCE_LEADER_RCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_rctl_finished, dance_rctl_reset),
    [TAP_DANCE_LEADER_LALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lalt_finished, dance_lalt_reset),
    [TAP_DANCE_LEADER_RALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_ralt_finished, dance_ralt_reset),
};

// clang-format on

#endif // TAP_DANCE_ENABLE

#if defined(COMBO_SHOULD_TRIGGER)

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    if (layer_state_is(LAYER_GAMES)) {
        return false;
    } else if (layer_state_is(LAYER_NUMPAD)) {
        return false;
    } else {
        return true;
    }
}

#endif // COMBO_SHOULD_TRIGGER
