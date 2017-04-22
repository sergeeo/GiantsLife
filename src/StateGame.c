#pragma bank=2
#include "StateGame.h"
UINT8 bank_STATE_GAME = 2;

#include "..\res\src\tiles.h"
#include "..\res\src\map.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "Keys.h"
#include "SpriteManager.h"

extern UINT8 n_sprite_types;
UINT8 collision_tiles[] = {1, 0};
INT8 load_next = 0;

void Start_STATE_GAME() {
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

void Update_STATE_GAME() {
	if(KEY_TICKED(J_START)) {
		SetState(STATE_INTRO2);
	}
}