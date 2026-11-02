#include <iostream>
#include "includes/luhn.h"
using namespace std;



int main(){
    //Input
    char user_input[17]; //We make the size 17 because of the null character at the end.
    int counter = 0; // This counts the amount of digits within the userinput. 
                     //A credit card has 16 digits, 
    bool NoChar = true;
           
    do{ // The purpose of this whole segment is to check whether or not the user inputted something that is actually 16 in length 
        // It also checks if a character was inpu
    cout << "Please enter a 16-digit number.\n"; 
    cin >> user_input; 
    counter = 0; // Reset the counter to zero before checking the input.
    NoChar = true; // Reset the boolean before checking the input.
    while(user_input[counter] != '\0'){
        if (user_input[counter] >= '0' and user_input[counter] <= '9'){
          //Its good, keep continuing, no code needed here 
        }
        else{
            NoChar = false;
        }
        counter++; // Increase the count by one for every non null character
    }

    if (counter != 16 or NoChar == false or !LuhnValid(user_input)){
        cout << "Input is invalid. Please try again.\n";
    }
    }
    while(counter != 16 or NoChar == false or !LuhnValid(user_input));
    // !LuhnValid just says, "if my function, LuhnValid, returns False, I want you to loop it again.
}

    
