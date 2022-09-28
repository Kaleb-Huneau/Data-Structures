//
// Created by Kaleb Huneau on 2021-12-08.
//
#include <stdio.h>

int gcd(int x, int y){//this function takes two integers and returns the GCD of both (recursion)
    if(y == 0){//if one of the numbers is zero, return zero
        return x;
    }
    else if(x < y){
        return gcd(y,x);
    }else{
        return gcd(y, x % y);
    }
}


int main(){
    //test the gcd here:
    int x = 54;
    int y = 24;
    printf("GCD of x = %d, and y = %d is %d\n", x, y, gcd(x,y));

    return 0;
}
