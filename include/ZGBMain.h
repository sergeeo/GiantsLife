#ifndef ZGBMAIN_H
#define ZGBMAIN_H

#include "main.h"

typedef enum {
	STATE_PRESSSTART,
	STATE_INTRO1,
	STATE_GAME,
	STATE_INTRO2,
	STATE_GAME2,
	STATE_INTRO3,
	STATE_GAME3,
	STATE_GAMEOVER,
	STATE_VICTORY,

	N_STATES
} STATE;

typedef enum {
	SPRITE_PLAYER,
	SPRITE_PLAYERBODY,
	SPRITE_BLOCK,
	SPRITE_PLANE,
	SPRITE_TANK,

	N_SPRITE_TYPES
} SPRITE_TYPE;

#endif