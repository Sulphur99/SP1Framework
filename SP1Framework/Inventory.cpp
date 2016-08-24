#include "Inventory.h"

extern bool g_abKeyPressed[K_I];
extern int map;
extern int memory;
extern int key;
extern Console g_Console;
COORD a;
extern double g_dElapsedTime;
extern double g_dBounceTime;

void inventory()
{
	//bool SomethingHappened;

	if (g_abKeyPressed[K_I] && map != 13)
	{
		memory = map;
		map = 13;
		//SomethingHappened = true;

	}
	else if (g_abKeyPressed[K_I] && map == 13)
	{
		map = memory;
	}
	if (key > 0 && map == 13)
	{
		a.X = 1;
		a.Y = 2;
		g_Console.writeToBuffer(a, "Key x1");
	}
	/*if (SomethingHappened)
	{
	g_dBounceTime = g_dElapsedTime + 0.125;
	}*/
}