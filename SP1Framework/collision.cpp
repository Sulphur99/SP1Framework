#include "collision.h"

extern Console g_Console;
extern SGameChar  g_sChar;
extern bool    g_abKeyPressed[K_COUNT];
extern char grid[80][26];

bool collision(int g_level)
{
	char txt[100][100];
	int height = 0;
	int width = 0;
	ifstream file;

	if (g_abKeyPressed[K_UP] && g_sChar.m_cLocation.Y > 0)
	{
		if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] != (char)176)
		{
			return false;
		}
	}
	if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X > 0)
	{
		if (grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] != (char)176)
		{
			return false;
		}
	}
	if (g_abKeyPressed[K_DOWN] && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1)
	{
		if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] != (char)176)
		{
			return false;
		}
	}
	if (g_abKeyPressed[K_RIGHT] && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1)
	{
		if (grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] != (char)176)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return true;
	}
}