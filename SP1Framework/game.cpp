// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Transition.h"
#include "Interact.h"
#include "Inventory.h"
#include "LoadMap.h"
#include "Chest.h"

double  g_dElapsedTime;
double  g_dDeltaTime;
bool    g_abKeyPressed[K_COUNT];
extern int Activity_feed;
int checkobj;
bool setText = false;
ifstream read;

// Game specific variables here
SGameChar   g_sChar;
SGameSelector g_sSelector;
EGAMESTATES g_eGameState = S_SPLASHSCREEN;
double  g_dBounceTime; // this is to prevent key bouncing, so we won't trigger keypresses more than once
int map = 0;
bool load = false;
char grid[80][26];
int memory;
int key = 1;
char keypiece = 48;
int check = 0;
int value = 0;
int access4 = 1;

//Torchlight
int MinX;
int MaxX;
int MinY;
int MaxY;

// Console object
Console g_Console(80, 25, "SP1 Framework");

//--------------------------------------------------------------
// Purpose  : Initialisation function
//            Initialize variables, allocate memory, load data from file, etc. 
//            This is called once before entering into your main loop
// Input    : void
// Output   : void
//--------------------------------------------------------------
void init(void)
{
	// Set precision for floating point output
	g_dElapsedTime = 0.0;
	g_dBounceTime = 0.0;

	// sets the initial state for the game
	g_eGameState = S_SPLASHSCREEN;

	g_sChar.m_cLocation.X = g_Console.getConsoleSize().X / 2;
	g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y / 2;
	g_sSelector.c_cLocation.X = 32;
	g_sSelector.c_cLocation.Y = 11;

	g_sChar.m_bActive = true;
	// sets the width, height and the font name to use in the console
	g_Console.setConsoleFont(0, 16, L"Raster");
}

//--------------------------------------------------------------
// Purpose  : Reset before exiting the program
//            Do your clean up of memory here
//            This is called once just before the game exits
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void shutdown(void)
{
	// Reset to white text on black background
	colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

	g_Console.clearBuffer();
}

//--------------------------------------------------------------
// Purpose  : Getting all the key press states
//            This function checks if any key had been pressed since the last time we checked
//            If a key is pressed, the value for that particular key will be true
//
//            Add more keys to the enum in game.h if you need to detect more keys
//            To get other VK key defines, right click on the VK define (e.g. VK_UP) and choose "Go To Definition" 
//            For Alphanumeric keys, the values are their ascii values (uppercase).
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void getInput(void)
{
	g_abKeyPressed[K_UP] = isKeyPressed(VK_UP);
	g_abKeyPressed[K_DOWN] = isKeyPressed(VK_DOWN);
	g_abKeyPressed[K_LEFT] = isKeyPressed(VK_LEFT);
	g_abKeyPressed[K_RIGHT] = isKeyPressed(VK_RIGHT);
	g_abKeyPressed[K_Z] = isKeyPressed(0x5A);//Z
	g_abKeyPressed[K_SPACE] = isKeyPressed(VK_SPACE);
	g_abKeyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
	g_abKeyPressed[K_I] = isKeyPressed(0x49);//I
	g_abKeyPressed[K_J] = isKeyPressed(0x4A);//J
	g_abKeyPressed[K_K] = isKeyPressed(0x4B);//K
	g_abKeyPressed[K_R] = isKeyPressed(0x52);//R
	g_abKeyPressed[K_ENTER] = isKeyPressed(0x0D);//Enter
}

