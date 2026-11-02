#include <iostream>
using namespace std;



int main(){
    //Input
    char user_input[17]; //We make the size 17 because of the null character at the end.
    int counter = 0; // This counts the amount of digits within the userinput. 
                     //A credit card has 16 digits, 

           
    do{ // The purpose of this whole segment is to check whether or not the user inputted something that is actually 16 in length.
    cout << "Please enter a 16-digit number.\n"; 
    cin >> user_input; 
    counter = 0; // Reset the counter to zero before checking the number.
    while(user_input[counter] != '\0'){
        counter++; // Increase the count by one for every non null character
    }

    if (counter != 16){
        cout << "Input is not 16 digits. Please try again.\n";
    }
    }
    while(counter != 16);
}

    
