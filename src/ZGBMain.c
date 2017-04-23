#include "ZGBMain.h"

#include "StateGame.h"
#include "StateGame2.h"
#include "StateGame3.h"
#include "StateGameOver.h"
#include "StateIntro1.h"
#include "StateIntro2.h"
#include "StateIntro3.h"
#include "StatePressStart.h"
#include "StateVictory.h"

#include "SpritePlayer.h"
#include "SpritePlayerBody.h"
#include "SpriteBlock.h"

#include "../res/src/player.h"
#include "../res/src/playerbody.h"
#include "../res/src/block.h"
#include "Math.h"

UINT8 next_state = STATE_GAME;

SET_N_STATES(N_STATES);
SET_N_SPRITE_TYPES(N_SPRITE_TYPES);

void InitStates() {
	INIT_STATE(STATE_PRESSSTART);
	INIT_STATE(STATE_INTRO1);
	INIT_STATE(STATE_GAME);
	INIT_STATE(STATE_INTRO2);
	INIT_STATE(STATE_GAME2);
	INIT_STATE(STATE_INTRO3);
	INIT_STATE(STATE_GAME3);
	INIT_STATE(STATE_GAMEOVER);
	INIT_STATE(STATE_VICTORY);
}

void InitSprites() {
	INIT_SPRITE(SPRITE_PLAYER, player, 3, FRAME_16x16, 2);
	INIT_SPRITE(SPRITE_PLAYERBODY, playerbody, 3, FRAME_16x16, 4);
	INIT_SPRITE(SPRITE_BLOCK,  block,  3, FRAME_16x16, 5);
}

UINT8 GetTileReplacement(UINT8* tile_ptr, UINT8* tile) {
	if(current_state == STATE_GAME) {
		if(U_LESS_THAN(255 - (UINT16)*tile_ptr, N_SPRITE_TYPES)) {
			*tile = 0;
			return 255 - (UINT16)*tile_ptr;
		}
		*tile = *tile_ptr;
	}
	return 255u;
}