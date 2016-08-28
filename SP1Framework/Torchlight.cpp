#include "Torchlight.h"

extern Console g_Console;
extern char grid[80][26];
extern SGameChar  g_sChar;
extern int a;
extern int b;
extern int MinY;
extern int MaxY;
extern int MinX;
extern int MaxX;

void Torchlight()
{
	MinY = g_sChar.m_cLocation.Y - 2;
	MinX = g_sChar.m_cLocation.X - 5;
	MaxX = 80 - a;
	MaxY = 26 - b;

	COORD c;

	if (g_sChar.m_cLocation.Y <= 2)
	{
		MinY = 0;
	}
	if (g_sChar.m_cLocation.X <= 2)
	{
		MinX = 0;
	}
	if (g_sChar.m_cLocation.Y >= 24)
	{
		MaxY = 26;
	}
	if (g_sChar.m_cLocation.X >= 75)
	{
		MaxX = 80;
	}
	for (int y = MinY; y < MaxY; y++)
	{
		c.Y = y;
		for (int x = MinX; x < MaxX; x++)
		{
			if (grid[x][y] == '-')
			{
				grid[x][y] = (char)176;
			}
			if (grid[x][y] == 'W')
			{
				grid[x][y] = (char)178;
			}
			if (grid[x][y] == '\n')
			{
				grid[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, grid[x][y]);
		}
	}
}