#include "Inventory.h"

extern bool g_abKeyPressed[K_I];
extern int map;
extern int memory;
extern int key;
extern Console g_Console;
COORD a;
extern double g_dElapsedTime;
extern double g_dBounceTime;
extern char keypiece;
extern EGAMESTATES g_eGameState;
extern int access4;

//void inventory()
//{
//	//bool SomethingHappened;
//
//	if (g_abKeyPressed[K_I] && map != 14)
//	{
//		memory = map;
//		map = 14;
//		//SomethingHappened = true;
//
//	}
//	else if (g_abKeyPressed[K_I] && map == 14)
//	{
//		map = memory;
//	}
//	/*if (SomethingHappened)
//	{
//	g_dBounceTime = g_dElapsedTime + 0.125;
//	}*/
//}

void loadInv()
{
	ifstream file;
	int height = 0;
	int width = 0;
	file.open("Inventory.txt");

	char grid2[80][26];

	if (file.is_open())
	{
		while (height < 25)
		{
			while (width < 80)
			{
				file >> grid2[width][height];
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
			if (grid2[x][y] == '-')
			{
				grid2[x][y] = ' ';
			}
			if (grid2[x][y] == 'W')
			{
				grid2[x][y] = (char)178;
			}
			if (grid2[x][y] == '\n')
			{
				grid2[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, grid2[x][y]);
		}
	}
}

void renderInv()
{
	ifstream file;
	int height = 0;
	int width = 0;
	file.open("Inventorytext.txt");
	char grid3[20][1];
	if (file.is_open())
	{
		while (height < 1)
		{
			while (width < 20)
			{
				file >> grid3[width][height];
				if (grid3[width][height] == '-')
				{
					grid3[width][height] = ' ';
				}
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
		if (key == 1)
		{
			a.X = 1;
			a.Y = 2;
			for (int b = 0; b < 7; b++)
			{
				g_Console.writeToBuffer(a, grid3[b][0]);
				a.X += 1;
			}
		}
		if (keypiece > 48)
		{
			a.X = 1;
			a.Y = 2;
			for (int b = 7; b < 20; b++)
			{
				g_Console.writeToBuffer(a, grid3[b][0]);
				a.X += 1;
			}
			g_Console.writeToBuffer(a, keypiece);
		}
		if (keypiece == 50 && g_eGameState == S_INVENTORY && g_abKeyPressed[K_K])
		{
			keypiece -= 2;
			key += 1;
		}
		if (keypiece == 52 && g_eGameState == S_INVENTORY && g_abKeyPressed[K_K] && access4 == 0)
		{
			keypiece -= 4;
			key += 1;
		}
	}
}