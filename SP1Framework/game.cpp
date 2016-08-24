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

double  g_dElapsedTime;
double  g_dDeltaTime;
bool    g_abKeyPressed[K_COUNT];
extern int Activity_feed;
int checkobj;
bool setText = false;
ifstream read;

// Game specific variables here
SGameChar   g_sChar;
EGAMESTATES g_eGameState = S_SPLASHSCREEN;
double  g_dBounceTime; // this is to prevent key bouncing, so we won't trigger keypresses more than once
int g_level = 1;
int map = 0;

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
	g_sChar.m_bActive = true;
	// sets the width, height and the font name to use in the console
	g_Console.setConsoleFont(0, 16, L"Consolas");
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
	g_abKeyPressed[K_INTERACT] = isKeyPressed(0x5A);
	g_abKeyPressed[K_SPACE] = isKeyPressed(VK_SPACE);
	g_abKeyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
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
	case S_GAME: gameplay(); // gameplay logic when we are in the game
		break;
	case S_LEVEL2: gameplay();
		break;
	case S_LEVEL21: gameplay();
		break;
	case S_LEVEL22: gameplay();
		break;
	case S_LEVEL3: gameplay();
		break;
	case S_LEVEL31: gameplay();
		break;
	case S_LEVEL32: gameplay();
		break;
	case S_LEVEL33: gameplay();
		break;
	case S_LEVEL34: gameplay();
		break;
	case S_LEVEL35: gameplay();
		break;
	case S_LEVEL36: gameplay();
		break;
	case S_LEVEL37: gameplay();
		break;
	case S_LEVEL38: gameplay();
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
	case S_GAME: renderGame();
		break;
	case S_LEVEL2: renderGame();
		break;
	case S_LEVEL21:renderGame();
		break;
	case S_LEVEL22:renderGame();
		break;
	case S_LEVEL3:renderGame();
		break;
	case S_LEVEL31: renderGame();
		break;
	case S_LEVEL32: renderGame();
		break;
	case S_LEVEL33: renderGame();
		break;
	case S_LEVEL34: renderGame();
		break;
	case S_LEVEL35: renderGame();
		break;
	case S_LEVEL36: renderGame();
		break;
	case S_LEVEL37: renderGame();
		break;
	case S_LEVEL38: renderGame();
		break;
	}
	renderFramerate();  // renders debug information, frame rate, elapsed time, etc
	renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
}

void splashScreenWait()    // waits for time to pass in splash screen
{
	if (g_dElapsedTime > 3.0)
	{// wait for 3 seconds to switch to game mode, else do nothing
		g_eGameState = S_GAME;
	}
}

void gameplay()            // gameplay logic
{
	processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
	moveCharacter();    // moves the character, collision detection, physics, etc
	transition();					// sound can be played here too.
	if (map == 0)
	{
		g_Console.clearBuffer();
		g_eGameState = S_GAME;
		g_level = 1;
	}
	if (map == 1)
	{
		g_Console.clearBuffer();
		g_eGameState = S_LEVEL2;
		g_level = 2;
	}
	if (map == 2)
	{
		g_Console.clearBuffer();
		g_eGameState = S_LEVEL21;
		g_level = 3;
	}
	if (map == 3)
	{
		g_Console.clearBuffer();
		g_eGameState = S_LEVEL22;
		g_level = 4;
	}
	if (map == 4)
	{
		g_Console.clearBuffer();
		g_eGameState = S_LEVEL3;
		g_level = 5;
	}
	if (map == 5)
	{
		g_Console.clearBuffer();
		g_eGameState = S_LEVEL31;
		g_level = 6;
	}
	if (map == 6)
	{
		g_Console.clearBuffer();
		g_eGameState = S_LEVEL32;
		g_level = 7;
	}
	if (map == 7)
	{
		g_Console.clearBuffer();
		g_eGameState = S_LEVEL33;
		g_level = 8;
	}
	if (map == 8)
	{
		g_Console.clearBuffer();
		g_eGameState = S_LEVEL34;
		g_level = 9;
	}
	if (map == 9)
	{
		g_Console.clearBuffer();
		g_eGameState = S_LEVEL35;
		g_level = 10;
	}
	if (map == 10)
	{
		g_Console.clearBuffer();
		g_eGameState = S_LEVEL36;
		g_level = 11;
	}
	if (map == 11)
	{
		g_Console.clearBuffer();
		g_eGameState = S_LEVEL37;
		g_level = 12;
	}
	if (map == 12)
	{
		g_Console.clearBuffer();
		g_eGameState = S_LEVEL38;
		g_level = 13;
	}
}

void moveCharacter()
{
	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
		return;

	// Updating the location of the character based on the key press
	// providing a beep sound whenver we shift the character
	if (g_abKeyPressed[K_UP] && g_sChar.m_cLocation.Y > 0 && collision(g_level))
	{
		//Beep(1440, 30);
		g_sChar.m_cLocation.Y--;
		bSomethingHappened = true;
	}
	if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X > 0 && collision(g_level))
	{
		//Beep(1440, 30);
		g_sChar.m_cLocation.X--;
		bSomethingHappened = true;
	}
	if (g_abKeyPressed[K_DOWN] && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1 && collision(g_level))
	{
		//Beep(1440, 30);
		g_sChar.m_cLocation.Y++;
		bSomethingHappened = true;
	}
	if (g_abKeyPressed[K_RIGHT] && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1 && collision(g_level))
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
	if (g_abKeyPressed[K_INTERACT])
	{
		setText = false;
		checkobj = checkinteract(g_level);
		Interact(checkobj);

	}
}

void clearScreen()
{
	// Clears the buffer with this colour attribute
	g_Console.clearBuffer(0x1F);
}

void renderSplashScreen()  // renders the splash screen
{
	COORD c = g_Console.getConsoleSize();
	c.Y /= 3;
	c.X = c.X / 2 - 9;
	g_Console.writeToBuffer(c, "A game in 3 seconds", 0x03);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Press <Space> to change character colour", 0x09);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 9;
	g_Console.writeToBuffer(c, "Press 'Esc' to quit", 0x09);
}

void renderGame()
{
	renderMap();        // renders the map to the buffer first
	renderFeed();
	renderCharacter();// renders the character into the buffer
}



void renderMap()
{
	// Set up sample colours, and output shadings
	const WORD colors[] =
	{
		0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
		0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	};

	char** grid = new char*[100];
	grid = Mapping(grid, g_level);
	print_map(grid);

	/*COORD c;
	for (int i = 0; i < 12; ++i)
	{
	c.X = 5 * i;
	c.Y = i + 1;
	colour(colors[i]);
	g_Console.writeToBuffer(c, " °±²Û", colors[i]);
	}*/
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

	if (Activity_feed == 2 && !setText)
	{
		text = "It's a pillar.";
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

void renderCharacter()
{
	// Draw the location of the character
	WORD charColor = 0x0C;
	if (g_sChar.m_bActive)
	{
		charColor = 0x0A;
	}
	g_Console.writeToBuffer(g_sChar.m_cLocation, (char)1, charColor);
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
	g_Console.writeToBuffer(c, ss.str(), 0x59);
}
void renderToScreen()
{
	// Writes the buffer to the console, hence you will see what you have written
	g_Console.flushBufferToConsole();
}