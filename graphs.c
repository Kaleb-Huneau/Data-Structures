//
// Created by Kaleb Huneau on 2021-12-11.
//
#include <stdio.h>

typedef struct node{
    char vertex;  //vertex label
    int weight;   //holds the weight of an edge
    struct node *next;
}node;

int read_graph(){
    /*
     * This function creates a graph given the path to a text file with verticies and edge information
     */
    //read the vertex information
    FILE *fp = fopen("graph.txt", "r");//open graph file in read mode

    int size;
    fscanf(fp,"%d", &size);    //read the first line into size

    char vertex[size];
    for(int i = 0; i <= size; i++){    //vertex name has length (size)
        //read each character into the vertex array
        fscanf(fp,"%c ", &vertex[i]);
        printf("%c", vertex[i]);
    }
    return 1;
}

int main(){
    read_graph();
    int a = 2;
    int b = 1;
    printf("%d",b/a );
    return 0;
}