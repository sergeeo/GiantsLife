#pragma bank=2
#include "StateVictory.h"
UINT8 bank_STATE_VICTORY = 2;

#include "..\res\src\pressstarttiles.h"
#include "..\res\src\victory.h"
#include "..\res\src\font.h"

#include "ZGBMain.h"
#include "Print.h"
#include "Scroll.h"
#include "Keys.h"
#include "SpriteManager.h"

/* extern const unsigned char* exo_start_mod_Data[]; */

extern UINT8 n_sprite_types;
UINT8 collision_tiles[] = {1, 0};

void PrintEnding() {
	PRINT_POS(4, 4);
	Printf("PLEASE GIANT");
	
	PRINT_POS(4, 6);
	Printf("CONTROL YOUR");
	
	PRINT_POS(4, 8);
	Printf("FEELINGS...");
	
	PRINT_POS(4, 10);
	Printf("DONT DESTROY");
	
	PRINT_POS(4, 12);
	Printf("FOR FUN...");
}

void Start_STATE_VICTORY() {
	UINT8 i;

	SPRITES_8x16;
	for(i = 0; i != n_sprite_types; ++ i) {
		SpriteManagerLoad(i);
	}
	SHOW_SPRITES;

	InitScrollTiles(0, 24, pressstarttiles, 3);
	InitScroll(victoryWidth, victoryHeight, victory, collision_tiles, 0, 3);
	SHOW_BKG;
	
	INIT_FONT(font, 3, PRINT_BKG);
	PrintEnding();
}

void Update_STATE_VICTORY() {
	if(KEY_TICKED(J_START)) {
	SetState(STATE_PRESSSTART);
	}
}