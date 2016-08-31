#include "MovableObj.h"

extern Console g_Console;
extern SGameChar  g_sChar;
extern bool    g_abKeyPressed[K_COUNT];
extern char grid[80][26];
bool pull;

int checkMobj()
{
	if (pull == true)
	{
		if (g_abKeyPressed[K_UP] && g_sChar.m_cLocation.Y > 0)
		{
			if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'O' && grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == (char)176)
			{
				return 5;
			}
		}
		else if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X > 0)
		{
			if (grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'O' && grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == (char)176)
			{
				return 6;
			}
		}
		else if (g_abKeyPressed[K_DOWN] && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1)
		{
			if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'O' && grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == (char)176)
			{
				return 7;
			}
		}
		else if (g_abKeyPressed[K_RIGHT] && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1)
		{
			if (grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'O' && grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == (char)176)
			{
				return 8;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if (g_abKeyPressed[K_UP] && g_sChar.m_cLocation.Y > 0)
		{
			if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'O' && grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 2] == (char)176)
			{
				return 1;
			}
		}
		else if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X > 0)
		{
			if (grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'O' && grid[g_sChar.m_cLocation.X - 2][g_sChar.m_cLocation.Y] == (char)176)
			{
				return 2;
			}
		}
		else if (g_abKeyPressed[K_DOWN] && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1)
		{
			if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'O' && grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 2] == (char)176)
			{
				return 3;
			}
		}
		else if (g_abKeyPressed[K_RIGHT] && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1)
		{
			if (grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'O' && grid[g_sChar.m_cLocation.X + 2][g_sChar.m_cLocation.Y] == (char)176)
			{
				return 4;
			}
		}
		else
		{
			return 0;
		}
	}
}

void MoveObj(int checkMobj)
{
	int obj = checkMobj;

	if (obj == 1)
	{
		grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] = (char)176;
		grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 2] = 'O';
	}
	if (obj == 2)
	{
		grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] = (char)176;
		grid[g_sChar.m_cLocation.X - 2][g_sChar.m_cLocation.Y] = 'O';
	}
	if (obj == 3)
	{
		grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] = (char)176;
		grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 2] = 'O';
	}
	if (obj == 4)
	{
		grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] = (char)176;
		grid[g_sChar.m_cLocation.X + 2][g_sChar.m_cLocation.Y] = 'O';
	}
	if (obj == 5)
	{
		grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] = (char)176;
		grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] = 'O';
		g_sChar.m_cLocation.Y+2;
	}
	if (obj == 6)
	{
		grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] = (char)176;
		grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] = 'O';
		g_sChar.m_cLocation.X + 2;
	}
	if (obj == 7)
	{
		grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] = (char)176;
		grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] = 'O';
		g_sChar.m_cLocation.Y - 2;
	}
	if (obj == 8)
	{
		grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] = (char)176;
		grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] = 'O';
		g_sChar.m_cLocation.X - 2;
	}
}