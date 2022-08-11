#ifndef BOGGLESOLVER_H_INCLUDED // jar file already firun include jhaleli asel tar include naka karu nasel tar kara (mhnjech multiple definition ha )
#define BOGGLESOLVER_H_INCLUDED

#include"array.h"
#include"dict.h"
#include"linkedList.h"

int Row,Col; // size of grid

void findWord(int x, int y, list1 **p, set **arr, node1* copy1, node1* Dict);

int freeBoggle();

int loadBoggle();

int checkValid(int x, int y);

void solveBoggle();

#endif // BOGGLESOLVER_H_INCLUDED