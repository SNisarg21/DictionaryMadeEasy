#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"boggleSolver.h"
#define max_size 20
#include<windows.h>

int main(){
    //HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  //  SetConsoleTextAttribute(h,2);
    node1 *p = NULL;
    int i, choice;
    char ch;
    count = 0;
    do{
        //SetConsoleTextAttribute(h,2);
        printf("\n--------------------------------------------------------");
        printf("\n|                                                        |");
        printf("\n|      1) --> Boggle Solver With Meaning.                |");
        printf("\n|      2) --> Dictionary.                                |");
        printf("\n|      3) --> QUIT.                                      |");
        printf("\n|                                                        |");
        printf("\n--------------------------------------------------------\n");
        printf("\n Enter Choice --> ");
        fflush(stdin); // flush the output buffer of the stream. It returns zero, if successful
        scanf("%d", &choice);
        switch(choice){
        case 1:
            // SetConsoleTextAttribute(h,4);
            printf("\n ||--------Boggle Solver--------||");
            solveBoggle();
            break;
        case 2:
           // SetConsoleTextAttribute(h,3);
            do{

                printf("\n|*|*|*|*|*|*|*|*---Dictionary---|*|*|*|*|*|*|*|*\n");
                printf("\n 1) --> Add Word  --> ");
                printf("\n 2) --> Load Dictionary  --> ");
                printf("\n 3) --> Display Meaning --> ");
                printf("\n 4) --> Destroy Dictionary --> ");
                printf("\n 5) --> Display Whole Dictionary --> ");
                printf("\n 6) --> Number of Words in Dictionary --> ");
                printf("\n 7) --> Delete Word --> ");
                printf("\n 8) --> Quit --> ");
                printf("\n Enter Your Choice : ");
                fflush(stdin);
                scanf("%d",&i);
                char* word = (char*)malloc(max_size*sizeof(char));
            switch(i){
                case 1: addWord();
                    break;
                case 2:p = loadDict();
                    break;
                case 3:printf("\nEnter the word to be searched : ");
                    fflush(stdin);
                    printf("\n%s",display(p,gets(word)));
                    free(word);
                    break;
                case 4:
                    if(destroyDict(&p)){
                        printf("\nData Unloaded!!...!!");
                        count = 0;
                    }
                    break;
                case 5:
                    autoFill(p,"");
                    break;
                case 6:
                    printf("\n%d is count ",count);
                    break;
                case 7:
                    printf("\nEnter the Word to be deleted ");
                    fflush(stdin);

                    if(delete(&p,gets(word))){
                        count--;
                        printf("%s is Successfully Deleted",word);
                    }
                    break;
                case 8:destroyDict(&p);
                        count = 0;
                        break;
                default:
                    printf("\nYou Have Entered Wrong Choice ");
                    break;
                }
                printf("\nPress (y or Y) to clear the screen......... ");
                fflush(stdin);
                scanf("%c",&ch);
                if(ch == 'y' || ch =='Y')
                    system("cls");
            }while(i!=8);
            break;
        case 3:break;
        default:
             printf("\nEntered Choice is incorrect!!...Please Enter the correct choice...");
             break;
        }
        system("pause");
        system("cls");
    }while(choice!=3);
    printf("\nFinished Successfully........Thankyou...");
    return 0;
}
