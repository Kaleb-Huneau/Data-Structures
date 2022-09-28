//
// Created by Kaleb Huneau on 2021-12-22.
//
///Heads up that this does not fully work yet. data array should be an input to the other functions(will fix later)

#include <stdio.h>
#define SIZE 10
int data[10] = {9,5,6,4,2,3,1,8,7,0};
int data2[10] = {9,5,6,4,2,3,1,8,7,0};

int find_smallest(int start){//Find and return the index with the smallest value between the start and end of sub_array
    int temp = 0;
    for(int i = start; i < SIZE; i++){
        if(data2[i] < data2[temp]){
            temp = i;
        }
    }
    return temp;
}
int swap(int i, int j){//swap based on index positions
    int temp = data2[j];
    data2[j] = data2[i];
    data2[i] = temp;
}

void recursive_selection(int min, int max){

    //base case
    if(min == max){//if we have gone through the whole array
        return;
    }
    //otherwise, swap the first and the smallest indexes
    swap(min, find_smallest(min));
    //after swap, we must selsort the remainder of the array:
    recursive_selection(min + 1, max);
}

void iterative_selection(int min, int max) {//takes input of min and max index
    int temp_index;
    //start a zero and find smallest
    for(int i = 0; i < SIZE; i++){//loop through the array
        //find the smallest:
        temp_index = find_smallest(i);
        //swap with the ith element
        swap(i, temp_index);
    }
}
int print_array(int which){
    printf("Data");
    if(which == 0){
        for(int i = 0; i < SIZE; i++){
            printf("%d, ",data[i]);
        }
        printf("\n");
    }else{
        for(int i = 0; i < SIZE; i++){
            printf("%d, ",data2[i]);
        }
        printf("\n");
    }

}

int main(){
    print_array(0);
    iterative_selection(0, SIZE);
    print_array(0);

    print_array(1);
    recursive_selection(0, SIZE);
    print_array(1);
    return 0;
}

