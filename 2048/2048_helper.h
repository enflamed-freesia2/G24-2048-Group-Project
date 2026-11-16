#include <iostream>
#include <random>
#include <iomanip>
#include <fstream>

using namespace std;

//Directional functions
void move_left(int board[][5], int numrows = 5)
{
    for (int i = 0; i < numrows; i++)
    {
        int temp[5] = {0};
        int index = 0;
        //this just shifts any numbers that are non-zero to the LEFT
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] != 0)
            {
                temp[index++] = board[i][j];
                
            }
           
        }
        //takes all non-zeros to the front and fill every remaining spot with a zero
        while(index < 5) {temp[index++] = 0;} 
        //merge function here
        for(int n =0; n < 4; n++){
            //the if statement checks if the current temporary variable in the array is exactly the same as the next one
            if(board[i][n] != 0 && board[i][n]==board[i][n+1]){
                board[i][n]*= 2;
                board[i][n + 1] =0;
                n++;
            }
            
        }
        //shift it again because the previous function before this created new empty space
        index = 0;
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] != 0)
            {
                temp[index] = board[i][j];
                index++;
            }
           
        }
         while(index < 5) {temp[index++] = 0;}
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
         while(index >= 0) {temp[index--] = 0;} 

        for(int n =4; n > 0; n--){
            //the if statement checks if the current temporary variable in the array is exactly the same as the next one
            if(board[i][n] != 0 && board[i][n]==board[i][n-1]){
                board[i][n]*= 2;
                board[i][n - 1] =0;
                n--;
            }
        }

        index = 4;

        for (int j = 4; j >= 0; j--)
        {
            if (board[i][j] != 0)
            {
                temp[index] = board[i][j];
                index--;
            }
        }
         while(index >= 0) {temp[index--] = 0;} 

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
        while(index < 5) {temp[index++]=0;}

        //merger
        for(int n =0; n < 4; n++){
            //the if statement checks if the current temporary variable in the array is exactly the same as the next one
            if(board[n][j] != 0 && board[n][j]==board[n+1][j]){
                board[n][j]*= 2;
                board[n+1][j] =0;
                n++;
            }
        }

        index=0;
        //shift again to make up for the spaces
        for (int i = 0; i < numrows; i++)
        {
            if (board[i][j] != 0)
            {
                temp[index] = board[i][j];
                index++;
            }
        }
        while(index < 5) {temp[index++]=0;}


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
        while(index >= 0) {temp[index--] = 0;}

        // merger
        for(int n = 4; n > 0; n--){
            //the if statement checks if the current temporary variable in the array is exactly the same as the next one
            if(board[n][j] != 0 && board[n][j]==board[n-1][j]){
                board[n][j]*= 2;
                board[n-1][j] =0;
                n--;
            }
        }

        index = 4;

        for (int i = numrows - 1; i >= 0; i--)
        {
            if (board[i][j] != 0)
            {
                temp[index] = board[i][j];
                index--;
            }
        }
        while(index >= 0) {temp[index--] = 0;}

        for (int i = 0; i < numrows; i++)
        {
            board[i][j] = temp[i];
        }
    }
}
//=======================================================================

//Save and load function

//validate if the board values are even validated numbers on the board
bool power_of_two(int n){
    if(n<2) return false;
    while(n % 2 ==0){
        n /= 2;

    }
    return n == 1;
}

void save_board(int board[][5], int score, int moves){
    ofstream outFile;
    outFile.open("savegame.txt");

    if(outFile.fail()){
        cout<<"error could not open up a file for saving"<<endl;
        return;
    }

    //writing out file header
    outFile<<"CS211_2048_V1"<<endl;

    //writing counters
    outFile<<score<<" "<<moves<<endl;

    //writing the 5x5 board
    for(int n = 0; n < 5; n++){
        for(int r = 0; r < 5; r++){
            outFile<<board[n][r];
            if(r<4){
                outFile<<" ";
            }
        }
        outFile<<endl;
    }
    outFile.close();
    cout<<"game saved successfully"<<endl;
}

