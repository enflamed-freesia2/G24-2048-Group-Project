#include <iostream>
#include "2048_helper.h"
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

	int score =0;
	int moves=0;
	//both of these check if we already gave the user win/lose by tracking it
	bool winannounced = false;
	bool isgameover = false;

	char choice = 'u';	//initialized
	while (choice != 'e')
	{
		

		cout << "Please enter choice:{u,d,l,r,s,o,e} for UP, DOWN, LEFT, RIGHT, Save, Open, Exit: " << endl;
		cout << "Choice: ";
		cin >> choice;

		bool board_changed = false;
		int old_board[5][5];
		for(int i = 0; i < 5; i++){
			for(int n =0; n < 5; n++){
				old_board[i][n]=board[i][n];
			}
		}
		while(!isgameover){
			if (choice == 'u')
				move_up(board, size);
			else if (choice == 'd')
				move_down(board, size);
			else if (choice == 'l')
				move_left(board, size);
			else if (choice == 'r')
				move_right(board, size);
			else if (choice == 'u' || choice == 'd' || choice == 'l' || choice == 'r'){
				cout<<"Game over you lose"<<endl;
				continue;
			}
		}

		if(choice =='s'){
			save_board(board, score, moves);
			continue;
		}
		else if(choice == 'o'){
			if(load_board(board, score,moves)){
				cout<<"game loaded"<<endl;
				print_board(board);
				cout<<"Score: "<<score<<" | Moves: "<<moves<<endl;
			}
			else{
				cout<<"load failed. Game unchanged"<<endl;
			}
			continue;
		}
	//checking for changes within the board
	for(int n = 0;n<5; n++){
		for(int r =0; r < 5; r++){
			if (board[n][r]!=old_board[n][r]){
				board_changed = true;
			}
		}
	}
	//check if board has even changed before adding a random tile to the board
	if(board_changed){
		moves++;
		insert_random(board, size);
	}
	//check if the user won
		if(!winannounced && winning(board)){
			cout << "\n*** Congratulations! You reached 2048! ***" << endl;
			cout << "You may continue playing to beat your high score.\n" << endl;
			winannounced = true; // Only announce it once
		}
	//check if the user lost
		if(!isgameover && losing(board)){
			cout << "\n*** GAME OVER ***" << endl;
			cout << "No more moves are possible." << endl;
			cout << "You may still Save, Load, start a New game, or Exit.\n" << endl;
			isgameover = true; 
		}
	}		

	
		print_board(board);
		return 0;

}
