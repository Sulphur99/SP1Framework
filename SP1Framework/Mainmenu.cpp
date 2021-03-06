#include "Mainmenu.h"

extern bool g_abKeyPressed[K_COUNT];
extern SGameSelector  g_sSelector;
extern EGAMESTATES g_eGameState;
extern Console g_Console;
extern double g_dBounceTime;
extern double g_dElapsedTime;
extern int map;
char Main[80][26];

void renderSelector()
{
	g_Console.writeToBuffer(g_sSelector.c_cLocation, (char)175, 0x0C);
}

void moveSelector()
{
	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
		return;

	if (g_abKeyPressed[K_UP] && Main[g_sSelector.c_cLocation.X][g_sSelector.c_cLocation.Y - 1] == (char)177)
	{
		g_sSelector.c_cLocation.Y--;
		bSomethingHappened = true;
	}
	if (g_abKeyPressed[K_DOWN] && Main[g_sSelector.c_cLocation.X][g_sSelector.c_cLocation.Y + 1] == (char)177)
	{
		g_sSelector.c_cLocation.Y++;
		bSomethingHappened = true;
	}
	if (bSomethingHappened)
	{
		g_dBounceTime = g_dElapsedTime + 0.125;
	}
}

void menu()
{
	moveSelector();

	if (g_abKeyPressed[K_ENTER] && g_sSelector.c_cLocation.Y == 11)
	{
		g_eGameState = S_GAME;
		map = 1;
	}
	if (g_abKeyPressed[K_ENTER] && g_sSelector.c_cLocation.Y == 13)
	{
		g_bQuitGame = true;
	}
}

void rendermenu()
{
	ifstream read("Mainmenu.txt");
	int height = 0;
	int width = 0;

	if (read.is_open())
	{
		while (height < 25)
		{
			while (width < 80)
			{
				read >> Main[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		read.close();
	}

	COORD c;

	for (int y = 0; y < 26; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			if (Main[x][y] == '-')
			{
				Main[x][y] = ' ';
			}
			if (Main[x][y] == 'W')
			{
				Main[x][y] = (char)178;
			}
			if (Main[x][y] == 'M')
			{
				Main[x][y] = (char)177;
			}
			if (Main[x][y] == '\n')
			{
				Main[x][y] = ' ';
			}
			c.X = x;
			if (Main[x][y] == (char)178)
			{
				g_Console.writeToBuffer(c, Main[x][y], 0x0E);
			}
			else
			{
				g_Console.writeToBuffer(c, Main[x][y]);
			}
		}
	}
	renderSelector();
	c.X = 28;
	c.Y = 22;
	g_Console.writeToBuffer(c, "<arrow keys> to move");
	c.Y = 23;
	g_Console.writeToBuffer(c, "<enter> to select");

	if (g_sSelector.c_cLocation.Y == 11)
	{
		c.X = 32;
		c.Y = 11;
		g_Console.writeToBuffer(c, "STARTGAME", 0x0C);
		c.X = 29;
		c.Y = 18;
		g_Console.writeToBuffer(c, "Play the game");
	}
	else if (g_sSelector.c_cLocation.Y != 11)
	{
		c.X = 32;
		c.Y = 11;
		g_Console.writeToBuffer(c, "STARTGAME");
	}
	if (g_sSelector.c_cLocation.Y == 12)
	{
		c.X = 32;
		c.Y = 12;
		g_Console.writeToBuffer(c, "CONTROLS", 0x0C);
		c.X = 29;
		c.Y = 15;
		g_Console.writeToBuffer(c, "<arrow keys> to move");
		c.Y = 16;
		g_Console.writeToBuffer(c, "<spacebar> to toggle push and pull mode");
		c.Y = 17;
		g_Console.writeToBuffer(c, "Z to interact");
		c.Y = 18;
		g_Console.writeToBuffer(c, "I to open and close inventory");
		c.Y = 19;
		g_Console.writeToBuffer(c, "K to combine key pieces in inventory");
	}
	else if (g_sSelector.c_cLocation.Y != 12)
	{
		c.X = 32;
		c.Y = 12;
		g_Console.writeToBuffer(c, "CONTROLS");
	}
	if (g_sSelector.c_cLocation.Y == 13)
	{
		c.X = 32;
		c.Y = 13;
		g_Console.writeToBuffer(c, "QUIT", 0x0C);
		c.X = 29;
		c.Y = 18;
		g_Console.writeToBuffer(c, "Quit the game");
	}
	else if (g_sSelector.c_cLocation.Y != 13)
	{
		c.X = 32;
		c.Y = 13;
		g_Console.writeToBuffer(c, "QUIT");
	}
}