bool load_board(int board[][5], int& score, int& moves){
    ifstream infile("savegame.txt");
        if(!infile){
            cout<<"error: sample_save.txt cannot be found or opened"<<endl;
            return false;
        }
    

    char marker[20];
    infile>>marker;
    
    //string comparison
    const char expected[] = "CS211_2048_V1";
    int i =0;
    while(expected[i] != '\0' && marker[i] != '\0'){
        if(expected[i] != marker[i]){
            infile.close();
            cout<<"Error: invalid file marker"<<endl;
            return false;
        }
        i++;
    }
    if(expected[i] != marker[i]){ //when lengths don't match
        infile.close();
        cout<<"Error: invalid file marker (length)"<<endl;
        return false;
    }
    // when the resultant score and moves don't match up
    int temp_score;
    int temp_moves;
    if(!(infile>>temp_score>>temp_moves) || temp_score < 0 || temp_moves < 0 ){
        infile.close();
        cout<<"Error: invalid counters in the save file"<<endl;
        return false;
    }
    int temp_board[5][5];
    for(int r = 0; r < 5; r++){
        for(int v = 0; v<5; v++){
            if(!(infile>>temp_board[r][v])){
                infile.close();
                cout << "Error: Missing board data." << endl;
                return false;
            }
            if (temp_board[r][v] != 0 && !power_of_two(temp_board[r][v])) {
                infile.close();
                cout << "Error: Invalid tile value on board." << endl;
                return false;
            }
        }
    }
    //if extra whitespace is found, deny
    char extra;
    
    if(infile>>extra){
    infile.close();
    cout<<"Error: extra data found in the file"<<endl;
    return false;
}

    //when it does validate by passing all the markers
    score = temp_score;
    moves = temp_moves;
    for(int r =0; r < 5; r++){
        for(int n = 0; n < 5; n++){
            board[r][n] = temp_board[r][n];
        }
    }

    infile.close();
    cout<<"game loaded successfully"<<endl;
    return true;
}
//============================================================================
//win/lose function
bool winning(int board[][5]){
    for(int n = 0; n < 5; n++){
        for(int r = 0; r < 5; r++){
            if(board[n][r]>=2048){
                return true;
            }
        }
    }
}
//to check for possible moves, we need to check vertically and horizontally
//to fully confirm whether are not any tiles are uncombinable
bool losing(int board[][5]){
    //empty cell check
    for(int n =0; n < 5; n++){
        for(int r =0; r<5; r++){
            if(board[n][r]==0){
                return false;
            }
        }
    }
    //vertical check
    for(int n =0; n < 4; n++){
        for(int r =0; r<5; r++){
            if(board[n][r]==board[n+1][r]){
                return false;
            }
        }
    }
    //horizontal check
    for(int n =0; n < 5; n++){
        for(int r =0; r<4; r++){
            if(board[n][r]==board[n][r+1]){
                return false;
            }
        }
    }
    return true;
}
//============================================================================
//print & random
void print_board(int board[][5], int numrows = 5)
{
	cout << endl << "\t-----------------------------------------" << endl;

	for (int r = 0; r < numrows; r++)
	{
		for (int v = 0; v < 5; v++)
		{
			if(board[r][v] > 0)
				cout << "\t|" << right << setw(6) << setfill(' ') << board[r][v];
			else
				cout << "\t|" << right << setw(6) << setfill(' ') << " ";

			//cout << board[r][v] << "\t|\t";
		}
		cout << "\t|" << endl;
		cout << "\t-----------------------------------------" << endl;
	}

	cout << "\t" << endl << endl;
}


void insert_random(int board[][5], int numrows = 5)
{
	int r, v;
	//count empty
	int empty_count = 0;
	for (int r = 0; r < numrows; r++)
	{
		for (int v = 0; v < 5; v++)
		{
			if (board[r][v] == 0)
				empty_count++;
		}
	}

	if (empty_count > 0)
	{
		while (true)
		{
			//generate random location r, v
			r = rand() % numrows;
			v = rand() % numrows;
			//check if empty
			if (board[r][v] == 0)
			{
				//add number randomly {2,4}
				board[r][v] = 2 * (1 + (rand() % 2));
				break;
			}
		}

	}
}

