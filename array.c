#include<stdio.h>
#include<stdlib.h>
#include"array.h"

int r, c;

void modifySize(int a, int b){
    r = a;
    c = b;
    return;
}

int position(int b, int a){
    return c*b+a;
}

int createSet(set** h){
    *h = (set*)malloc(sizeof(set));
    if(!(*h)) return 0;
    (*h)->arr = (int*)calloc(r*c, sizeof(int));
    if(!(*h)->arr) return 0;
    return 1;
}

void destroySet(set ** h){
    free((*h)->arr);
    free(*h);
    return;
}

void insertValue(set ** h, int x, int y){
    if((*h)->arr[position(x,y)] == 0){
        (*h)->arr[position(x,y)] = 1;
        return;
    }
}

int find(set* h,int x,int y){   
    return h->arr[position(x,y)];
}

void removeValue(set** h,int x,int y){  
    if((*h)->arr[position(x,y)] == 1){
        (*h)->arr[position(x,y)] = 0;
        return;
    }
    return;
}
