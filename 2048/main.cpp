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

		//Handle Game Over prevention
		if (isgameover && (choice == 'u' || choice == 'd' || choice == 'l' || choice == 'r')) {
			cout << "Game Over! You cannot make any more moves." << endl;
			continue; // Skips the rest of the loop, asks for input again
		}

		//Snapshot the board to check for changes later
		bool board_changed = false;
		int old_board[5][5];
		for(int i = 0; i < 5; i++){
			for(int n = 0; n < 5; n++){
				old_board[i][n] = board[i][n];
			}
		}

		// Process Movement (Only if game is NOT over)
		if (!isgameover) {
			if (choice == 'u') move_up(board, size);
			else if (choice == 'd') move_down(board, size);
			else if (choice == 'l') move_left(board, size);
			else if (choice == 'r') move_right(board, size);
		}

		// 4. Process Save / Load (These bypass random insertion)
		if(choice == 's'){
			save_board(board, score, moves);
			continue;
		}
		else if(choice == 'o'){
			if(load_board(board, score, moves)){
				cout << "game loaded" << endl;
				print_board(board);
				cout << "Score: " << score << " | Moves: " << moves << endl;
			}
			else{
				cout << "load failed. Game unchanged" << endl;
			}
			continue;
		}
		else if (choice == 'e') {
			break; // Exit the loop cleanly
		}

		// Check if the board actually changed
		for(int n = 0; n < 5; n++){
			for(int r = 0; r < 5; r++){
				if (board[n][r] != old_board[n][r]){
					board_changed = true;
				}
			}
		}

		// Insert random tile and count move ONLY if board changed
		if(board_changed){
			moves++;
			insert_random(board, size);
		}

		// Check for Win
		if(!winannounced && winning(board)){
			cout << "\n*** Congratulations! You reached 2048! ***" << endl;
			cout << "would you like to start a new game (y/n)\n" << endl;
			char restart;
			cin >> restart;

			if(restart=='y'||restart=='Y'){
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {
						board[i][j] = 0;
					}
				}
			//reset counters
				score = 0;
				moves = 0;
				winannounced = false;
				isgameover = false;

				//board comes with two new tiles
				insert_random(board, size);
				insert_random(board, size);
				

				cout << "\nNew game started!" << endl;
				print_board(board);
				cout << "Score: " << score << " | Moves: " << moves << endl;
			}
			winannounced = true; 
		}

		//Check for Loss
		if(!isgameover && losing(board)){
			cout << "\n*** GAME OVER ***" << endl;
			cout << "No more moves are possible." << endl;
			cout << "You may still Save, Load, or Exit.\n" << endl;
			cout <<"or would you like to play another game? (y/n)"<<endl;

			char restart;
			cin >> restart;

			if(restart=='y'||restart=='Y'){
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {
						board[i][j] = 0;
					}
				}
			//reset counters
				score = 0;
				moves = 0;
				winannounced = false;
				isgameover = false;

				//board comes with two new tiles
				insert_random(board, size);
				insert_random(board, size);
				

				cout << "\nNew game started!" << endl;
				print_board(board);
				cout << "Score: " << score << " | Moves: " << moves << endl;
			}
			isgameover = true; 
		}

		print_board(board);
		cout << "Score: " << score << " | Moves: " << moves << endl;
	}

	return 0;
}
