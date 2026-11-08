#include <iostream>
#include "2048_helper.h"
#include <fstream>
using namespace std;

int main()
{
	int size = 5;
	int board[5][5] = {
		{0, 4, 2, 4, 0},
		{0, 0, 0, 0, 0},
		{2, 0, 2, 0, 2},
		{0, 0, 2, 0, 0},
		{2, 2, 2, 2, 2},
	};
	//while getch == x loop for up down left right

	cout << "Initial Board : [5x5] :" << endl;
	print_board(board);

	char choice = 'u';	//initialized
    while (choice != 'e')
{
    cout << "Please enter choice:{u,d,l,r,s,o,e}" << endl;
    cout << "u = UP, d = DOWN, l = LEFT, r = RIGHT" << endl;
    cout << "s = SAVE, o = LOAD, e = EXIT" << endl;

    cout << "Choice: ";
    cin >> choice;

    if (choice == 'u')
    {
        move_up(board, size);
        insert_random(board, size);
    }
    else if (choice == 'd')
    {
        move_down(board, size);
        insert_random(board, size);
    }
    else if (choice == 'l')
    {
        move_left(board, size);
        insert_random(board, size);
    }
    else if (choice == 'r')
    {
        move_right(board, size);
        insert_random(board, size);
    }
    else if (choice == 's')
    {
        save_board(board);
    }
    else if (choice == 'o')
    {
        load_board(board);
    }
    else if (choice == 'e')
    {
        cout << "Exiting game!" << endl;
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    if (choice != 'e')
    {
        print_board(board);
    }
}

return 0;
}
