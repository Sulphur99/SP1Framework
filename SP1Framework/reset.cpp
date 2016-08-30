#include "reset.h"

extern int map;
extern EGAMESTATES g_eGameState;
extern bool load;

void reset()
{
	Mapping(map);
	load = true;
	g_eGameState = S_GAME;
}