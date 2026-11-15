#include "luhn.h"

bool LuhnValid(const char input[]){
    int sum = 0;
    int counter = 15;

    while(counter >= 0){
        if (counter%2 == 0){ // If my index is even, say 14, double that number 
            int doublenumber = (input[counter] - '0') *2;
            if (doublenumber > 9){ // if that doubled number is greater than 9, subtract 9.
                doublenumber -= 9;
                sum += doublenumber; // add to the sum
            }
            else{
                sum += doublenumber;  // add to the sum
            }
        }
        else{
            sum += (input[counter] - '0'); // if its an odd index, just add it to the sum.
        }
        counter--; // reduce the counter.
    }
    if (sum%10 == 0){ // The sum modulo must return zero in order to be true. 
        return true;
    }
    else{
        return false;
}
}
