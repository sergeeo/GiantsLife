#pragma bank=2
#include "StateGame.h"
UINT8 bank_STATE_GAME = 2;

#include "..\res\src\level1_1.h"
#include "..\res\src\tiles_level1.h"

#include "ZGBMain.h"
#include "Scroll.h"
#include "Keys.h"
#include "SpriteManager.h"

extern UINT8 n_sprite_types;
UINT8 collision_tiles[] = {1,2,3,4,5,0};

void Start_STATE_GAME() {
	UINT8 i;

	SPRITES_8x16;
	for(i = 0; i != n_sprite_types; ++ i) {
		SpriteManagerLoad(i);
	}
	SHOW_SPRITES;

	scroll_target = SpriteManagerAdd(SPRITE_PLAYER, 20, 50);
	SpriteManagerAdd(SPRITE_PLAYERBODY, 20, 50);

	InitScrollTiles(0, 19, tiles_level1, 3);
	InitScroll(level1_1Width, level1_1Height, level1_1, collision_tiles, 0, 3);
	SHOW_BKG;
}

void Update_STATE_GAME() {
}