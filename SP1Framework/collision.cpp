#include "collision.h"

extern Console g_Console;
extern SGameChar  g_sChar;
extern bool    g_abKeyPressed[K_COUNT];

bool collision(int g_level)
{
	char txt[100][100];
	int height = 0;
	int width = 0;
	ifstream file;

	if (g_level == 1)
	{
		file.open("Level1.txt");
	}
	if (g_level == 2)
	{
		file.open("Level2.txt");
	}
	if (g_level == 3)
	{
		file.open("Level2.1.txt");
	}
	if (g_level == 4)
	{
		file.open("Level2.2.txt");
	}
	if (g_level == 5)
	{
		file.open("Level3.txt");
	}
	if (g_level == 6)
	{
		file.open("Level3.1.txt");
	}
	if (g_level == 7)
	{
		file.open("Level3.2.txt");
	}
	if (g_level == 8)
	{
		file.open("Level3.3.txt");
	}
	if (g_level == 9)
	{
		file.open("Level3.4.txt");
	}
	if (g_level == 10)
	{
		file.open("Level3.5.txt");
	}
	if (g_level == 11)
	{
		file.open("Level3.6.txt");
	}
	if (g_level == 12)
	{
		file.open("Level3.7.txt");
	}
	if (g_level == 13)
	{
		file.open("Level3.8.txt");
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
		if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] != '-')
		{
			return false;
		}
	}
	if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X > 0)
	{
		if (txt[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] != '-')
		{
			return false;
		}
	}
	if (g_abKeyPressed[K_DOWN] && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1)
	{
		if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] != '-')
		{
			return false;
		}
	}
	if (g_abKeyPressed[K_RIGHT] && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1)
	{
		if (txt[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] != '-')
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