// Copyright 2022 Wes Rupert (@wesrupert)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "ora.h"

bool force_mac_maps = false;
bool force_win_maps = false;
bool is_tab_switcher_active = false;
uint16_t tab_switcher_timer = 0;

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

__attribute__((weak)) bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_dynamic_macro(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case PK_TABN:
            if (record->event.pressed) {
                if (!is_tab_switcher_active) {
                    is_tab_switcher_active = true;
                    if (PLATFORM_IS_MAC) register_code(KC_LGUI); else register_code(KC_LALT);
                }
                tab_switcher_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;

        MACRO_SEND_PLAT_ON_PRESS(PK_LOCK, SS_LGUI("l"), SS_LGUI(SS_LCTL("q")));
        MACRO_SEND_PLAT_ON_PRESS(PK_PSCF, SS_DOWN(X_LGUI)SS_TAP(X_PSCR)SS_UP(X_LGUI), SS_LGUI(SS_LSFT("4")));
        MACRO_SEND_PLAT_ON_PRESS(PK_PSCR, SS_TAP(X_PSCR), SS_LGUI(SS_LCTL(SS_LSFT("4"))));
        MACRO_SEND_PLAT_ON_PRESS(PK_MNXT, SS_TAP(X_MNXT), SS_TAP(X_MFFD));
        MACRO_SEND_PLAT_ON_PRESS(PK_MPRV, SS_TAP(X_MPRV), SS_TAP(X_MRWD));
        MACRO_SEND_PLAT_ON_PRESS(PK_VOLU, SS_TAP(X_VOLU), SS_TAP(X_KB_VOLUME_UP));
        MACRO_SEND_PLAT_ON_PRESS(PK_VOLD, SS_TAP(X_VOLD), SS_TAP(X_KB_VOLUME_DOWN));
        MACRO_SEND_PLAT_ON_PRESS(PK_MUTE, SS_TAP(X_MUTE), SS_TAP(X_KB_MUTE));
        MACRO_SEND_PLAT_ON_PRESS(PK_MONT, SS_DOWN(X_LCTL)SS_DOWN(X_LSFT)SS_TAP(X_ESC)SS_UP(X_LSFT)SS_UP(X_LCTL), SS_DOWN(X_LGUI)SS_DOWN(X_LALT)SS_TAP(X_ESC)SS_UP(X_LALT)SS_UP(X_LGUI));
        MACRO_SEND_PLAT_ON_PRESS(PK_SYST, SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_TAP(X_DEL)SS_UP(X_LALT)SS_UP(X_LCTL), SS_DOWN(X_LGUI)SS_DOWN(X_LALT)SS_TAP(X_ESC)SS_UP(X_LALT)SS_UP(X_LGUI));
        MACRO_SEND_ON_PRESS(MA_LAUNCH, SS_LGUI(" "));
        MACRO_SEND_ON_PRESS(MA_OR,   " || ");
        MACRO_SEND_ON_PRESS(MA_AND,  " && ");
        MACRO_SEND_ON_PRESS(MA_PBRC, "[]"SS_TAP(X_LEFT));
        MACRO_SEND_ON_PRESS(MA_PCBR, "{  }"SS_TAP(X_LEFT)SS_TAP(X_LEFT));
        MACRO_SEND_ON_PRESS(MA_PPRN, "()"SS_TAP(X_LEFT));
        MACRO_SEND_ON_PRESS(MA_PABK, "<>"SS_TAP(X_LEFT));
        MACRO_SEND_ON_PRESS(MA_PCMT, "/*  */"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
        MACRO_SEND_ON_PRESS(MA_LMBD, "() => {  }"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
        MACRO_SEND_ON_PRESS(MA_BRNL, "{"SS_TAP(X_ENTER)SS_TAP(X_ENTER)"}"SS_TAP(X_UP)SS_TAP(X_END));
    }
    return true;
}

void matrix_scan_user(void) {
  if (is_tab_switcher_active) {
    if (timer_elapsed(tab_switcher_timer) > SUPER_TAB_SWITCHER_TERM) {
      if (PLATFORM_IS_MAC) unregister_code(KC_LGUI); else unregister_code(KC_LALT);
      is_tab_switcher_active = false;
    }
  }
}

#if defined(LEADER_ENABLE)
// clang-format off

bool base_leader_end_user(void) {
    /* Key:  Caps */ if (leader_sequence_one_key(KC_C)) { tap_code(KC_CAPS); return true; }
    /* Layr: Base */ if (leader_sequence_two_keys(KC_L, KC_D) || leader_sequence_two_keys(KC_L, KC_L)) { layer_move(LAYER_BASE); return true; }
    /* Layr: Game */ // (leader_sequence_two_keys(KC_L, KC_G) || leader_sequence_two_keys(KC_L, KC_O)) -> Add this case to the map-local leader_end_user method.
    /* Plat: Infr */ if (leader_sequence_two_keys(KC_P, KC_D) || leader_sequence_two_keys(KC_L, KC_K)) { force_mac_maps = false; force_win_maps = false; return true; }
    /* Plat: Mac  */ if (leader_sequence_two_keys(KC_P, KC_M) || leader_sequence_two_keys(KC_L, KC_I)) { force_mac_maps = !force_mac_maps; force_win_maps = false; return true; }
    /* Plat: Win  */ if (leader_sequence_two_keys(KC_P, KC_W) || leader_sequence_two_keys(KC_L, KC_COMMA)) { force_mac_maps = false; force_win_maps = !force_win_maps; return true; }
    /* Plat: Prnt */ if (leader_sequence_two_keys(KC_P, KC_P)) { if (PLATFORM_IS_MAC) SEND_STRING("mac"); else SEND_STRING("win"); return true; }
    return false;
}

__attribute__((weak)) void leader_end_user(void) {
    if (base_leader_end_user()) return;
    tap_code(KC_ESC);
}

// clang-format on
#endif // LEADER_ENABLED

#if defined(TAP_DANCE_ENABLE)

// Get easy combo state enum from the current state object.
// @see docs\feature_tap_dance.md
__attribute__((weak)) td_state_t cur_dance(tap_dance_state_t *state) {
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
__attribute__((weak)) td_state_t hold_cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) return state->pressed ? TD_SINGLE_HOLD : TD_SINGLE_TAP;
    if (state->count == 2) return state->pressed ? TD_DOUBLE_HOLD : TD_DOUBLE_TAP;
    if (state->count == 3) return state->pressed ? TD_TRIPLE_HOLD : TD_TRIPLE_TAP;
    return TD_UNKNOWN;
}

#endif // TAP_DANCE_ENABLE

#if defined(COMBO_SHOULD_TRIGGER)

__attribute__((weak)) bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    if (get_highest_layer(layer_state) > 0) {
        return false;
    } else {
        return true;
    }
}

#endif // COMBO_SHOULD_TRIGGER
