//
// Created by Kaleb Huneau on 2021-12-08.
//
#include <stdio.h>
#define TEST 7

int factorial_recursion(int x){
    if(x == 1){
        return 1;
    }else{
        return x * factorial_recursion(x-1);
    }
}
int factorial_loop(int x){
    int ans = 1;
    for(int i = x; i > 0; i--){
        ans *= i;
    }
    return ans;
}

int gcd_recursion(int x, int y){
    if(y == 0){//gcd is itself
        return x;
    }else if(x < y){//if one of them is zero, then gcd is zero
        return gcd_recursion(y, x);
    }else{
        return gcd_recursion(y, x % y);
    }
}


int main(){
    printf("Factorial with Recursion: %d\n", factorial_recursion(TEST));
    printf("Factorial with Loop: %d\n", factorial_loop(TEST));
    return 0;
}
