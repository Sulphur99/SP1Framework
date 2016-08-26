#include "Chest.h"
extern int key;
extern Console g_Console;
extern char grid[80][26];
extern SGameChar g_sChar;
extern bool g_abKeyPressed[K_COUNT];
extern bool collision(int g_level);
extern int check;
extern int map;
extern char keypiece;
extern int value;
int access = 1;
int access2 = 1;
int access3 = 1;
extern int access4;
void renderChests()
{


	if (key > 0 && grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'D' && g_abKeyPressed[K_Z])
	{
		grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] = '-';
		key -= 1;
	}
	if (map == 1 && key == 0 && grid[79][10] == 'D')
	{
		if (grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'T' && g_abKeyPressed[K_Z])
		{
			key += 1;
		}
		if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'T' && g_abKeyPressed[K_Z])
		{
			key += 1;
		}
		if (grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'T' && g_abKeyPressed[K_Z])
		{
			key += 1;
		}
		if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'T' && g_abKeyPressed[K_Z])
		{
			key += 1;
		}
	}
	if (map == 3 && value == 0 || value == 2 && map == 3)//11,70
	{
		if ((g_sChar.m_cLocation.X + 1) == 70 && g_sChar.m_cLocation.Y == 11 && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			if (value == 2)
			{
				value = 1;
			}
			else
			{
				value = 3;
			}
		}
		if (g_sChar.m_cLocation.X == 70 && (g_sChar.m_cLocation.Y + 1) == 11 && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			if (value == 2)
			{
				value = 1;
			}
			else
			{
				value = 3;
			}
		}
		if ((g_sChar.m_cLocation.X - 1) == 70 && g_sChar.m_cLocation.Y == 11 && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			if (value == 2)
			{
				value = 1;
			}
			else
			{
				value = 3;
			}
		}
		if (g_sChar.m_cLocation.X == 70 && (g_sChar.m_cLocation.Y - 1) == 11 && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			if (value == 2)
			{
				value = 1;
			}
			else
			{
				value = 3;
			}
		}
	}
	if (map == 4 && value == 0 || map == 4 && value == 3)//18,39
	{
		if (grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'T' && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			if (value == 3)
			{
				value = 1;
			}
			else
			{
				value = 2;
			}
		}
		if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'T' && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			if (value == 3)
			{
				value = 1;
			}
			else
			{
				value = 2;
			}
		}
		if (grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'T' && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			if (value == 3)
			{
				value = 1;
			}
			else
			{
				value = 2;
			}
		}
		if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'T' && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			if (value == 3)
			{
				value = 1;
			}
			else
			{
				value = 2;
			}
		}
	}
	if (map == 6 && access == 1)//17, 54
	{
		if ((g_sChar.m_cLocation.X + 1) == 54 && g_sChar.m_cLocation.Y == 17 && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			access -= 1;
		}
		if (g_sChar.m_cLocation.X == 54 && (g_sChar.m_cLocation.Y + 1) == 17 && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			access -= 1;
		}
		if ((g_sChar.m_cLocation.X - 1) == 54 && g_sChar.m_cLocation.Y == 17 && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			access -= 1;
		}
		if (g_sChar.m_cLocation.X == 54 && (g_sChar.m_cLocation.Y - 1) == 17 && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			access -= 1;
		}
	}
	if (map == 8 && access2 == 1)
	{
		if (grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'T' && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			access2 -= 1;
		}
		if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'T' && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			access2 -= 1;
		}
		if (grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'T' && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			access2 -= 1;
		}
		if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'T' && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			access2 -= 1;
		}
	}
	if (map == 12 && access3 == 1)//9,18
	{
		if ((g_sChar.m_cLocation.X + 1) == 9 && g_sChar.m_cLocation.Y == 18 && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			access3 -= 1;
		}
		if (g_sChar.m_cLocation.X == 9 && (g_sChar.m_cLocation.Y + 1) == 18 && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			access3 -= 1;
		}
		if ((g_sChar.m_cLocation.X - 1) == 9 && g_sChar.m_cLocation.Y == 18 && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			access3 -= 1;
		}
		if (g_sChar.m_cLocation.X == 9 && (g_sChar.m_cLocation.Y - 1) == 18 && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			access3 -= 1;
		}
	}
	if (map == 13 && access4 == 1)
	{
		if (grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'T' && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			access4 -= 1;
		}
		if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'T' && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			access4 -= 1;
		}
		if (grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'T' && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			access4 -= 1;
		}
		if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'T' && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
			access4 -= 1;
		}
	}
}