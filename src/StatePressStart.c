#pragma bank=2
#include "StatePressStart.h"
UINT8 bank_STATE_PRESSSTART = 2;

#include "..\res\src\pressstarttiles.h"
#include "..\res\src\pressstart.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "Keys.h"
#include "SpriteManager.h"

/* extern const unsigned char* exo_start_mod_Data[]; */

extern UINT8 n_sprite_types;
UINT8 collision_tiles[] = {1, 0};

void Start_STATE_PRESSSTART() {
	UINT8 i;

	SPRITES_8x16;
	for(i = 0; i != n_sprite_types; ++ i) {
		SpriteManagerLoad(i);
	}
	SHOW_SPRITES;

	InitScrollTiles(0, 24, pressstarttiles, 3);
	InitScroll(pressstartWidth, pressstartHeight, pressstart, collision_tiles, 0, 3);
	SHOW_BKG;
}

void Update_STATE_PRESSSTART() {
		if(KEY_TICKED(J_START)) {
			SetState(STATE_INTRO1);
	}
}