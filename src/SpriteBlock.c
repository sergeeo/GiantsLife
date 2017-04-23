#pragma bank=2
#include "SpriteBlock.h"
#include "SpriteManager.h"
#include "ZGBMain.h"
UINT8 bank_SPRITE_BLOCK = 2;

// const UINT8 anim_idleblock[] = {1, 0};
const UINT8 anim_destroy[] = {4, 1, 2, 3, 2};

extern struct Sprite* sprite_player;

typedef enum  {
	BLOCK_NORMAL,
	BLOCK_DESTROY
}BLOCK_STATE;

BLOCK_STATE block_state;

void Start_SPRITE_BLOCK() {
	THIS->coll_x = 1u;
	THIS->coll_y = 1u;
	THIS->coll_w = 6u;
	THIS->coll_h = 6u;
	block_state = BLOCK_NORMAL;
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
						SetSpriteAnim(THIS, anim_destroy, 3u);
					}
				}
			}
			break;
	}

}

void Destroy_SPRITE_BLOCK() {
}