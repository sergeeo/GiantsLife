#pragma bank=2
#include "StateGameOver.h"
UINT8 bank_STATE_GAMEOVER = 2;

#include "..\res\src\tiles.h"
#include "..\res\src\map.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "Keys.h"
#include "SpriteManager.h"

/* extern const unsigned char* exo_start_mod_Data[]; */

extern UINT8 n_sprite_types;
UINT8 collision_tiles[] = {1, 0};

void Start_STATE_GAMEOVER() {
	
	UINT8 i;

	SPRITES_8x16;
	for(i = 0; i != n_sprite_types; ++ i) {
		SpriteManagerLoad(i);
	}
	SHOW_SPRITES;

	scroll_target = SpriteManagerAdd(SPRITE_PLAYER, 10, 10);
	SpriteManagerAdd(SPRITE_PLAYERBODY, 10, 10);

	InitScrollTiles(0, 2, tiles, 3);
	InitScroll(mapWidth, mapHeight, map, collision_tiles, 0, 3);
	SHOW_BKG;
}

void Update_STATE_GAMEOVER() {
		if(KEY_TICKED(J_START)) {
			SetState(STATE_GAME);
	}
}