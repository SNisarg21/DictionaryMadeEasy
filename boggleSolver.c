#include<stdio.h>
#include<stdlib.h>
#include"boggleSolver.h"
#include<string.h>

char** Boggle;


// Load The Boggle
int loadBoggle(){
    int a,b;
    printf("\nEnter Number of rows in grid  --> ");
    scanf("%d",&a);
    printf("\nEnter Number of columns in grid  --> ");
    scanf("%d",&b);
    Row = a;
    Col = b;
    modifySize(a, b);
    Boggle = (char**)malloc(sizeof(char*)*Row);
    if(Boggle == NULL) return 0;
    char c;
    printf("\nYou can enter %d characters\nEnter the character\n", Row*Col);
    for(int i = 0; i < Row; i++){
        Boggle[i] = (char*)malloc(sizeof(char)*Col);
        if(!Boggle[i]) return 0;
        for(int j = 0; j < Col; j++){
            scanf("%c",&c);
            while(c == ' ' || c == '\n'){
                scanf("%c", &c);
            }
            Boggle[i][j] = c;
        }
    }
    for(int j = 0;j < Row;j++){
        for(int i = 0; i<Col; i++){
            printf(" ___ ");
        }
        printf("\n");
        for(int k = 0; k<Col;k++){
            printf("| %c |",Boggle[j][k]);
        }
        printf("\n");
        for(int t = 0;t<Col;t++){
            printf(" ___ ");
        }
        printf("\n");
    }
    char correctness;
    printf("Recheck the corectness of Boggle (Enter Y or y for correct Boggle) -->");
    fflush(stdin);
    scanf("%c", &correctness);
    if(correctness != 'y' && correctness != 'Y'){
        freeBoggle();
        loadBoggle();
    }
    return 1;
}


int checkValid(int x, int y){
    if(x < 0  || y < 0 || x > Row-1 || y > Col-1)
        return 0;
    return 1;
}

void solveBoggle(){
    node1* Dict;
    if(!loadBoggle()){
        printf("\nGrid cannot be loaded due to Space!!");
        return;
    }
    Dict = createDict();
    Dict = loadDict();
    list1 *path;
    initLL(&path);
    set *arr;
    createSet(&arr);
    node1 *copy;
    copy = createDict();
    for(int i = 0; i < Row; i++){
        for(int j = 0; j < Col; j++){
            findWord(i, j, &path, &arr, copy, Dict);
        }
    }
    destroyDict(&copy);
    destroyDict(&Dict);
    count = 0;
    destroyLL(&path);
    destroySet(&arr);
    freeBoggle();
    return;
}

// Solving the valid Boggle

void findWord(int x, int y, list1** p, set** arr, node1* copy, node1* Dict){
    if(!checkValid(x, y)) return;
    if(find(*arr, x, y)) return;
    insertNode(p, Boggle[x][y]);
    char* word = getString(*p);
    if(search(Dict, word) && !search(copy, word)){
        printf("%s : ", word);
        printf("%s", display(Dict, word));
        insertWord(&copy, word, display(Dict, word));
    }
    if(checkPrefix(Dict, word)){
        insertValue(arr, x ,y);
        for(int i = x - 1; i <= x + 1; i++){
            for(int j = y - 1; j <= y + 1; j++){
                if(i == x && j == y){}
                else{
                    findWord(i, j, p, arr, copy, Dict);
                }
            }
        }
        removeValue(arr, x, y);
    }
    removeNode(p);
}

// Function to deallocate memory by grid
int freeBoggle(){
    for(int i = 0; i < Row; i++){
        free(Boggle[i]);
        Boggle[i] = NULL;
    }
    free(Boggle);
    Boggle = NULL;
    return 1;
}
