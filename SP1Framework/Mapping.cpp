#include "Mapping.h"

extern Console g_Console;

char** Mapping(char** grid, int g_level)
{
	ifstream read;

	if (g_level == 1)
	{
		clearScreen();
		read.open("Level1.txt");
	}
	if (g_level == 2)
	{
		clearScreen();
		read.open("Level2.txt");
	}
	if (g_level == 3)
	{
		clearScreen();
		read.open("Level2.1.txt");
	}
	if (g_level == 4)
	{
		clearScreen();
		read.open("Level2.2.txt");
	}
	if (g_level == 5)
	{
		clearScreen();
		read.open("Level3.txt");
	}


	if (read.is_open())
	{
		for (int i = 0; i < 25; i++)
		{
			grid[i] = new char[80];

			for (int j = 0; j < 80; j++)
			{
				read >> grid[i][j];
			}
		}
		read.close();
	}

	return grid;
}

void print_map(char** grid)
{
	COORD c;

	for (int i = 0; i < 25; ++i)
	{
		c.Y = i + 1;
		for (int j = 0; j < 80; ++j)
		{
			if (grid[i][j] == '-')
			{
				grid[i][j] = (char)176;
			}
			if (grid[i][j] == 'W')
			{
				grid[i][j] = (char)178;
			}
			if (grid[i][j] == '\n')
			{
				grid[i][j] = ' ';
			}
			c.X = j;
			g_Console.writeToBuffer(c, grid[i][j]);
		}
	}
}