//--------------------------------------------------------------
// Purpose  : Update function
//            This is the update function
//            double dt - This is the amount of time in seconds since the previous call was made
//
//            Game logic should be done here.
//            Such as collision checks, determining the position of your game characters, status updates, etc
//            If there are any calls to write to the console here, then you are doing it wrong.
//
//            If your game has multiple states, you should determine the current state, and call the relevant function here.
//
// Input    : dt = deltatime
// Output   : void
//--------------------------------------------------------------
void update(double dt)
{
	// get the delta time
	g_dElapsedTime += dt;
	g_dDeltaTime = dt;

	switch (g_eGameState)
	{
	 case S_SPLASHSCREEN: splashScreenWait(); // game logic for the splash screen
		break;
	 case S_MAINMENU: menu();
		 break;
	 case S_GAME: gameplay(); // gameplay logic when we are in the game
		break;
	 case S_ENDGAME: Endgame();
		 break;
	 case S_INVENTORY: processUserInput(); //key updates here -SY
		 break;
	}
}
//--------------------------------------------------------------
// Purpose  : Render function is to update the console screen
//            At this point, you should know exactly what to draw onto the screen.
//            Just draw it!
//            To get an idea of the values for colours, look at console.h and the URL listed there
// Input    : void
// Output   : void
//--------------------------------------------------------------
void render()
{
	clearScreen();      // clears the current screen and draw from scratch 
	switch (g_eGameState)
	{
	 case S_SPLASHSCREEN: renderSplashScreen();
		break;
	 case S_MAINMENU: rendermenu();
		 break;
	 case S_GAME: renderGame();
		break;
	 case S_ENDGAME: renderEndgame();
		 break;
	 case S_INVENTORY: loadInv();
		 renderInv();
		 break;
	}
	renderFramerate();  // renders debug information, frame rate, elapsed time, etc
	renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
}

void splashScreenWait()    // waits for time to pass in splash screen
{
	if (g_dElapsedTime > 3.0)
	{// wait for 3 seconds to switch to game mode, else do nothing
		load = true;
		g_eGameState = S_MAINMENU;
	}
}

void gameplay()            // gameplay logic
{
	processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
	moveCharacter();    // moves the character, collision detection, physics, etc
	transition();
	if (map == 8)
	{
		puzzle3_3();
	}
	if (map == 12)
	{
		puzzle3_7();
	}
	if (map == 9)
	{
		puzzle3_4_1();
		puzzle3_4_2();
		puzzle3_4_3();
	}
	// sound can be played here too.
}

void moveCharacter()
{
	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
		return;

	// Updating the location of the character based on the key press
	// providing a beep sound whenver we shift the character
	if (g_abKeyPressed[K_UP] && g_sChar.m_cLocation.Y > 0 && collision(map))
	{
		//Beep(1440, 30);
		g_sChar.m_cLocation.Y--;
		bSomethingHappened = true;
	}
	if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X > 0 && collision(map))
	{
		//Beep(1440, 30);
		g_sChar.m_cLocation.X--;
		bSomethingHappened = true;
	}
	if (g_abKeyPressed[K_DOWN] && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1 && collision(map))
	{
		//Beep(1440, 30);
		g_sChar.m_cLocation.Y++;
		bSomethingHappened = true;
	}
	if (g_abKeyPressed[K_RIGHT] && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1 && collision(map))
	{
		//Beep(1440, 30);
		g_sChar.m_cLocation.X++;
		bSomethingHappened = true;
	}
	if (g_abKeyPressed[K_SPACE])
	{
		g_sChar.m_bActive = !g_sChar.m_bActive;
		bSomethingHappened = true;
	}
	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
	}
}
void processUserInput()
{
	// quits the game if player hits the escape key
	if (g_abKeyPressed[K_ESCAPE])
		g_bQuitGame = true;
	if (g_abKeyPressed[K_Z])
	{
		setText = false;
		checkobj = checkinteract(map);
		Interact(checkobj);
	}
	if (g_abKeyPressed[K_R])
	{
		reset();
	}
	switch (g_eGameState)
	{
		case S_GAME:
			if (g_abKeyPressed[K_I])
			{
				g_eGameState = S_INVENTORY;
			}
			break;
		case S_INVENTORY:
			if (g_abKeyPressed[K_J])
			{
				g_eGameState = S_GAME;
			}
			break;
	}
}

void clearScreen()
{
	// Clears the buffer with this colour attribute
	g_Console.clearBuffer();
}

