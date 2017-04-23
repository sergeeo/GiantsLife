#pragma bank=2
#include "SpriteTank.h"
#include "SpriteManager.h"
#include "ZGBMain.h"
UINT8 bank_SPRITE_TANK = 2;

// const UINT8 anim_idleblock[] = {1, 0};
const UINT8 anim_walktank[] = {3, 0, 1, 2};
const UINT8 anim_destroytank[] = {5, 3, 4, 3, 4, 5};

extern struct Sprite* sprite_player;
UINT8 tank_speed = 1u;
UINT8 tank_direction = 0u;

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
	
	if(sprite_player->x > THIS->x){
		THIS->flags = OAM_VERTICAL_FLAG;
		tank_direction = 0u;
	} else if (sprite_player->x < THIS->x){
		THIS->flags = 0u;
		tank_direction = 1u;
	}
}

void Update_SPRITE_TANK() {

	UINT8 i;
	struct Sprite* spr;
	
	switch(tank_state){
		case TANK_DESTROY:
			if(THIS->current_frame == 4) {
				SpriteManagerRemove(THIS_IDX);
				// SpriteManagerRemoveSprite(THIS);
			}
			break;
		case TANK_NORMAL:
			SetSpriteAnim(THIS, anim_walktank, 9u);
			SPRITEMANAGER_ITERATE(i, spr) {
				if(spr->type == SPRITE_PLAYER || spr->type == SPRITE_PLAYERBODY) {
					if(CheckCollision(THIS, spr)) {
						//SpriteManagerRemove(THIS_IDX);
						tank_state = TANK_DESTROY;
						SetSpriteAnim(THIS, anim_destroytank, 3u);
					}
				}
			}
			if(tank_direction == 0u){
				THIS->flags = OAM_VERTICAL_FLAG;
				THIS->x = THIS->x + tank_speed;
			} else {
				THIS->flags = 0u;
				THIS->x = THIS->x - tank_speed;
			}
			break;
	}

}

void Destroy_SPRITE_TANK() {
}