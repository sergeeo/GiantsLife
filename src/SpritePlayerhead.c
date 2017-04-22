#pragma bank=2

#include "SpritePlayerhead.h"
#include "ZGBMain.h"
#include "SpriteManager.h"
#include "Keys.h"
#include "Math.h"
#include "Scroll.h"

UINT8 bank_SPRITE_PLAYERHEAD = 2;

extern struct Sprite* sprite_player;

void Start_SPRITE_PLAYERHEAD() {

}

void Update_SPRITE_PLAYERHEAD() {
	THIS->x = sprite_player->x;
	THIS->y = sprite_player->y - 15u;
}

void Destroy_SPRITE_PLAYERHEAD() {
}