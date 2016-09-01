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
	else if (map != 1)
	{
		if (grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'T' && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
		}
		if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'T' && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
		}
		if (grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'T' && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
		}
		if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'T' && g_abKeyPressed[K_Z])
		{
			keypiece += 1;
		}
	}
}