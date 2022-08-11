#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

typedef struct set
{
    int* arr; // Array will store 0 or 1's
}set;

void modifySize(int a, int b);

int position(int x, int y);

int createSet(set** h);

void destroySet(set** h);

int find(set* h, int x, int y);

void insertValue(set ** h, int x, int y);

void removeValue(set** h, int x, int y);

#endif