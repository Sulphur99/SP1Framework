#include "Transition.h"
extern EGAMESTATES g_eGameState;
extern SGameChar g_sChar;
extern int map;
void transition()
{
	if (g_sChar.m_cLocation.X == 79 && g_sChar.m_cLocation.Y == 10)//right to left
	{
		if (g_eGameState == S_GAME)
		{
			map = 1;
		}
		if (g_eGameState == S_LEVEL2)
		{
			map = 4;
		}
		if (g_eGameState == S_LEVEL32)
		{
			map = 5;
		}
		if (g_eGameState == S_LEVEL31)
		{
			map = 8;
		}
		if (g_eGameState == S_LEVEL36)
		{
			map = 9;
		}
		if (g_eGameState == S_LEVEL35)
		{
			map = 12;
		}
		g_sChar.m_cLocation.X = 1;
		g_sChar.m_cLocation.Y = 10;
		}
		if (g_sChar.m_cLocation.X == 0 && g_sChar.m_cLocation.Y == 10)// left to right
		{
			if (g_eGameState == S_LEVEL2)
			{
				map = 0;
			}
			if (g_eGameState == S_LEVEL3)
			{
				map = 1;
			}
			if (g_eGameState == S_LEVEL31)
			{
				map = 6;
			}
			if (g_eGameState == S_LEVEL34)
			{
				map = 5;
			}
			if (g_eGameState == S_LEVEL35)
			{
				map = 10;
			}
			if (g_eGameState == S_LEVEL38)
			{
				map = 9;
			}
			g_sChar.m_cLocation.X = 78;
			g_sChar.m_cLocation.Y = 10;
		}
		if (g_sChar.m_cLocation.X == 39 && g_sChar.m_cLocation.Y == 1)//up to down(left)
		{
			g_sChar.m_cLocation.X = 39;
			g_sChar.m_cLocation.Y = 18;
			if (g_eGameState == S_LEVEL2)
			{
				map = 2;
			}
			if (g_eGameState == S_LEVEL22)
			{
				map = 1;
			}
			if (g_eGameState == S_LEVEL3)
			{
				map = 5;
			}
			if (g_eGameState == S_LEVEL31)
			{
				map = 7;
			}
			if (g_eGameState == S_LEVEL35)
			{
				map = 4;
			}
			if (g_eGameState == S_LEVEL37)
			{
				map = 9;
			}
		}
		if (g_sChar.m_cLocation.X == 39 && g_sChar.m_cLocation.Y == 19)//down to up(left)
		{
			if (g_eGameState == S_LEVEL21)
			{
				map = 1;
			}
			if (g_eGameState == S_LEVEL2)
			{
				map = 3;
			}
			if (g_eGameState == S_LEVEL31)
			{
				map = 4;
			}
			if (g_eGameState == S_LEVEL33)
			{
				map = 5;
			}
			if (g_eGameState == S_LEVEL3)
			{
				map = 9;
			}
			if (g_eGameState == S_LEVEL35)
			{
				map = 11;
			}
			g_sChar.m_cLocation.X = 39;
			g_sChar.m_cLocation.Y = 2;
		}
		if (g_sChar.m_cLocation.X == 40 && g_sChar.m_cLocation.Y == 1)//up to down(right)
		{
			g_sChar.m_cLocation.X = 40;
			g_sChar.m_cLocation.Y = 18;
			if (g_eGameState == S_LEVEL2)
			{
				map = 2;
			}
			if (g_eGameState == S_LEVEL22)
			{
				map = 1;
			}
			if (g_eGameState == S_LEVEL3)
			{
				map = 5;
			}
			if (g_eGameState == S_LEVEL31)
			{
				map = 7;
			}
			if (g_eGameState == S_LEVEL35)
			{
				map = 4;
			}
			if (g_eGameState == S_LEVEL37)
			{
				map = 9;
			}
		}
		if (g_sChar.m_cLocation.X == 40 && g_sChar.m_cLocation.Y == 19)//down to up(right)
		{
			if (g_eGameState == S_LEVEL21)
			{
				map = 1;
			}
			if (g_eGameState == S_LEVEL2)
			{
				map = 3;
			}
			if (g_eGameState == S_LEVEL31)
			{
				map = 4;
			}
			if (g_eGameState == S_LEVEL33)
			{
				map = 5;
			}
			if (g_eGameState == S_LEVEL3)
			{
				map = 9;
			}
			if (g_eGameState == S_LEVEL35)
			{
				map = 11;
			}
			g_sChar.m_cLocation.X = 40;
			g_sChar.m_cLocation.Y = 2;
		}
}