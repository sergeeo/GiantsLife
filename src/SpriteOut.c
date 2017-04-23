#pragma bank=2
#include "SpriteOut.h"
#include "SpriteManager.h"
#include "ZGBMain.h"
#include "Math.h"
#include "SpriteManager.h"

UINT8 bank_SPRITE_OUT = 2;

extern struct Sprite* sprite_player;

void Start_SPRITE_OUT() {
}

void Update_SPRITE_OUT() {

	UINT8 i;
	struct Sprite* spr;
	
	SPRITEMANAGER_ITERATE(i, spr) {
		if(spr->type == SPRITE_PLAYER || spr->type == SPRITE_PLAYERBODY) {
			if(CheckCollision(THIS, spr)) {
				//SpriteManagerRemove(THIS_IDX);
				SetState(STATE_VICTORY);
			}
		}
	}
}

void Destroy_SPRITE_OUT() {
}