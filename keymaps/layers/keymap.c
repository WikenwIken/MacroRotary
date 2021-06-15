#include "ultipad.h"
#include QMK_KEYBOARD_H
#include "muse.h"

#define _BASE     0
#define _SCOTT    1
#define _MITCH    2

enum UltiPad_layers {
    _BASE,
    _SCOTT,
    _MITCH
};

enum custom_keycodes {
  LUL = SAFE_RANGE,
  RED_FLAME,
  DARK_FLAME,
  TEN_SIGN,
  LIGHTER,
  DANCE,	                                                                                                            
  TD,
  YEA,
  DR_WORM,
  LAZER,
  SNARF,
  PARTY,
  LOVE,
  BASE,
  SCOTT,
  MITCH
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_10Key(
		KC_F1, KC_F2, KC_F3, KC_F4, 
		KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_MUTE, 
		KC_P7, KC_P8, KC_P9, 
		KC_P4, KC_P5, KC_P6, KC_PPLS, 
		KC_P1, KC_P2, KC_P3, 
		KC_P0, KC_PDOT, KC_PENT, DF(SCOTT), DF(MITCH)),

  [_SCOTT] = LAYOUT_10Key(
		RESET,     KC_TRNS, KC_TRNS, KC_TRNS, 
		PARTY,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		DR_WORM,   LAZER, SNARF, 
		DANCE,     YEA, TEN_SIGN, LIGHTER, 
		RED_FLAME, DARK_FLAME, TD, 
		LUL,       KC_TRNS, KC_PENT,  DF(BASE),   DF(MITCH)),

  [_MITCH] = LAYOUT_10Key(
		RESET, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		LCAG(KC_A), LCAG(KC_B), LCAG(KC_C), 
		LCAG(KC_D), LCAG(KC_E), LCAG(KC_F), KC_TRNS, 
		LCAG(KC_G), LCAG(KC_H), LCAG(KC_I), 
		LCAG(KC_J), KC_TRNS, KC_PENT, DF(SCOTT), DF(BASE)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
	case BASE:
	    if (record->event.pressed) {
		set_single_persistent_default_layer(_BASE);
	    }
	    return false;
	    break;
	case SCOTT:
	    if (record->event.pressed) {
		set_single_persistent_default_layer(_SCOTT);
	    }
	    return false;
	    break;
        case MITCH:
	    if (record->event.pressed) {
		set_single_persistent_default_layer(_MITCH);
	    }
	    return false;
	    break;
        case LUL:
            if (record->event.pressed) {                
                SEND_STRING("LUL ");
            } else {                			
            }
            break;
	case PARTY:
            if (record->event.pressed) {                
                SEND_STRING("2020Party ");
            } else {                			
            }
            break;            
	case LAZER:
            if (record->event.pressed) {                
                SEND_STRING("scottk2Lazer ");
            } else {                			
            }
            break;
	case SNARF:
            if (record->event.pressed) {
                SEND_STRING("scottk2Snarf ");
            } else {
            }
            break;
	case YEA:
            if (record->event.pressed) {                
                SEND_STRING("VoteYea ");
            } else {                			
            }
            break;
	case LIGHTER:
            if (record->event.pressed) {                
                SEND_STRING("scottk2Lighter ");
            } else {                			
            }
            break;
	case DR_WORM:
            if (record->event.pressed) {                
                SEND_STRING("Squid1 Squid2 Squid2 Squid4 ");
            } else {                			
            }
            break;
	case TD:
            if (record->event.pressed) {                
                SEND_STRING("FBtouchdown ");
            } else {                			
            }
            break;
	case DANCE:
            if (record->event.pressed) {                
                SEND_STRING("scottk2Dance ");
            } else {                			
            }
            break;
        case RED_FLAME:
            if (record->event.pressed) {
                SEND_STRING("CurseLit ");
            } else {                
            }
            break;
	case DARK_FLAME:
	    if (record->event.pressed) {
		SEND_STRING("TwitchLit ");
	    } else {
	    }
	    break;
	case TEN_SIGN:
	    if (record->event.pressed) {
		SEND_STRING("scottk2Ten ");
	    } else {
	    }
	    break;
	case LOVE:
	    if (record->event.pressed) {
		SEND_STRING("PrideHeartL PrideHeartR ");
	    } else {
	    }
	    break;
    }
    return true;
}

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
/*
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif 

  return true;
}
*/
uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _BASE:
      writePinLow(LAYER_INDICATOR_LED_0);
      writePinLow(LAYER_INDICATOR_LED_1);
      break;
    case _SCOTT:
      writePinHigh(LAYER_INDICATOR_LED_1);
      writePinLow(LAYER_INDICATOR_0);
      break;
    case _MITCH:
      writePinHigh(LAYER_INDICATOR_LED_0);
      writePinLow(LAYER_INDICATOR_1);
      break;
  }
  return state;
}
/*
void keyboard_post_init_user() {
  // Customise these values to desired behaviour
  //debug_enable = true;
  //debug_matrix = true;
  //debug_keyboard = true;
  //debug_mouse = true;
  setPinOutput(LAYER_INDICATOR_LED_0);
  setPinOutput(LAYER_INDICATOR_LED_1);
}
*/
void shutdown_user() {
  
}


void matrix_init_user() {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {
    DDRB |= (1 << 3); 

    if (usb_led & (1<<USB_LED_NUM_LOCK)) {
        PORTB |= (1 << 3);
    } else {
        PORTB &= ~(1 << 3);
    }
}


void encoder_update_user(uint8_t index, bool clockwise) {
  /*  Custom encoder control - handles CW/CCW turning of encoder
   *  Cusotom behavior:
   *    main layer:
   *       CW: volume up
   *      CCW: volume down
   *    sub layer:
   *       CW: next media track
   *      CCW: prev media track
   *    debug layer:
   *       CW: brightness up
   *      CCW: brightness down
   */
  if (index == 0) {
    switch (biton32(layer_state)) {
      case _BASE:
        // main layer - volume up (CW) and down (CCW)
        if (clockwise) {
          tap_code(KC_VOLU);
        } else {
          tap_code(KC_VOLD);
        }
        break;

      case _SCOTT:
        // sub layer - next track (CW) and previous track (CCW)
        if (clockwise) {
          tap_code(KC_VOLU);
        } else {
          tap_code(KC_VOLD);
        }
        break;

      case _MITCH:
        // debug layer - brightness up (CW) and brightness down (CCW)
        if (clockwise) {
          tap_code(KC_VOLU);
        } else {
          tap_code(KC_VOLD);
        }
        break;

      default:
        // any other layer (shouldn't exist..) - volume up (CW) and down (CCW)
        if (clockwise) {
          tap_code(KC_VOLU);
        } else {
          tap_code(KC_VOLD);
        }
        break;   
    }
  }
}
