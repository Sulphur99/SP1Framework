#include "LoadMap.h"

extern char g_Mapping[14][80][26];
extern int map;

void loadmap()
{
	int width = 0;
	int height = 0;
	string mapname;

	for (map = 0; map < 14; map++)
	{
		switch (map)
		{
		case 0: mapname = "Level1.txt";
			break;
		case 1: mapname = "Level2.txt";
			break;
		case 2: mapname = "Level2.1.txt";
			break;
		case 3: mapname = "Level2.2.txt";
			break;
		case 4: mapname = "Level3.txt";
			break;
		case 5: mapname = "Level3.1.txt";
			break;
		case 6: mapname = "Level3.2.txt";
			break;
		case 7: mapname = "Level3.3.txt";
			break;
		case 8: mapname = "Level3.4.txt";
			break;
		case 9: mapname = "Level3.5.txt";
			break;
		case 10: mapname = "Level3.6.txt";
			break;
		case 11: mapname = "Level3.7.txt";
			break;
		case 12: mapname = "Level3.8.txt";
			break;
		case 13: mapname = "Inventory.txt";
			break;
		}		
	}
	ifstream read(mapname);
	read.open(mapname);
	char letter;
	while(read.get(letter))
	{
		for (height = 0; height < 26; height++)
		{

			for (width = 0; width < 80; width++)
			{
				letter >> g_Mapping[map][width][height];
			}
			width = 0;
		}
		read.close();
	}
	
}

/*loadmaps()
{
	for (mapno = 0; mapno < 14; mapno++)
	{
		switch (mapno)
		{
		case 0: mapname = "level1.txt";
			break;
		case 1: mapname = "level2.txt";
		}

		openfile(mapname);

		for (y = 0; y < MAX_ROW; y++)
		{
			for (x = 0; x < MAX_COLUMN; x++)
			{
				g_OriginalMapData[mapno][x][y] = letterfrommapfile; // g_OriginalMapData is global variable.
			}
		}

		closefile();
	}
}*/
