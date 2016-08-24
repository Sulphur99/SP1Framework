#include "Mapping.h"

extern Console g_Console;
extern char grid[80][26];

void loadMap1()
{
	ifstream file("Level1.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 25)
		{
			while (width < 80)
			{
				file >> grid[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
}
void loadMap2()
{
	ifstream file("Level2.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 25)
		{
			while (width < 80)
			{
				file >> grid[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
}

void loadMap3()
{
	ifstream file("Level2.1.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 25)
		{
			while (width < 80)
			{
				file >> grid[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
}

void loadMap4()
{
	ifstream file("Level2.2.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 25)
		{
			while (width < 80)
			{
				file >> grid[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
}

void loadMap5()
{
	ifstream file("Level3.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 25)
		{
			while (width < 80)
			{
				file >> grid[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
}

void loadMap6()
{
	ifstream file("Level3.1.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 25)
		{
			while (width < 80)
			{
				file >> grid[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
}

void loadMap7()
{
	ifstream file("Level3.2.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 25)
		{
			while (width < 80)
			{
				file >> grid[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
}

void loadMap8()
{
	ifstream file("Level3.3.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 25)
		{
			while (width < 80)
			{
				file >> grid[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
}

void loadMap9()
{
	ifstream file("Level3.4.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 25)
		{
			while (width < 80)
			{
				file >> grid[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
}

void loadMap10()
{
	ifstream file("Level3.5.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 25)
		{
			while (width < 80)
			{
				file >> grid[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
}

void loadMap11()
{
	ifstream file("Level3.6.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 25)
		{
			while (width < 80)
			{
				file >> grid[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
}

void loadMap12()
{
	ifstream file("Level3.7.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 25)
		{
			while (width < 80)
			{
				file >> grid[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
}

void loadMap13()
{
	ifstream file("Level3.8.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 25)
		{
			while (width < 80)
			{
				file >> grid[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
}