#include "Inventory.h"

extern bool g_abKeyPressed[K_I];
extern int map;
extern int memory;
extern int key;
extern Console g_Console;
COORD a;
extern double g_dElapsedTime;
extern double g_dBounceTime;

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
				grid2[x][y] = (char)176;
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
	if (key > 0 && map == 14)
	{
		a.X = 1;
		a.Y = 2;
		g_Console.writeToBuffer(a, "Key x1");
	}
}