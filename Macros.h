enum custom_keycodes {
  LUL = SAFE_RANGE,
  RED_FLAME,
	DARK_FLAME,
	TEN_SIGN,
	LIGHTER,
	DANCE,
	NIGHTBOT,
	DANCE_HF,
	TD,
	YEA,
	NAY,
	DR_WORM,
	LAZER,
	SNARF,
	PARTY,
	PEARLS,
	NINETEN,
	BABIES,
	LORD,
	UNITY,
	TIE,
	MODS,
	BANANA,
	FACEPALM,
	ROCK,
	LOVE,
	mitchLIGHTER,
	mitchDANCE,
	POLO,
	HYPE,
	SOGOOD,
	CLAP,
	LAUGH
	
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
//SCOTT EMOTES
	case UNITY:
		if (record->event.pressed) {                
			SEND_STRING("TwitchUnity ");
		} else {                			
		}
		break;	
	case PEARLS:
		if (record->event.pressed) {                
			SEND_STRING("::gasps:: My Pearls! ");
		} else {                			
		}
		break;
	case NIGHTBOT:
		if (record->event.pressed) {                
			SEND_STRING("scottk2Nightbot ");
		} else {                			
		}
		break;
	case LORD:
		if (record->event.pressed) {                
			SEND_STRING("LORD?!");
		} else {                			
		}
		break;	
	case BABIES:
		if (record->event.pressed) {                
			SEND_STRING("!babies");
		} else {                			
		}
		break;
	case NINETEN:
		if (record->event.pressed) {                
			SEND_STRING("9 / scottk2Ten ");
		} else {                			
		}
		break;	
	case LUL:
		if (record->event.pressed) {                
			SEND_STRING("LUL ");
		} else {                			
		}
		break;
	case PARTY:
		if (record->event.pressed) {                
			SEND_STRING("scottk2Party ");
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
	case NAY:
		if (record->event.pressed) {                
			SEND_STRING("VoteNay ");
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
			SEND_STRING("scottk2Lighter scottk2Lighter scottk2Lighter scottk2Lighter scottk2Lighter scottk2Lighter_HF scottk2Lighter_HF scottk2Lighter_HF scottk2Lighter_HF scottk2Lighter_HF scottk2Lighter scottk2Lighter scottk2Lighter scottk2Lighter scottk2Lighter ");
		} else {                			
		}
		break;
	case DR_WORM:
		if (record->event.pressed) {                
			SEND_STRING("Squid1 Squid2 Squid2 Squid4 mitchbLOVE ");
		} else {                			
		}
		break;
	case TD:
		if (record->event.pressed) {                
			SEND_STRING("FBtouchdown ");
		} else {                			
		}
		break;
	case DANCE_HF:
		if (record->event.pressed) {                
			SEND_STRING("scottk2Dance_HF ");
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
//MITCH EMOTES
	case TIE:
		if (record->event.pressed) {
			SEND_STRING("mitchbTIE ");
		} else {
		}
		break;
	case MODS:
		if (record->event.pressed) {
			SEND_STRING("mitchbMODS ");
		} else {
		}
		break;	
	case BANANA:
		if (record->event.pressed) {
			SEND_STRING("mitchbBANANA ");
		} else {
		}
		break;
	case FACEPALM:
		if (record->event.pressed) {
			SEND_STRING("mitchbFACEPALM ");
		} else {
		}
		break;
	case ROCK:
		if (record->event.pressed) {
			SEND_STRING("mitchbROCK ");
		} else {
		}
		break;
	case LOVE:
		if (record->event.pressed) {
			SEND_STRING("mitchbLOVE ");
		} else {
		}
		break;
	case mitchLIGHTER:
		if (record->event.pressed) {
			SEND_STRING("mitchbLIGHTER ");
		} else {
		}
		break;
	case mitchDANCE:
		if (record->event.pressed) {
			SEND_STRING("mitchbDANCE ");
		} else {
		}
		break;
	case POLO:
		if (record->event.pressed) {
			SEND_STRING("mitchbPOLO ");
		} else {
		}
		break;
	case HYPE:
		if (record->event.pressed) {
			SEND_STRING("mitchbHYPE ");
		} else {
		}
		break;
	case SOGOOD:
		if (record->event.pressed) {
			SEND_STRING("mitchbSOGOOD ");
		} else {
		}
		break;
	case CLAP:
		if (record->event.pressed) {
			SEND_STRING("mitchbCLAP ");
		} else {
		}
		break;
	case LAUGH:
		if (record->event.pressed) {
			SEND_STRING("mitchbLAUGH ");
		} else {
		}
		break;
	}
    return true;
}

