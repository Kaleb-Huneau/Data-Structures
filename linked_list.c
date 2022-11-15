//
// Created by Kaleb Huneau on 2021-12-08.
//This program defines a node and implements functions to build linked lists from scratch
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node{//this is what a node will look like in the linked list
    int data;
    struct node *next;
}node;

//initialize the head of the list
node *start = NULL;

int init_list(int data);
int insert_beginning(int data);
int insert_end(int data);
void print_list();
int find_and_replace(int target, int new);

int main(){
    //pointers for start and end of a list
    init_list(2);
    insert_beginning(1);
    insert_end(5);
    find_and_replace(1, 0);

    print_list(start);
    return 0;
}
int insert_end(int data){
    node *new = malloc(sizeof(node));
    if(new != NULL){
        //find the end of the list
        node *temp;//temp pointer that will iterate through the list
        temp = start;
        while((temp->next) != NULL){//go until temp points to
            temp = temp->next;
        }
        new->data = data;
        new->next = NULL;
        temp->next = new;
        free(temp);
    }
    return 0;
}

int init_list(int data){//given a pointer to a node, and the value for the node, initialize a new list
    node *new = malloc(sizeof(node));
    if(new != NULL){//if memory was allocated properly
        new->next = NULL;
        new->data = data;
        start = new;
        return 1;//success
    }
    return 0;
    //fail (did not get memory)
}

int insert_beginning(int data){//insert a node into the end of the list
    node *new = malloc(sizeof(node));
    if(new != NULL){
        new->next = NULL;
        new->data = data;
        new->next = start;//point to what used to be the first node and now is the second node
        start = new;
        return 1;//success
    }
    return 0;//fail
}

void print_list(){
    node *temp;
    temp = start;
    printf("Printing list:");
    while(temp != NULL){//go until the last element in the list
        printf(" %d,", temp->data);
        temp = temp->next;
    }
}

int find_and_replace(int target, int new){
    node *temp = start;
    while(temp != NULL){//go through list and find the target
        if(temp->data == target){
            temp->data = new;//set the target to desired value
            return 1;//this makes it only replace the first target found
        }
        temp = temp->next;
    }
    return 0;//target not in list
}

