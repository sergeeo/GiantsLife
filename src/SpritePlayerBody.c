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

UINT8 previous_x;

void Start_SPRITE_PLAYERBODY() {
	SetSpriteAnim(THIS, anim_idle, 3u);
	THIS->x = sprite_player->x;
	THIS->y = sprite_player->y + 13u;
	previous_x = THIS->x;
}

void Update_SPRITE_PLAYERBODY() {
	
//	if(player_state == PLAYER_STATE_IDLE) {
	if (previous_x == THIS->x) {
		SetSpriteAnim(THIS, anim_idle, 9u);
	}else{
//	}else if(player_state == PLAYER_STATE_WALKING){
		SetSpriteAnim(THIS, anim_walk, 14u);
	}
	previous_x = THIS->x;
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