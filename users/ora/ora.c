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

void leader_end_user(void) {
    /* Calendar */ if (leader_sequence_one_key(KC_C)) { LAUNCH_APP_RET("google calendar", "google calendar"); }
    /* Edit     */ if (leader_sequence_one_key(KC_E)) { LAUNCH_APP_RET("goneovim", "goneovim"); }
    /* Notes    */ if (leader_sequence_one_key(KC_N)) { LAUNCH_APP_RET("obsidian", "obsidian"); }
    /* Mail     */ if (leader_sequence_one_key(KC_M)) { LAUNCH_APP_RET("gmail", "gmail"); }
    /* Play     */ if (leader_sequence_one_key(KC_P)) { LAUNCH_APP_RET("spotify", "spotify"); }
    /* Slack    */ if (leader_sequence_one_key(KC_S)) { LAUNCH_APP_RET("slack", "slack"); }
    /* Term     */ if (leader_sequence_one_key(KC_T)) { LAUNCH_APP_RET("terminal", "iterm"); }
    /* Web      */ if (leader_sequence_one_key(KC_W)) { LAUNCH_APP_RET("firefox", "firefox"); }

    /* Layer: Games */ if (leader_sequence_two_keys(KC_L, KC_G)) { layer_move(LAYER_WIN); layer_on(LAYER_GAMES); return; }
    /* Layer:   Mac */ if (leader_sequence_two_keys(KC_L, KC_M)) { layer_move(LAYER_MAC); return; }
    /* Layer:   Win */ if (leader_sequence_two_keys(KC_L, KC_W)) { layer_move(LAYER_WIN); return; }
    /* L(Keep): Mac */ if (leader_sequence_two_keys(KC_K, KC_M)) { layer_move(LAYER_MAC); set_single_persistent_default_layer(LAYER_MAC); return; }
    /* L(Keep): Win */ if (leader_sequence_two_keys(KC_K, KC_W)) { layer_move(LAYER_WIN); set_single_persistent_default_layer(LAYER_WIN); return; }

    /* L(1H):   Mac */ if (leader_sequence_two_keys(KC_L, KC_O)) { layer_move(LAYER_MAC); return; }
    /* L(1H):   Win */ if (leader_sequence_two_keys(KC_L, KC_L)) { layer_move(LAYER_WIN); return; }
    /* L(1H): Games */ if (leader_sequence_two_keys(KC_L, KC_DOT)) { layer_move(LAYER_WIN); layer_on(LAYER_GAMES); return; }
    /* D(1H):   Mac */ if (leader_sequence_two_keys(KC_K, KC_O)) { layer_move(LAYER_MAC); set_single_persistent_default_layer(LAYER_MAC); return; }
    /* D(1H):   Win */ if (leader_sequence_two_keys(KC_K, KC_L)) { layer_move(LAYER_WIN); set_single_persistent_default_layer(LAYER_WIN); return; }

    /* None:        */ tap_code(KC_DEL);
}

// clang-format on

#if defined(TAP_DANCE_ENABLE)

// Get easy combo state enum from the current state object.
// @see docs\feature_tap_dance.md
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Prioritizes held combos. Useful for infrequently-tapped keys.
td_state_t hold_cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) return state->pressed ? TD_SINGLE_HOLD : TD_SINGLE_TAP;
    if (state->count == 2) return state->pressed ? TD_DOUBLE_HOLD : TD_DOUBLE_TAP;
    if (state->count == 3) return state->pressed ? TD_TRIPLE_HOLD : TD_TRIPLE_TAP;
    return TD_UNKNOWN;
}

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
