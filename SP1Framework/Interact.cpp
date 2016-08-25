#include "Interact.h"
extern bool g_test;
extern Console g_Console;
extern SGameChar  g_sChar;
extern bool g_abKeyPressed[K_COUNT];
int Activity_feed = 0;

int checkinteract(int g_number)
{
	int height = 0;
	int width = 0;
	ifstream file;
	char txt[100][100];

		if (g_number == 1)
		 {
			file.open("Level1.txt");
		 }
	
		if (g_number == 2)
		 {
			file.open("Level2.txt");
		 }
	
		if (g_number == 3)
		{
			file.open("Level2.1.txt");
		}

		if (g_number == 4)
		{
			file.open("Level2.2.txt");
		}

		if (g_number == 5)
		{
			file.open("Level3.txt");
		}

		if (g_number == 6)
		{
			file.open("Level3.1.txt");
		}
	
		if (g_number == 7)
		{
			file.open("Level3.2.txt");
		}
	
		if (g_number == 8)
		{
			file.open("Level3.3.txt");
		}
	
		if (g_number == 9)
		{
			file.open("Level3.4.txt");
		}
	
		if (g_number == 10)
		{
			file.open("Level3.5.txt");
		}
	
		if (g_number == 11)
		{
			file.open("Level3.6.txt");
		}

		if (g_number == 12)
		{
			file.open("Level3.7.txt");
		}
	if (g_number == 13)
	{
		file.open("Level3.8.txt");
	}

	COORD c;
	if (file.is_open())
	{
		while (height < 25)
		{
			while (width < 80)
			{
				file >> txt[width][height];
				width++;
			}
			width = 0;
			height++;
		}
		file.close();
	}

	/*if (g_sChar.Key != 0)
	{
	g_sChar.Key--;
	txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] = ' ';
	}*/

	if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'W')//up
	{
		return 1;
	}

	if (txt[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'W') //left
	{
		return 1;
	}

	if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'W')//down
	{
		return 1;
	}

	if (txt[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'W')//right
	{
		return 1;
	}

	if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'P')
	{
		return 2;
	}

	if (txt[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'P')
	{
		return 2;
	}

	if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'P')
	{
		return 2;
	}

	if (txt[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'P')
	{
		return 2;
	}

	if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'D')
	{
		return 3;
	}

	if (txt[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'D')
	{
		return 3;
	}

	if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'D')
	{
		return 3;
	}

	if (txt[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'D')
	{
		return 3;
	}

	if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'T')
	{
		return 4;
	}

	if (txt[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'T')
	{
		return 4;
	}

	if (txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'T')
	{
		return 4;
	}

	if (txt[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'T')
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