#include "Mapping.h"

extern Console g_Console;
extern bool load;

void Mapping(int map)
{
	string file;
	ifstream read;
	int width = 0;
	int height = 0;

	if (load == true)
	{
		switch (map)
		{
		case 1: read.open("Level1.txt");
			break;
		case 2: read.open("Level2.txt");
			break;
		case 3: read.open("Level2.1.txt");
			break;
		case 4: read.open("Level2.2.txt");
			break;
		case 5: read.open("Level3.txt");
			break;
		case 6: read.open("Level3.1.txt");
			break;
		case 7: read.open("Level3.2.txt");
			break;
		case 8: read.open("Level3.3.txt");
			break;
		case 9: read.open("Level3.4.txt");
			break;
		case 10: read.open("Level3.5.txt");
			break;
		case 11:read.open("Level3.6.txt");
			break;
		case 12:read.open("Level3.7.txt");
			break;
		case 13: read.open("Level3.8.txt");
			break;
		case 14:read.open("Inventory.txt");
			break;
		}
		load = false;
	}
	
	if (read.is_open())
	{
		while (height < 25)
		{
			while (width < 80)
			{
				read >> grid[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		read.close();
	}
}
