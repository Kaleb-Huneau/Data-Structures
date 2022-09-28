//
// Created by Kaleb Huneau on 2021-12-09.
//
#include <stdio.h>
#include <stdbool.h>

int data[20] = {18,8,16,9,3,17,11,4,10,5,19,2,7,6,12,1,13,0,14,15};


int array_size(){
    return (sizeof(data)/sizeof(int));
}
int print_array(){

    for(int i = 0; i < array_size(); i++){
        printf("%d, ", data[i]);
    }
    printf("\n");
}

int swap(int i, int j){
    int temp = data[j];
    data[j] = data[i];
    data[i] = temp;
}

int insertion_sort(){
    int temp_index = 0;
    int i, j;
    for(i = 0; i < array_size(); i++){//loop through the array starting after the first element
        temp_index = i;
        for(j = i+1; j > 0; j--){//loop through the sorted array section in reverse
            print_array();
            //compare
            if(data[j] < data[temp_index]){//swap
                swap(temp_index, j);
                temp_index--;
            }

        }


    }
}


int main(){
    print_array();
    insertion_sort();
    print_array();
    return 0;
}