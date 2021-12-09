//
// Created by Kaleb Huneau on 2021-12-09.
//
#include <stdio.h>
#include <stdbool.h>
#define SIZE 100

int queue[SIZE];//queue of integers up to (SIZE) places
int count = 0, head = -1, tail = -1;// keep track of the start, end and size of the queue

bool is_full(){
    return (count == SIZE);
}
bool is_empty(){
    return (count == 0);
}

bool add_queue(int data){//add an item to the queue
    if(is_full()){
        return false;
    }
    //not full
    tail  = ++tail % SIZE; //move end to next position and insert the data here
    queue[tail] = data;
    //if this is the first element, then make point both head and tail to the item
    if(head == -1){
        head = tail;
    }
    count++;//something was added so increase the count
    return true;
}

bool remove_queue(){//no input needed to remove from queue
    //check if its already empty:
    if(is_empty()){
        printf("Queue is already empty\n");
        return false;
    }
    head = ++head % SIZE;//move head to the next position and take mod size to handle wrap around

    //is it now empty?
    if(is_empty()){
        head = -1;
        tail = -1;
    }
    count--;//something was taken out so decrease the count
    return true;
}

void print_queue(){
    //print the queue from front to end;
    int temp = head;//start at the front of queue
    while(temp-1 != tail){//go until temp is tail and when it passes, stop
        printf("%d ", queue[temp]);
        temp ++;
    }
    printf("\n");
}

int main(){
    add_queue(0);
    add_queue(1);
    add_queue(2);
    add_queue(3);

    print_queue();

    remove_queue();
    remove_queue();

    print_queue();
    return 0;
}

