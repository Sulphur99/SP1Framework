#include "Transition.h"
extern EGAMESTATES g_eGameState;
extern SGameChar g_sChar;
extern int map;
extern bool load;
extern char grid[80][26];

void transition()
{
	bool loaded = false;

	if (g_sChar.m_cLocation.X == 79 && g_sChar.m_cLocation.Y == 10) //right to left
	{
		if (map == 1)//1-2
		{
			map = 2;
			loaded = true;
		}
		else if (map == 2)//2-5
		{
			map = 5;
			loaded = true;
		}
		else if (map == 5)//endgame
		{
			map = 14;
			loaded = true;
		}
		else if (map == 6)//6-9
		{
			map = 9;
			loaded = true;
		}
		else if (map == 7)//7-6
		{
			map = 6;
			loaded = true;
		}
		else if (map == 10)//10-13
		{
			map = 13;
			loaded = true;
		}
		else if (map == 11)//11-10
		{
			map = 10;
			loaded = true;
		}
		if (loaded = true)
		{
			load = true;
			g_sChar.m_cLocation.X = 1;
			g_sChar.m_cLocation.Y = 10;
		}
		else
		{
			load = false;
		}
	}
	if (g_sChar.m_cLocation.X == 0 && g_sChar.m_cLocation.Y == 10) //left to right
	{
		if (map == 2)//2-1
		{
			map = 1;
			loaded = true;
			grid[80][11] = (char)176;
		}
		else if (map == 5)//5-2
		{
			map = 2;
			loaded = true;
		}
		else if (map == 9)//9-6
		{
			map = 6;
			loaded = true;
		}
		else if (map == 6)//6-7
		{
			map = 7;
			loaded = true;
		}
		else if (map == 13)//13-10
		{
			map = 10;
			loaded = true;
		}
		else if (map == 10)//10-11
		{
			map = 11;
			loaded = true;
		}
		if (loaded = true)
		{
			load = true;
			g_sChar.m_cLocation.X = 78;
			g_sChar.m_cLocation.Y = 10;
		}
	}
	if (g_sChar.m_cLocation.X == 39 && g_sChar.m_cLocation.Y == 1) //up to down(left)
	{
		if (map == 2)//2-3
		{
			map = 3;
			loaded = true;
		}
		else if (map == 4)//4-2
		{
			map = 2;
			loaded = true;
		}
		else if (map == 6)//6-8
		{
			map = 8;
			loaded = true;
		}
		else if (map == 5)//5-6
		{
			map = 6;
			loaded = true;
		}
		else if (map == 10)//10-5
		{
			map = 5;
			loaded = true;
		}
		else if (map == 12)//12-10
		{
			map = 10;
			loaded = true;
		}
		if (loaded = true)
		{
			load = true;
			g_sChar.m_cLocation.X = 39;
			g_sChar.m_cLocation.Y = 18;
		}
	}
	if (g_sChar.m_cLocation.X == 39 && g_sChar.m_cLocation.Y == 19)//down to up(left)
	{
		if (map == 2)//2-4
		{
			map = 4;
			loaded = true;
		}
		else if (map == 3)//3-2
		{
			map = 2;
			loaded = true;
		}
		else if (map == 8)//8-6
		{
			map = 6;
			loaded = true;
		}
		else if (map == 6)//6-5
		{
			map = 5;
			loaded = true;
		}
		else if (map == 5)//5-10
		{
			map = 10;
			loaded = true;
		}
		else if (map == 10)//10-12
		{
			map = 12;
			loaded = true;
		}
		if (loaded = true)
		{
			load = true;
			g_sChar.m_cLocation.X = 39;
			g_sChar.m_cLocation.Y = 2;
		}
	}
	if (g_sChar.m_cLocation.X == 40 && g_sChar.m_cLocation.Y == 1)//up to down(right)
	{
		if (map == 2)//2-3
		{
			map = 3;
			loaded = true;
		}
		else if (map == 4)//4-2
		{
			map = 2;
			loaded = true;
		}
		else if (map == 6)//6-8
		{
			map = 8;
			loaded = true;
		}
		else if (map == 5)//5-6
		{
			map = 6;
			loaded = true;
		}
		else if (map == 10)//10-5
		{
			map = 5;
			loaded = true;
		}
		else if (map == 12)//12-10
		{
			map = 10;
			loaded = true;
		}

		if (loaded = true)
		{
			load = true;
			g_sChar.m_cLocation.X = 40;
			g_sChar.m_cLocation.Y = 18;
		}
	}
	if (g_sChar.m_cLocation.X == 40 && g_sChar.m_cLocation.Y == 19)//down to up(right)
	{
		if (map == 2)//2-4
		{
			map = 4;
			loaded = true;
		}
		else if (map == 3)//3-2
		{
			map = 2;
			loaded = true;
		}
		else if (map == 8)//8-6
		{
			map = 6;
			loaded = true;
		}
		else if (map == 6)//6-5
		{
			map = 5;
			loaded = true;
		}
		else if (map == 5)//5-10
		{
			map = 10;
			loaded = true;
		}
		else if (map == 10)//10-12
		{
			map = 12;
			loaded = true;
		}
		if (loaded = true)
		{
			load = true;
			g_sChar.m_cLocation.X = 40;
			g_sChar.m_cLocation.Y = 2;
		}
	}
}