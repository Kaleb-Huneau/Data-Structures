//
// Created by Kaleb Huneau on 2021-12-08.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node{//define a linked list node
    int data;       //this is where you store the data in a node
    struct node *next;   //pointer to the next node in the stack
}node;

//initialize the head and tail of the stack to be NULL
node *head = NULL;
node *tail = NULL;

void init_stack(int data){//initialize a stack with some integer for the data
    //allocate memory
    node *new = malloc(sizeof(node));

    if(new != NULL){//if the memory has properly been allocated
        new->data = data;
        new->next = NULL;
        //point the head and tail to the new node;
        head = new;
        tail = new;
    }else{
        free(new);
    }
}

void insert(int data){
    //allocate memory;
    node *new = malloc(sizeof(node));
    if(new != NULL){//if memory wqs allocated properly
        new->data = data;
        new->next = head;    //point to the next node in the stack
        head = new;          //point the head to the top node
    }else{//if memory not allocated properly, then free up what we used
        free(new);
    }
}

int pop(int *num){//take the top element of the stack off the pile and return fail(0) or success(1)
    if(head == tail){// if they point to the same item then do the delete the only node protocol
        node *temp = head;
        *num = temp->data;
        head = NULL;
        tail = NULL;
        free(temp);
        return 1;
    }else if(head->next == NULL){//if there is no element in the list;
        printf("There are no elements to pop\n");
        return 0;
    }else{//here do a pop routine for a stack with more than one element
        node *temp = head;
        *num = temp->data;
        head = head->next;
        free(temp);
        return 1;
    }
}

int top(int *num){
    *num = head->data;
    printf("The top of the stack is %d", *num);
}

int main(){
    int data[10] = {1,2,3,4,5,6,7,8,9};
    init_stack(0);
    int num;

    //read the data array into the stack:
    for(int i = 0; i < 9; i++){
        insert(data[i]);
        printf("Added %d to stack\n", data[i]);
    }
    //empty and print the stack
    for(int i = 0; i < 10; i++){
        pop(&num);
        printf("%d", num);
    }

    return 0;
}
