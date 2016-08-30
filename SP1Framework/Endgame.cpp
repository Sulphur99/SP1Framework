#include "Endgame.h"

extern Console g_Console;
extern bool g_abKeyPressed[K_COUNT];
extern double gametime;
extern EGAMESTATES  g_eGameState;

void Endgame()
{
	if (g_abKeyPressed[K_ESCAPE])
	{
		g_eGameState = S_MAINMENU;
	}
}

void renderEndgame()
{
	ifstream file;
	int height = 0;
	int width = 0;
	file.open("WIN_SCREEN.txt");

	char grid4[80][26];

	if (file.is_open())
	{
		while (height < 25)
		{
			while (width < 80)
			{
				file >> grid4[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}

	COORD c;
	for (int y = 0; y < 26; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			WORD color=0x07;
			if (grid4[x][y] == '-')
			{
				color = 0x07;
				grid4[x][y] = ' ';
			}
			if (grid4[x][y] == 'W')
			{
				grid4[x][y] = (char)178;
			}
			if (grid4[x][y] == '\n')
			{
				grid4[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, grid4[x][y],color);
		}
	}
}