void renderSplashScreen()  // renders the splash screen
{
	COORD c = g_Console.getConsoleSize();
	c.Y = 5;
	c.X = g_Console.getConsoleSize().X / 2 - 33;

	g_Console.writeToBuffer(c, "___________                                                        ", 0x01);
	c.Y += 1;
	g_Console.writeToBuffer(c, "\\__    ___/_______   ____  _____     ______ __ __ _______   ____   ", 0x02);
	c.Y += 1;
	g_Console.writeToBuffer(c, "  |    |   \\_  __ \\_/ __ \\ \\__  \\   /  ___/|  |  \\\\_  __ \\_/ __ \\  ", 0x03);
	c.Y += 1;
	g_Console.writeToBuffer(c, "  |    |    |  | \\/\\  ___/  / __ \\_ \\___ \\ |  |  / |  | \\/\\  ___/  ", 0x04);
	c.Y += 1;
	g_Console.writeToBuffer(c, "  |____|    |__|    \\___  >(____  //____  >|____/  |__|    \\___  > ", 0x05);
	c.Y += 1;
	g_Console.writeToBuffer(c, "                        \\/      \\/      \\/                     \\/  ", 0x06);
	c.Y += 1;
	g_Console.writeToBuffer(c, "  ___ ___                   __                                     ", 0x07);
	c.Y += 1;
	g_Console.writeToBuffer(c, " /   |   \\  __ __   ____  _/  |_   ____  _______                   ", 0x08);
	c.Y += 1;
	g_Console.writeToBuffer(c, "/    ~    \\|  |  \\ /    \\ \\   __\\_/ __ \\ \\_  __ \\                  ", 0x09);
	c.Y += 1;
	g_Console.writeToBuffer(c, "\\    Y    /|  |  /|   |  \\ |  |  \\  ___/  |  | \\/                  ", 0xA);
	c.Y += 1;
	g_Console.writeToBuffer(c, " \\___|_  / |____/ |___|  / |__|   \\___  > |__|                     ", 0xB);
	c.Y += 1;
	g_Console.writeToBuffer(c, "       \\/              \\/             \\/                           ", 0xC);

}

void renderGame()
{
	renderMap();// renders the map to the buffer first
	if (map != 14)
	{
		renderCharacter(); // renders the character into the buffer
	}
	renderChests();
	renderFeed();
}



void renderMap()
{
	// Set up sample colours, and output shadings
	const WORD colors[] =
	{
		0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
		0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	};

	COORD c;
	Mapping(map);

	char txt[80][5];
	for (int y = 0; y < 5; y++)
	{
		c.Y = y + 20;
		for (int x = 0; x < 80; x++)
		{
			if(y == 0)
			{
				txt[x][y] = (char)178;
			}
			else
			{
				txt[x][y] = (char)176;
			}
			c.X = x;
			g_Console.writeToBuffer(c, txt[x][y]);
		}
	}

	MinX = g_sChar.m_cLocation.X - 4;
	MaxX = g_sChar.m_cLocation.X + 5;
	MinY = g_sChar.m_cLocation.Y - 2;
	MaxY = g_sChar.m_cLocation.Y + 3;

	if (map != 14)
	{	
		WORD mapColor = 0x89;
		if (g_sChar.m_cLocation.X <= 4)
		{
			MinX = 0;
		}
		if (g_sChar.m_cLocation.Y <= 2)
		{
			MinY = 0;
		}
		if (g_sChar.m_cLocation.X >= 78)
		{
			MaxX = 80;
		}
		if (g_sChar.m_cLocation.Y >= 18)
		{
			MaxY = 20;
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
				g_Console.writeToBuffer(c, grid[x][y], mapColor);
			}
		}
	}
	else
	{
		for (int y = 0; y < 26; y++)
		{
			c.Y = y;
			for (int x = 0; x < 80; x++)
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
	/*COORD c;
	for (int i = 0; i < 12; ++i)
	{
	c.X = 5 * i;
	c.Y = i + 1;
	colour(colors[i]);
	g_Console.writeToBuffer(c, " °±²Û", colors[i]);
	}*/
}

void renderCharacter()
{
	// Draw the location of the character
	WORD charColor = 0x0C;
	if (g_sChar.m_bActive)
	{
		charColor = 0x0A;
	}
	g_Console.writeToBuffer(g_sChar.m_cLocation, (char)1, charColor);//
}

void renderFramerate()
{
	COORD c;
	// displays the framerate
	std::ostringstream ss;
	ss << std::fixed << std::setprecision(3);
	ss << 1.0 / g_dDeltaTime << "fps";
	c.X = g_Console.getConsoleSize().X - 9;
	c.Y = 0;
	g_Console.writeToBuffer(c, ss.str());

	// displays the elapsed time
	ss.str("");
	ss << g_dElapsedTime << "secs";
	c.X = 0;
	c.Y = 0;
	g_Console.writeToBuffer(c, ss.str());
}
void renderToScreen()
{
	// Writes the buffer to the console, hence you will see what you have written
	g_Console.flushBufferToConsole();
}