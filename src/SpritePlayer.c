#pragma bank=2

#include "SpritePlayer.h"
#include "ZGBMain.h"
#include "SpriteManager.h"
#include "Keys.h"
#include "Math.h"
#include "Scroll.h"

UINT8 bank_SPRITE_PLAYER = 2;

const UINT8 anim_jump[] = {1, 0};

typedef enum {
	PLAYER_STATE_NORMAL,
	PLAYER_STATE_JUMPING
}PLAYER_STATE;

PLAYER_STATE player_state;
INT16 player_accel_y;

struct Sprite* sprite_player = 0;
struct Sprite* player_parent = 0;

UINT16 player_old_x, player_old_y;
UINT8 bg_hidden = 0;

UINT8 tile_collision;

void Start_SPRITE_PLAYER() {
	//AQUÍ SE PODRÍA DEFINIR EL COLLIDER MÁS FINAMENTE
	THIS->coll_x = 0;
	THIS->coll_w = 16;
	THIS->coll_y = 0;
	THIS->coll_h = 32;
	
	player_accel_y = 0;

	scroll_target = THIS;
	sprite_player = THIS;
	bg_hidden = 0;
}

// extern UINT8 stage_completion;
// extern UINT8 current_stage;

void CheckCollisionTile() {
	switch(tile_collision) {
		case 3u:
			// load_next = 1;
			break;

		case 4u:
			// load_next = -1;
			break;

		case 33u:
		case 35u:
			// Hit();
			break;

		case 27u:
		case 28u:
			// SET_BIT(stage_completion, current_stage);
			// SetState(STATE_STAGE_SELECT);
			break;
	}
}

void MovePlayer(){
	if(KEY_PRESSED(J_LEFT)){
		tile_collision = TranslateSprite(THIS, -1 << delta_time, 0);
		THIS->flags = OAM_VERTICAL_FLAG;
	}
	else if(KEY_PRESSED(J_RIGHT)){
		tile_collision = TranslateSprite(THIS, 1 << delta_time, 0);
		THIS->flags = 0u;
	}
}

void Jump(){
	if(player_state != PLAYER_STATE_JUMPING) {
		player_accel_y = -50;
		player_state = PLAYER_STATE_JUMPING;
		player_parent = 0;
	}
}

/* void UpdatePlayerHead(){
	TranslateSprite(playerhead_sprite, THIS->x, THIS->y + playerhead_offset_y);
} */

void Update_SPRITE_PLAYER() {
	
	switch(player_state) {
		case PLAYER_STATE_NORMAL:
			MovePlayer();
			
			// Check jumping
			if(KEY_TICKED(J_A)) {
				Jump();
			}
			
			// Check falling
//			if((player_accel_y >> 4) > 1) {
//				player_state = PLAYER_STATE_JUMPING;
//			}

			break;
			
		case PLAYER_STATE_JUMPING:
			if((player_accel_y < 0) && !KEY_PRESSED(J_A)) {
				player_accel_y = 0;
			}

			SetSpriteAnim(THIS, anim_jump, 33u);
			MovePlayer();
			break;
	}
	
	// gravity
	
	if(player_parent == 0) {
		if(player_accel_y < 60) {
			player_accel_y += 2;
		}
		tile_collision = TranslateSprite(THIS, 0, (player_accel_y >> 4));
		if(!tile_collision && delta_time != 0 && player_accel_y < 40) { //Do another iteration if there is no collision
			player_accel_y += 2;
			tile_collision = TranslateSprite(THIS, 0, (player_accel_y >> 4));
		}
		if(tile_collision) {
			if(tile_collision != 3u && tile_collision != 4u) {
				player_accel_y = 0;
				if(player_state == PLAYER_STATE_JUMPING) {
					player_state = PLAYER_STATE_NORMAL;
				}
			}

			 CheckCollisionTile();
		}
	}
	if(player_parent && player_state == PLAYER_STATE_JUMPING) {
		player_accel_y = 0;
		player_state = PLAYER_STATE_NORMAL;
	}
	if(KEY_TICKED(J_B)){
		player_state = PLAYER_STATE_NORMAL;
	}
}


void Destroy_SPRITE_PLAYER() {
	sprite_player = 0;
}