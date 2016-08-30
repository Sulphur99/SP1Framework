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
void puzzle3_7()
{
	if (grid[59][7] == 'O' && grid[60][7] == 'O')
	{
		grid[49][15] = (char)176;
		grid[50][15] = (char)176;
		grid[69][15] = (char)176;
		grid[70][15] = (char)176;
	}
}
void puzzle3_4_1()
{
	if (grid[13][2] == 'O' && grid[35][2] == 'O' && grid[58][2] == 'O')
	{
		grid[51][10] = (char)176;
	}
}
void puzzle3_4_2()
{
	if (grid[33][6] == 'O' && grid[53][6] == 'O' && grid[74][6] == 'O')
	{
		grid[52][10] = (char)176;
	}
}
void puzzle3_4_3()
{
	if (grid[41][14] == 'O' && grid[52][14] == 'O' && grid[75][14] == 'O')
	{
		grid[53][10] = (char)176;
	}
}