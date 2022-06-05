#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
#include <array>
using namespace std;

class game_of_life {
private:
	static const unsigned int COLS = 40;
	static const unsigned int ROWS = 20;
	bool _generation[ROWS][COLS] = {false};
	bool _next_generation[ROWS][COLS] = {false};
	int random_value(int max);
	bool cell_taken(int i, int j);

public:
	game_of_life();
	void next_generation();
	void draw();
	int count_neighbours(int i, int j);
};

#endif
