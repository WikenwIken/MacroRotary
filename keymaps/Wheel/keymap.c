#include "ultipad.h"
#include "Macros.h"

#define _BASE     0
#define _SUB      1
#define _SUB2     2




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_UltiPad(
		KC_F1, KC_F2, KC_F3, KC_F4, 
		KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_MUTE, 
		KC_P7, KC_P8, KC_P9, 
		KC_P4, KC_P5, KC_P6, KC_PPLS, 
		KC_P1, KC_P2, KC_P3, 
		KC_P0, KC_PDOT, KC_PENT, DF(1), DF(2)),

  [_SUB] = LAYOUT_UltiPad(
		RESET,     YEA, 		NAY,  	  BABIES, 
		PARTY,     NINETEN, 	NIGHTBOT,   mitchLIGHTER,  KC_MUTE, 
		DR_WORM,   LAZER, 		SNARF, 
		DANCE,     DANCE_HF, 	TEN_SIGN, LIGHTER, 
		RED_FLAME, DARK_FLAME,  TD, 
		LUL,       UNITY, 		KC_PENT,  		   DF(0),   DF(2)),

  [_SUB2] = LAYOUT_UltiPad(
		RESET, 		KC_TRNS, 	KC_TRNS, KC_TRNS, 
		TIE,   		MODS,    	PEARLS,  BANANA, KC_MUTE, 
		FACEPALM,   ROCK,	 	LOVE, 
		mitchDANCE, POLO,  		HYPE,	  mitchLIGHTER, 
		RED_FLAME,  DARK_FLAME, SOGOOD, 
		LAUGH,		CLAP,		KC_PENT, 			DF(1), DF(0)),
};


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
  switch (biton32(layer_state)) {		//added layer_ to state
    case _BASE:
      writePinLow(LAYER_INDICATOR_LED_0);
      writePinLow(LAYER_INDICATOR_LED_1);
      break;
    case _SUB:
      writePinHigh(LAYER_INDICATOR_LED_1);
	  writePinLow(LAYER_INDICATOR_LED_0);
      break;
    case _SUB2:
      writePinHigh(LAYER_INDICATOR_LED_0);
	  writePinLow(LAYER_INDICATOR_LED_1);
      break;
  }
  return state;
}

void keyboard_pre_init_user() {		//changed post to pre
  // Customise these values to desired behaviour
  //debug_enable = true;
  //debug_matrix = true;
  //debug_keyboard = true;
  //debug_mouse = true;
  setPinOutput(LAYER_INDICATOR_LED_0);
  setPinOutput(LAYER_INDICATOR_LED_1);
  //setPinOutput(LED_NUMLOCK_PIN);
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

  
    switch (biton32(layer_state)) {
      case _BASE:
        // main layer - volume up (CW) and down (CCW)
        if (clockwise) {
          tap_code(KC_VOLU);
        } else {
          tap_code(KC_VOLD);
        }
        break;

      case _SUB:
        // sub layer - next track (CW) and previous track (CCW)
        if (clockwise) {
          tap_code(KC_A);
        } else {
          tap_code(KC_B);
        }
        break;

      case _SUB2:
        // debug layer - brightness up (CW) and brightness down (CCW)
        if (clockwise) {
          tap_code(KC_R);
        } else {
          tap_code(KC_L);
        }
        break;
	}
  
}
