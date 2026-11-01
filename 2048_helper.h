#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

void move_left(int board[][5], int numrows = 5)
{
    for (int i = 0; i < numrows; i++)
    {
        int temp[5] = {0};
        int index = 0;

        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] != 0)
            {
                temp[index] = board[i][j];
                index++;
            }
        }

        for (int j = 0; j < 5; j++)
        {
            board[i][j] = temp[j];
        }
    }
}

void move_right(int board[][5], int numrows = 5)
{
    for (int i = 0; i < numrows; i++)
    {
        int temp[5] = {0};
        int index = 4;

        for (int j = 4; j >= 0; j--)
        {
            if (board[i][j] != 0)
            {
                temp[index] = board[i][j];
                index--;
            }
        }

        for (int j = 0; j < 5; j++)
        {
            board[i][j] = temp[j];
        }
    }
}

void move_up(int board[][5], int numrows = 5)
{
    for (int j = 0; j < 5; j++)
    {
        int temp[5] = {0};
        int index = 0;

        for (int i = 0; i < numrows; i++)
        {
            if (board[i][j] != 0)
            {
                temp[index] = board[i][j];
                index++;
            }
        }

        for (int i = 0; i < numrows; i++)
        {
            board[i][j] = temp[i];
        }
    }
}

void move_down(int board[][5], int numrows = 5)
{
    for (int j = 0; j < 5; j++)
    {
        int temp[5] = {0};
        int index = 4;

        for (int i = numrows - 1; i >= 0; i--)
        {
            if (board[i][j] != 0)
            {
                temp[index] = board[i][j];
                index--;
            }
        }

        for (int i = 0; i < numrows; i++)
        {
            board[i][j] = temp[i];
        }
    }
}


void print_board(int board[][5], int numrows = 5)
{
	cout << endl << "\t-----------------------------------------" << endl;

	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if(board[r][c] > 0)
				cout << "\t|" << right << setw(6) << setfill(' ') << board[r][c];
			else
				cout << "\t|" << right << setw(6) << setfill(' ') << " ";

			//cout << board[r][c] << "\t|\t";
		}
		cout << "\t|" << endl;
		cout << "\t-----------------------------------------" << endl;
	}

	cout << "\t" << endl << endl;
}


void insert_random(int board[][5], int numrows = 5)
{
	int r, c;
	//count empty
	int empty_count = 0;
	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if (board[r][c] == 0)
				empty_count++;
		}
	}

	if (empty_count > 0)
	{
		while (true)
		{
			//generate random location r, c
			r = rand() % numrows;
			c = rand() % numrows;
			//check if empty
			if (board[r][c] == 0)
			{
				//add number randomly {2,4}
				board[r][c] = 2 * (1 + (rand() % 2));
				break;
			}
		}

	}
}

