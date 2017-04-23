#pragma bank=2
#include "SpritePlayerbody.h"
UINT8 bank_SPRITE_PLAYERBODY = 2;

#include "ZGBMain.h"
#include "Sprite.h"
#include "Keys.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "SpritePlayer.h"
#include "Math.h"

#include "../res/src/playerbody.h"

extern struct Sprite* sprite_player;

//esto no funca
// extern enum PLAYER_STATE;
// extern PLAYER_STATE player_state;

const UINT8 anim_idle[] = {1, 0};
const UINT8 anim_walk[] = {6, 0, 1, 2, 3, 4, 5};

void Start_SPRITE_PLAYERBODY() {
	SetSpriteAnim(THIS, anim_idle, 3u);
	THIS->x = sprite_player->x;
	THIS->y = sprite_player->y + 13u;
}

void Update_SPRITE_PLAYERBODY() {
	
	if(KEY_PRESSED(J_LEFT) || KEY_PRESSED(J_RIGHT)){
		SetSpriteAnim(THIS, anim_walk, 14u);
	} else {
		SetSpriteAnim(THIS, anim_idle, 9u);
	}

	//positioning
	
	THIS->x = sprite_player->x;
	THIS->y = sprite_player->y + 13u;
	
	// guarripeich 
	
	if(sprite_player->flags == OAM_VERTICAL_FLAG) {
		THIS->flags = OAM_VERTICAL_FLAG;
	} else if(sprite_player->flags == 0u) {
		THIS->flags = 0u;
	}
	
	
}

void Destroy_SPRITE_PLAYERBODY() {
}