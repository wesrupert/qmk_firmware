// Copyright 2022 Wes Rupert (@wesrupert)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "ora.h"
#include "action_layer.h"
#include "os_detection.h"

bool force_mac_maps = false;
bool force_win_maps = false;

__attribute__((weak)) bool keyboard_post_init_keymap(void) {
    return true;
}

void keyboard_post_init_user(void) {
    if (!keyboard_post_init_keymap()) return;
}


#if defined(AUTO_TRANSPORT_LAYER)
bool last_is_transport_connected = true;
#endif // AUTO_TRANSPORT_LAYER

__attribute__((weak)) bool housekeeping_task_keymap(void) {
    return true;
}

void housekeeping_task_user(void) {
    if (!housekeeping_task_keymap()) return;
#if defined(AUTO_TRANSPORT_LAYER)
    bool next_is_transport_connected = is_transport_connected();
    if (last_is_transport_connected != next_is_transport_connected) {
        last_is_transport_connected = next_is_transport_connected;
        layer_move(LAYER_BASE);
        if (!next_is_transport_connected) layer_on(LAYER_GAMES);
    }
#endif // AUTO_TRANSPORT_LAYER
}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_dynamic_macro(keycode, record)) return false;
    if (!process_record_keymap(keycode, record)) return false;

    switch (keycode) {
#if defined(RGB_MATRIX_ENABLE)
        case LI_VALU: rgb_matrix_increase_val();   return false;
        case LI_VALD: rgb_matrix_decrease_val();   return false;
        case LI_HUEU: rgb_matrix_increase_hue();   return false;
        case LI_HUED: rgb_matrix_decrease_hue();   return false;
        case LI_SATU: rgb_matrix_increase_sat();   return false;
        case LI_SATD: rgb_matrix_decrease_sat();   return false;
        case LI_NEXT: rgb_matrix_step();           return false;
        case LI_PREV: rgb_matrix_step_reverse();   return false;
        case LI_FAST: rgb_matrix_increase_speed(); return false;
        case LI_SLOW: rgb_matrix_decrease_speed(); return false;
#endif // RGB_MATRIX_ENABLE

        case PK_ASST:
            if (record->event.pressed) {
                register_code(PLATFORM_IS_MAC ? KC_LPAD : KC_ASST);
            }  else {
                unregister_code(PLATFORM_IS_MAC ? KC_LPAD : KC_ASST);
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
        MACRO_SEND_ON_PRESS(MA_LMBD, "() => ");
        MACRO_SEND_ON_PRESS(MA_LMBP, "() => "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
        MACRO_SEND_ON_PRESS(MA_BRNL, "{"SS_TAP(X_ENTER)SS_TAP(X_ENTER)"}"SS_TAP(X_UP)SS_TAP(X_END));
    }
    return true;
}

__attribute__((weak)) bool matrix_scan_keymap(void) {
    return true;
}

void matrix_scan_user(void) {
    if (!matrix_scan_keymap()) return;
}

#if defined(LEADER_ENABLE)
// clang-format off

__attribute__((weak)) bool leader_end_keymap(void) {
    return true;
}

void leader_end_user(void) {
    if (!leader_end_keymap()) return;
    /* Key:  Caps */ if (leader_sequence_one_key(KC_C)) { tap_code(KC_CAPS); return; }
    /* Key:  Num  */ if (leader_sequence_one_key(KC_N)) { tap_code(KC_NUM); return; }
    /* Layr: Base */ if (leader_sequence_two_keys(KC_L, KC_D) || leader_sequence_two_keys(KC_L, KC_L)) { layer_move(LAYER_BASE); return; }
    /* Layr: Game */ if (leader_sequence_two_keys(KC_L, KC_G) || leader_sequence_two_keys(KC_L, KC_P)) { layer_move(LAYER_BASE); layer_on(LAYER_GAMES); return; }
    /* Plat: Infr */ if (leader_sequence_two_keys(KC_P, KC_D) || leader_sequence_two_keys(KC_P, KC_K)) {
        force_mac_maps = false;
        force_win_maps = false;
        if (PLATFORM_IS_MAC) layer_on(LAYER_MAC); else layer_off(LAYER_MAC);
        return;
    }
    /* Plat: Mac  */ if (leader_sequence_two_keys(KC_P, KC_M) || leader_sequence_two_keys(KC_P, KC_I)) {
        force_mac_maps = !force_mac_maps;
        force_win_maps = false;
        layer_on(LAYER_MAC);
        return;
    }
    /* Plat: Win  */ if (leader_sequence_two_keys(KC_P, KC_W) || leader_sequence_two_keys(KC_P, KC_COMMA)) {
        force_mac_maps = false;
        force_win_maps = !force_win_maps;
        layer_off(LAYER_MAC);
        return;
    }
    /* Plat: Prnt */ if (leader_sequence_two_keys(KC_P, KC_P)) {
        os_variant_t os = detected_host_os();
        if (os == OS_MACOS) SEND_STRING("mac");
        else if (os == OS_LINUX) SEND_STRING("linux");
        else if (os == OS_WINDOWS) SEND_STRING("win");
        else if (os == OS_IOS) SEND_STRING("ios");
        else SEND_STRING("unsure");
        return;
    }
    /* Layr: Base */ if (leader_sequence_two_keys(KC_L, KC_D) || leader_sequence_two_keys(KC_L, KC_L)) {
        set_single_default_layer(LAYER_BASE);
        layer_move(LAYER_BASE);
        if (PLATFORM_IS_MAC) layer_on(LAYER_MAC);
        return;
    }
    /* Layr: Game */ if (leader_sequence_two_keys(KC_L, KC_W) || leader_sequence_two_keys(KC_L, KC_P)) {
        layer_move(LAYER_BASE);
        if (PLATFORM_IS_MAC) layer_on(LAYER_MAC);
        layer_on(LAYER_GAMES);
        return;
    }
    /* Layr: Func */ if (leader_sequence_two_keys(KC_L, KC_F) || leader_sequence_two_keys(KC_L, KC_K)) {
        layer_move(LAYER_BASE);
        if (PLATFORM_IS_MAC) layer_on(LAYER_MAC);
        layer_on(LAYER_FUNCTION);
        return;
    }
    /* Layr: Nump */ if (leader_sequence_two_keys(KC_L, KC_N) || leader_sequence_two_keys(KC_L, KC_I)) {
        layer_move(LAYER_BASE);
        if (PLATFORM_IS_MAC) layer_on(LAYER_MAC);
        layer_on(LAYER_NUMPAD);
        return;
    }
#if defined(LEADER_FAILED_CODE)
    tap_code(LEADER_FAILED_CODE);
#else
    tap_code(KC_ESC);
#endif
    return;
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
    layer_state_t layer = get_highest_layer(layer_state);
    return layer == LAYER_BASE || layer == LAYER_MAC;
}

#endif // COMBO_SHOULD_TRIGGER

#if defined (OS_DETECTION_ENABLE)

bool process_detected_host_os_user(os_variant_t detected_os) {
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            layer_on(LAYER_MAC);
            return false;
        default:
            return true;
    }
}

#endif // OS_DETECTION_ENABLE

