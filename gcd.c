//
// Created by Kaleb Huneau on 2021-12-08.
//
#include <stdio.h>

int gcd(int x, int y){
    /*
     * This function takes two integers and returns the greatest common denominator using recursion
     */
    if(y == 0){return x;}             //if y is zero, gcd must be zero
    else if(x < y){return gcd(y,x);}  //recursive call if x < y
    else{return gcd(y, x % y);}    //recursive call with remainder of x/y
}
int main(){
    //Testing the function
    int x = 54;
    int y = 24;
    int result = gcd(x, y);

    printf("GCD of x = %d, and y = %d is %d\n", x, y, result);

    if(result == 6){printf("Gives correct result for 54 and 24")};
    if(result == gcd(y, x)){printf("Confirmed that given order does not matter")};

    return 0;
}
