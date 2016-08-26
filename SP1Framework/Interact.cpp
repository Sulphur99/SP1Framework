#include "Interact.h"
extern bool g_test;
extern Console g_Console;
extern SGameChar  g_sChar;
extern bool g_abKeyPressed[K_COUNT];
int Activity_feed = 0;
extern char grid[80][26];
extern double g_dElapsedTime;
extern bool setText;
extern int key;

int checkinteract(int g_number)
{
	int height = 0;
	int width = 0;
	ifstream file;
	char txt[100][100];

	/*if (g_sChar.Key != 0)
	{
	g_sChar.Key--;
	txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] = ' ';
	}*/

	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == (char)178)//up
	{
		return 1;
	}

	if (grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == (char)178) //left
	{
		return 1;
	}

	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == (char)178)//down
	{
		return 1;
	}

	if (grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == (char)178)//right
	{
		return 1;
	}

	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'P')
	{
		return 2;
	}

	if (grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'P')
	{
		return 2;
	}

	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'P')
	{
		return 2;
	}

	if (grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'P')
	{
		return 2;
	}

	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'D' && key == 0)
	{
		return 3;
	}

	if (grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'D' && key == 0)
	{
		return 3;
	}

	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'D' && key == 0)
	{
		return 3;
	}

	if (grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'D' && key == 0)
	{
		return 3;
	}

	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'T')
	{
		return 4;
	}

	if (grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'T')
	{
		return 4;
	}

	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'T')
	{
		return 4;
	}

	if (grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'T')
	{
		return 4;
	}

	/*if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 2] == 'Ryan')
	{
	return 5;
	}

	if (txt[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y - 1] == 'Ryan')
	{
	return 5;
	}

	if (txt[g_sChar.mLocation.X][g_sChar.m_cLocation.Y] == 'Ryan')
	{
	return 5;
	}

	if (txt[g_sChar.mLocation.X + 1][g_sChar.m_cLocation.Y - 1] == 'Ryan')
	{
	return 5;
	}
	*/

	else
	{
		return 0;
	}
}

int Interact(int checkobj)
{
	if (checkobj == 1)
	{
		Activity_feed = 1;
	}

	if (checkobj == 2)
	{
		Activity_feed = 2;
	}

	if (checkobj == 3)
	{
		Activity_feed = 3;
	}

	if (checkobj == 4)
	{
		Activity_feed = 4;
	}

	/*
	if (checkobj == 5)
	{
	Activity_feed = 4;
	}
	*/


	else if (checkobj == 0)
	{
		Activity_feed = 0;
	}
	return 0;
}
void renderFeed()
{
	COORD c = g_Console.getConsoleSize();
	c.X = 0;
	c.Y = 20;
	string text;
	int textSize;

	if (Activity_feed == 1 && !setText)
	{
		text = "Curses! A wall blocks your way.";
		textSize = sizeof(text);
		double newTime = g_dElapsedTime + 1.0;

		g_Console.writeToBuffer(c, text, 0x02);

		if (g_dElapsedTime > newTime)
		{
			for (int i = 0; i < textSize; i++)
			{
				g_Console.writeToBuffer(c, " ");
				c.X++;
			}
		}
		setText = true;
	}

	if (Activity_feed == 2 && !setText)
	{
		text = "It's a pillar.";
		textSize = sizeof(text);
		double newTime = g_dElapsedTime + 1.0;

		g_Console.writeToBuffer(c, text, 0x02);

		if (g_dElapsedTime > newTime)
		{
			for (int i = 0; i < textSize; i++)
			{
				g_Console.writeToBuffer(c, " ");
				c.X++;
			}
		}
		setText = true;
	}

	if (Activity_feed == 3 && !setText)
	{
		text = "The door's locked.";
		textSize = sizeof(text);
		int newTime = g_dElapsedTime + 1.0;

		g_Console.writeToBuffer(c, text, 0x02);

		if (g_dElapsedTime > newTime)
		{
			for (int i = 0; i < textSize; i++)
			{
				g_Console.writeToBuffer(c, " ");
				c.X++;
			}
		}
		setText = true;
	}

	if (Activity_feed == 4)
	{
		text = "You found a chest! The chest contains a shimmering key.";
		g_Console.writeToBuffer(c, text, 0x02);
	}

	/*if (Activity_feed == 5)
	{
	text = "The chest is empty. Maybe because you took whatever's in it.";
	g_Console.writeToBuffer(c, text, 0x02);
	}
	*/
}