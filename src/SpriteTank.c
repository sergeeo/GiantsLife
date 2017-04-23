#pragma bank=2
#include "SpriteBlock.h"
#include "SpriteManager.h"
#include "ZGBMain.h"
UINT8 bank_SPRITE_TANK = 2;

// const UINT8 anim_idleblock[] = {1, 0};
const UINT8 anim_walktank[] = {3, 0, 1, 2};
const UINT8 anim_destroytank[] = {5, 3, 4, 3, 4, 5};

extern struct Sprite* sprite_player;

typedef enum  {
	TANK_NORMAL,
	TANK_DESTROY
}TANK_STATE;

TANK_STATE tank_state;

void Start_SPRITE_TANK() {
	THIS->coll_x = 2u;
	THIS->coll_y = 9u;
	THIS->coll_w = 14u;
	THIS->coll_h = 10u;
	tank_state = TANK_NORMAL;
}

void Update_SPRITE_BLOCK() {

	UINT8 i;
	struct Sprite* spr;
	
	switch(block_state){
		case BLOCK_DESTROY:
			if(THIS->current_frame == 3) {
				SpriteManagerRemove(THIS_IDX);
				// SpriteManagerRemoveSprite(THIS);
			}
			break;
		case BLOCK_NORMAL:
			SPRITEMANAGER_ITERATE(i, spr) {
				if(spr->type == SPRITE_PLAYER || spr->type == SPRITE_PLAYERBODY) {
					if(CheckCollision(THIS, spr)) {
						//SpriteManagerRemove(THIS_IDX);
						block_state = BLOCK_DESTROY;
						SetSpriteAnim(THIS, anim_destroy, 6u);
					}
				}
			}
			break;
	}

}

void Destroy_SPRITE_BLOCK() {
}