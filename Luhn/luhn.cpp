#include "includes/luhn.h"

bool LuhnValid(const char input[]){
    int sum = 0;
    /*Check segment goes into this entire block
    -To do: 
    Given input: 0000000000000018
    Convert the characters from the array back into strings. (There is a nice trick for this)
    Starting from the right of the array, (ignoring the null character, so, 8 at index 15)
    Keep that number the same. 
    Double every second digit from the right
    (So in this case, index 14, which is 1) 
    Double that number, add it to the sum
    Then look at index 12 (repeat)
    Then look at index 10,  (repeat) etc.
    

    When done, sum all of the digits doubled and the checked number (which is 8)

    Modulo it, if it returns with no remainder it should return true. (Step already done for you)
    If it has a remainder, return false.
    */

    if (sum%10 == 0){
        return true;
    }
    else{
        return false;
    }
}
