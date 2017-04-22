#pragma bank=2
#include "StateVictory.h"
UINT8 bank_STATE_VICTORY = 2;

#include "..\res\src\tiles.h"
#include "..\res\src\map.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "Keys.h"
#include "SpriteManager.h"

/* extern const unsigned char* exo_start_mod_Data[]; */

extern UINT8 n_sprite_types;
UINT8 collision_tiles[] = {1, 0};
INT8 load_next = 0;

void Start_STATE_VICTORY() {
	UINT8 i;

	SPRITES_8x16;
	for(i = 0; i != n_sprite_types; ++ i) {
		SpriteManagerLoad(i);
	}
	SHOW_SPRITES;

	InitScrollTiles(0, 2, tiles, 3);
	InitScroll(mapWidth, mapHeight, map, collision_tiles, 0, 3);
	SHOW_BKG;
}

void Update_STATE_VICTORY() {
	if(KEY_TICKED(J_START)) {
	SetState(STATE_GAMEOVER);
	}
}