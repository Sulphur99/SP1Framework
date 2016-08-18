#ifndef _MAPPING_H
#define _MAPPING_H
#include <iostream>
#include <string>
#include <fstream>
#include "game.h"
#include "Framework\console.h"

using namespace std;

char** Mapping(char** arr, int level);
void print_map(char** grid);

#endif // !_MAPPING_H