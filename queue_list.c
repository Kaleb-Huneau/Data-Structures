//
// Created by Kaleb Huneau on 2021-12-08.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head = NULL;
node *tail = NULL;


int init_queue(int data){//initialize the queue
    node *new = malloc(sizeof(node));
    if(new != NULL){//successful allocation
        new->data = data;
        new->next = NULL;
        head = new;
        tail = new;
        return 1;//success
    }
    return 0;//fail
}

int add_queue(int data){
    node *new = malloc(sizeof(node));
    //assuming memory was allocated:
    new->data = data;
    new->next = NULL;
    if(tail != NULL){//if there is at least one node that exists
        tail->next = new;
    }
    tail = new;
    if(head == NULL){//if the head is null then point it to the new element
        head = new;
    }
    return 0;//fail
}

int remove_queue(int *pi){//remove an item from the queue and return the its value

    node *temp = head; //temp pointer to the node at the start of the line


    if(head != NULL){//check to make sure the list isnt already empty
        *pi = head->data;
        head = head->next;
        printf("Removed: %d\n", temp->data);
        free(temp);
        return 1;//success
    }
    if(head == NULL){//there was only one element in the list so make tail null too
        tail = NULL;
    }
    printf("List already empty.\n");
    return 0;//list is already empty
}

int print_queue(){//loop through positions and print the queue head to tail
    node *temp = head;//start at the head of the queue
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 1;
}




int main(){
    int val;//use this pointer when removing from the queue

    //testing the functions
    init_queue(0);
    add_queue(1);
    add_queue(2);
    add_queue(3);


    remove_queue(&val);
    print_queue();
    return 0;
}
