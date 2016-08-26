#include "Puzzles.h"

extern Console g_Console;
extern SGameChar  g_sChar;
extern bool    g_abKeyPressed[K_COUNT];
extern char grid[80][26];

void puzzle3_3()
{
	if (grid[18][9] == 'O' && grid[19][9] == 'O' && grid[17][10] == 'O'  && grid[18][11] == 'O' && grid[19][11] == 'O'  && grid[20][10] == 'O')
	{
		grid[39][9] = (char)176;
		grid[40][9] = (char)176;
	}
}