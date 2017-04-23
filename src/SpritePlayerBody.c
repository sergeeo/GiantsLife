#pragma bank=2
#include "SpritePlayerbody.h"
UINT8 bank_SPRITE_PLAYERBODY = 2;

#include "ZGBMain.h"
#include "Sprite.h"
#include "Keys.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "Math.h"

#include "../res/src/playerbody.h"

extern struct Sprite* sprite_player;
extern enum player_state;

const UINT8 anim_idle[] = {1, 0};
const UINT8 anim_walk[] = {6, 0, 1, 2, 3, 4, 5};

UINT8 previous_x;

void Start_SPRITE_PLAYERBODY() {
	THIS->x = sprite_player->x;
	THIS->y = sprite_player->y + 13u;
}

void Update_SPRITE_PLAYERBODY() {
	
	previous_x = THIS->x;
	THIS->x = sprite_player->x;
	THIS->y = sprite_player->y + 13u;
	
	// guarripeich 
	
	if(previous_x != THIS->x){
		SetSpriteAnim(THIS, anim_walk, 9u);
	} else {
		SetSpriteAnim(THIS, anim_idle, 3u);
	}
	if(sprite_player->flags == OAM_VERTICAL_FLAG) {
		THIS->flags = OAM_VERTICAL_FLAG;
	} else if(sprite_player->flags == 0u) {
		THIS->flags = 0u;
	}
}

void Destroy_SPRITE_PLAYERBODY() {
}