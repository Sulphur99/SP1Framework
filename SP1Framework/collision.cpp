#include "collision.h"

extern Console g_Console;
extern SGameChar  g_sChar;
extern bool    g_abKeyPressed[K_COUNT];

bool collision(int g_number)
{
	char txt[100][100];
	int height = 0;
	int width = 0;
	ifstream file;

	if (g_number == 1)
	{
		file.open("Level1.txt");
	}
	if (g_number == 2)
	{
		file.open("Level2.txt");
	}
	if (g_number == 3)
	{
		file.open("Level2.1.txt");
	}
	if (g_number == 4)
	{
		file.open("Level2.2.txt");
	}
	if (g_number == 5)
	{
		file.open("Level3.txt");
	}
	if (g_number == 6)
	{
		file.open("Level6.txt");
	}

	COORD c;
	if (file.is_open())
	{
		while (height < 25)
		{
			while (width < 80)
			{
				file >> txt[width][height];
				width++;
			}
			width = 0;
			height++;
		}
		file.close();
	}

	if (g_abKeyPressed[K_UP] && g_sChar.m_cLocation.Y > 0)
	{
		// --------------------------------- UNABLE TO MOVE UP IF ITS NOT ' ' ---------------------------------------------// 
		if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 2] != '-')
		{
			return false;
		}

	}
	if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X > 0)
	{
		// --------------------------------- UNABLE TO MOVE LEFT IS ITS NOT ' ' -------------------------------------------//
		if (txt[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y - 1] != '-')
		{
			return false;
		}

	}
	if (g_abKeyPressed[K_DOWN] && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1)
	{
		// ---------------------------------- UNABLE TO MOVE DOWN IF ITS NOT ' ' -----------------------------------------//
		if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] != '-')
		{
			return false;
		}
	}
	if (g_abKeyPressed[K_RIGHT] && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1)
	{
		// ---------------------------------- UNABLE TO MOVE RIGHT IF ITS NOT ' ' ----------------------------------------//
		if (txt[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y - 1] != '-')
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