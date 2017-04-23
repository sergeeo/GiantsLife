#pragma bank=2
#include "StateIntro1.h"
UINT8 bank_STATE_INTRO1 = 2;

#include "..\res\src\pressstarttiles.h"
#include "..\res\src\intro.h"
#include "..\res\src\font.h"

#include "ZGBMain.h"
#include "Print.h"
#include "Scroll.h"
#include "Keys.h"
#include "SpriteManager.h"

/* extern const unsigned char* exo_start_mod_Data[]; */

extern UINT8 n_sprite_types;
UINT8 collision_tiles[] = {1, 0};

void PrintTitles() {
	PRINT_POS(4, 4);
	Printf("THIS GIANT");
	
	PRINT_POS(4, 6);
	Printf("WOKE UP TODAY");
	
	PRINT_POS(4, 8);
	Printf("IN A REALLY");
	
	PRINT_POS(4, 10);
	Printf("BAD MOOD!");
	
	PRINT_POS(4, 12);
	Printf("PRESS START");
}

void Start_STATE_INTRO1() {
	UINT8 i;

	SPRITES_8x16;
	for(i = 0; i != n_sprite_types; ++ i) {
		SpriteManagerLoad(i);
	}
	SHOW_SPRITES;

	InitScrollTiles(0, 24, pressstarttiles, 3);
	InitScroll(introWidth, introHeight, intro, collision_tiles, 0, 3);
	SHOW_BKG;
	
	INIT_FONT(font, 3, PRINT_BKG);
	PrintTitles();
}

void Update_STATE_INTRO1() {
		if(KEY_TICKED(J_START)) {
			SetState(STATE_GAME);
	}
}