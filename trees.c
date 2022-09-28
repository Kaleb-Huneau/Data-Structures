//
// Created by Kaleb Huneau on 2021-12-09.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;//store integer data in the tree node
    struct node *leftchild = NULL;
    struct node *rightchild = NULL;
}node;

typedef struct tree{//just holds a pointer to the first node in a tree
    node *root;
}tree;

bool add_node(int data){//create a new node and put it in a tree

}


tree* init_tree(){//initialize a tree and return a pointer to the tree
    tree *new = malloc(sizeof(tree));
    new->root = malloc(sizeof(node));

}
