#include "game_of_life.h"
#include <stdio.h>

using namespace std;

game_of_life::game_of_life()
{

	int i = 0;
	srand(time(nullptr));

	while (i < 200)
	{
		int c = random_value(COLS);
		int r = random_value(ROWS);
		if (!cell_taken(r, c))
		{
			_generation[r][c] = true;
			i++;
		}
	}
}

void game_of_life::next_generation()
{
	int res = 0;

	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLS; j++)
		{
			int cell = count_neighbours(i, j);
			if (cell < 2 || cell > 3)
			{
				_next_generation[i][j] = false;
	
			}
			else if (cell >= 2 && cell_taken(i, j))
			{
				_next_generation[i][j] = true;
			}
			else if (cell == 3 && !cell_taken(i, j))
			{
				_next_generation[i][j] = true;
			}
			
				
		}
	}

	for (size_t i = 0; i < ROWS; i++)
	{

		for (size_t j = 0; j < COLS; j++)
		{
			_generation[i][j] = _next_generation[i][j];
			_next_generation[i][j] = false;
		}
	}


}

void game_of_life::draw()
{
	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLS; j++)
		{
			if (cell_taken(i, j))
			{
				cout << "*";
			}
			else
			{
				cout << "-";
			}
		}
		cout << endl;
	}

}

int game_of_life::random_value(int max)
{
	return rand() % (max + 1);
}

bool game_of_life::cell_taken(int i, int j)
{
	return _generation[i][j];
}

int game_of_life::count_neighbours(int i, int j)
{
	int res = 0;
	for (int k = -1; k <= 1; k++)
	{
		for (int l = -1; l <= 1 ; l++)
		{
			int r = i + k;
			int c = j + l;

			if ( r < ROWS && r > -1 && c < COLS && c > -1)
			{
				if (( r != 0 || c != 0) && cell_taken(r, c))
				{
					res +=1;
				}
			}

		}
	}

	return res;
}


