#pragma bank=2
#include "SpritePlane.h"
#include "SpriteManager.h"
#include "ZGBMain.h"
#include "Math.h"
#include "SpriteManager.h"

UINT8 bank_SPRITE_PLANE = 2;

// const UINT8 anim_idleblock[] = {1, 0};
const UINT8 anim_planedestroy[] = {5, 1, 2, 1, 2, 3};

extern struct Sprite* sprite_player;
UINT8 plane_speed = 4u;
UINT8 plane_direction = 0u;

typedef enum  {
	PLANE_NORMAL,
	PLANE_DESTROY
}PLANE_STATE;

PLANE_STATE plane_state;

void Start_SPRITE_PLANE() {
	THIS->coll_x = 2u;
	THIS->coll_y = 3u;
	THIS->coll_w = 14u;
	THIS->coll_h = 10u;
	plane_state = PLANE_NORMAL;
	
	if(sprite_player->x > THIS->x){
		THIS->flags = OAM_VERTICAL_FLAG;
		plane_direction = 0u;
	} else if (sprite_player->x < THIS->x){
		THIS->flags = 0u;
		plane_direction = 1u;
	}
}

void Update_SPRITE_PLANE() {

	UINT8 i;
	struct Sprite* spr;
	
	switch(plane_state){
		case PLANE_DESTROY:
			if(THIS->current_frame == 3) {
				SpriteManagerRemove(THIS_IDX);
				// SpriteManagerRemoveSprite(THIS);
			}
			break;
		case PLANE_NORMAL:
			SPRITEMANAGER_ITERATE(i, spr) {
				if(spr->type == SPRITE_PLAYER || spr->type == SPRITE_PLAYERBODY) {
					if(CheckCollision(THIS, spr)) {
						//SpriteManagerRemove(THIS_IDX);
						plane_state = PLANE_DESTROY;
						SetSpriteAnim(THIS, anim_planedestroy, 6u);
					}
				}
			}
			
			if(plane_direction == 0u){
				THIS->flags = OAM_VERTICAL_FLAG;
				THIS->x = THIS->x + plane_speed;
			} else {
				THIS->flags = 0u;
				THIS->x = THIS->x - plane_speed;
			}
			break;
	}

}

void Destroy_SPRITE_PLANE() {
}