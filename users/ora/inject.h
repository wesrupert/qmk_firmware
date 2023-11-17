// Combos inject file for https://docs.qmk.fm/#/feature_combo?id=dictionary-management
// void process_combo_event(uint8_t combo_index, bool pressed) {
  switch (combo_index) {
    case COMBO_WASD: {
      layer_move(LAYER_BASE);
      layer_on(LAYER_GAMES);
      break;
    }
  }
// }