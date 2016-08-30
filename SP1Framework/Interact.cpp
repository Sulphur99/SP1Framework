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
extern int map;

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
	
	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == (char)241)
	{
		return 5;
	}

	if (grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == (char)241)
	{
		return 5;
	}

	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == (char)241)
	{
		return 5;
	}

	if (grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == (char)241)
	{
		return 5;
	}

	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == (char)194)
	{
		return 6;
	}

	if (grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == (char)194)
	{
		return 6;
	}

	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == (char)194)
	{
		return 6;
	}

	if (grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == (char)194)
	{
		return 6;
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
	Activity_feed = checkobj;
	return 0;
}
void renderFeed()
{
	COORD c = g_Console.getConsoleSize();
	c.X = 0;
	c.Y = 21;
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
		if (map == 1)
		{
			text = "You found a chest! The chest contains a shimmering key.";
			g_Console.writeToBuffer(c, text, 0x02);
		}

		if (map == 3)
		{
			text = "You found a chest! A key piece lies within.";
			g_Console.writeToBuffer(c, text, 0x02);
		}

		if (map == 4)
		{
			text = "You found a chest! A second key piece lies within.";
			g_Console.writeToBuffer(c, text, 0x02);
		}

		if (map == 6)
		{
			text = "You found a chest! It contains a key piece.";
			g_Console.writeToBuffer(c, text, 0x02);
		}

		if (map == 8)
		{
			text = "You found a chest! A key piece shines from within.";
			g_Console.writeToBuffer(c, text, 0x02);
		}

		if (map == 12)
		{
			text = "You found a chest! A keypiece lies within.";
			g_Console.writeToBuffer(c, text, 0x02);
		}

		if (map == 13)
		{
			text = "You found a chest! The chest has a keypiece.";
			g_Console.writeToBuffer(c, text, 0x02);
		}

	}
	if (Activity_feed == 5)
	{
		if (map == 1)
		{
			text = "You can push boulders by walking up to them.";
			g_Console.writeToBuffer(c, text, 0x02);
		}
		
		if (map == 3)
		{
			text = "One of these chests are not like the others...";
			g_Console.writeToBuffer(c, text, 0x02);
		}
		
		if (map == 7)
		{
			text = "Not all endeavours are rewarded.";
			g_Console.writeToBuffer(c, text, 0x02);
		}

		if (map == 8)
		{
			text = "Only one who understands balance shall find the way.";
			g_Console.writeToBuffer(c, text, 0x02);
		}

		if (map == 10)
		{
			text = "Greed will only waste your time.";
			g_Console.writeToBuffer(c, text, 0x02);
		}

		if (map == 11)
		{
			text = "Working hard will not always bear fruit.";
			g_Console.writeToBuffer(c, text, 0x02);
		}
	}

	if (Activity_feed == 6)
	{
		text = "The chest was empty.";
		g_Console.writeToBuffer(c, text, 0x02);
	}

	/*if (Activity_feed == 5)
	{
	text = "The chest is empty. Maybe because you took whatever's in it.";
	g_Console.writeToBuffer(c, text, 0x02);
	}
	*/
}