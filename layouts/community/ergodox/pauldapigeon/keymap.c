#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_hungarian.h"

#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)

//Tap Dance Declarations
enum {
  TD_LEFT_BRACES = 0,
  TD_RIGHT_BRACES,
};

//Combo Declarations
enum combos {
  COMBO_MUTE = 0,
  COMBO_VOLUME_DOWN,
  COMBO_PREV_TRACK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    HU_GRV,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_PC_COPY,                                     KC_PC_PASTE,    KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_EQUAL,
    KC_AUDIO_VOL_UP,KC_QUOTE,       KC_COMMA,       KC_DOT,         KC_P,           KC_Y,           TD(TD_LEFT_BRACES),                                        TD(TD_RIGHT_BRACES),        KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_SLASH,
    KC_MEDIA_PLAY_PAUSE,KC_A,           KC_O,           KC_E,           KC_U,           KC_I,                                                                           KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           KC_BSLASH,
    KC_LSHIFT,      KC_SCOLON,      KC_Q,           KC_J,           KC_K,           KC_X,           KC_LPRN,                                        KC_RPRN,        KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           KC_RSHIFT,
    KC_MEDIA_NEXT_TRACK,KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,                                                                                                       KC_PGUP,        KC_PGDOWN,      KC_HOME,        KC_END,         KC_MINUS,
                                                                                                    KC_TAB,         KC_INSERT,      KC_DELETE,      KC_ESCAPE,
                                                                                                                    TG(2),          OSL(1),
                                                                                    KC_SPACE,       KC_BSPACE,      LALT_T(KC_LGUI),LCTL_T(KC_CAPSLOCK),KC_ENTER,       KC_SPACE
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, HU_OEE,         KC_TRANSPARENT, HU_UEE,         KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, HU_AA,          HU_OO,          HU_EE,          HU_UU,          HU_II,                                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, HU_OE,          KC_TRANSPARENT, HU_UE,          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP,    KC_MS_UP,       KC_MS_WH_DOWN,  KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_RIGHT,                                                                 KC_MEDIA_REWIND, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_MEDIA_FAST_FORWARD, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN3,     KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,KC_AUDIO_VOL_DOWN,KC_TRANSPARENT,KC_TRANSPARENT,
    TD(TD_LEFT_BRACES), TD(TD_RIGHT_BRACES),    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


void dance_left_braces_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LSFT);
    register_code (KC_LBRACKET);
  } else if (state->count == 2) {
    register_code (KC_LBRACKET);
  } else {
    register_code (KC_LSFT);
    register_code (KC_9);
  }
}

void dance_left_braces_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_LSFT);
    unregister_code (KC_LBRACKET);
  } else if (state->count == 2) {
    unregister_code (KC_LBRACKET);
  } else {
    unregister_code (KC_LSFT);
    unregister_code (KC_9);
  }
}

void dance_right_braces_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LSFT);
    register_code (KC_RBRACKET);
  } else if (state->count == 2) {
    register_code (KC_RBRACKET);
  } else {
    register_code (KC_LSFT);
    register_code (KC_0);
  }
}

void dance_right_braces_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_LSFT);
    unregister_code (KC_RBRACKET);
  } else if (state->count == 2) {
    unregister_code (KC_RBRACKET);
  } else {
    unregister_code (KC_LSFT);
    unregister_code (KC_0);
  }
}

const uint16_t PROGMEM shift_play_combo[] = {KC_RSFT, KC_MEDIA_PLAY_PAUSE, COMBO_END};
const uint16_t PROGMEM shift_volume_up_combo[] = {KC_RSFT, KC_AUDIO_VOL_UP, COMBO_END};
const uint16_t PROGMEM shift_next_track_combo[] = {KC_RSFT, KC_MEDIA_NEXT_TRACK, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_MUTE] = COMBO(shift_play_combo, KC_AUDIO_MUTE),
  [COMBO_VOLUME_DOWN] = COMBO(shift_volume_up_combo, KC_AUDIO_VOL_DOWN),
  [COMBO_PREV_TRACK] = COMBO(shift_next_track_combo, KC_MEDIA_PREV_TRACK)
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for {, twice for (, three times for [
  [TD_LEFT_BRACES]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_left_braces_finished, dance_left_braces_reset),
  //Tap once for }, twice for ), three times for ]
  [TD_RIGHT_BRACES]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_right_braces_finished, dance_right_braces_reset)
};

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
