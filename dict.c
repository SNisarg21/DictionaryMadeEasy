#include<stdio.h>
#include<stdlib.h>
#include"dict.h"
#include<string.h>
#define wordSize 20
#define meanSize 30

int convertCharToInt(char p){
    int j;
    if(65 <= p && p <= 90){
        j = p - 'A';
        return j;
    }
    j = p - 'a';
    return j;
}

node1* createDict(){
    node1* dict = (node1*)malloc(sizeof(node1));
    if(dict == NULL){
        return 0;
    }
    dict -> alphabets = (node1**)malloc(sizeof(node1*)*26);
    dict -> endOfWord = 0;
    dict -> meaning = '\0';
    for(int i=0; i < size; i++){
        dict -> alphabets[i] = NULL;
        // initialize alphabets pointing to NULL
    }
    return dict;
}

//insertion of word with meaning in created trie
void insertWord(node1** dict, char* word, char* mean){
    int len = strlen(word);
    // will give the word length to be inserted
    int i, j;
    node1* q = *dict;
    for(i = 0; i < len; i++){
        j = convertCharToInt(word[i]);
        if(j == -65 || j == -87){
            // -87 is for end of text character
            break;
        }
        else if(j < 0){
            printf("Wrong Letter Inserted!!");
        }
        else if(q -> alphabets[j] != NULL){
            q = q -> alphabets[j];
        }
        else{
            q -> alphabets[j] = createDict();
            q = q -> alphabets[j];
        }
    }
    int t = strlen(mean);
    // len of meaning required to allocate mem for meaning pointer
     q->meaning = malloc(sizeof(char)*(t+1));
    strncpy(q->meaning,mean,t);
    q->meaning[t] = '\0';
    q -> endOfWord = 1;
    return;
}

// Outputs the meaning of given word
char* display(node1* dict, char *word){
    int len = strlen(word);
    node1* q = dict;
    char* str = (char*)malloc(sizeof(str)*len);
    // used if word is not spelled correctly
    int j;
    for(int i = 0;i < len; i++){
        j = convertCharToInt(word[i]);
        if(j<0){
            // Wrong word is inputted
            if(j == - 87) break;
            else{
                printf("No such data, %s is wrongly inserted",word);
                return NULL;
            }
        }
        else if(q -> alphabets[j] != NULL){
            q = q -> alphabets[j];
            str[i] = word[i];
        }
        else if(q->alphabets[j] == NULL){           
            //if spelling is wrong then it will correct and gives relevant output
            printf("Data not Present!!\nRecheck Spelling\nRelevant outputs are : \n");
            showString(q,dict,str);
            return NULL;
        }
    }
    if(q!=NULL && q->endOfWord == 1){
        return q->meaning;
    }
    //for prefix string
    else{
        printf("\nEntered Word is not Present\nThe Relevant Output are : ");
        showString(q,dict,str);
    }
    return NULL;
}

// To check whether word is present
int search(node1* dict, char* str){
    for(int i = 0; i < strlen(str); i++){
        int j = convertCharToInt(str[i]);
        if(j == -65) break;
        if(dict->alphabets[j] == NULL) return 0;
        dict = dict->alphabets[j];
    }
    if(dict->endOfWord == 1 && dict!=NULL){
        return 1;
    }
    return 0;
}

// To check if prefix
int checkPrefix(node1* dict, char* str){
    for(int i = 0; i < strlen(str); i++){
        int j = convertCharToInt(str[i]);
        if(dict->alphabets[j] == NULL) return 0;
        dict = dict->alphabets[j];
    }
    return 1;
}

//destroys whole node with all children or simply unload dictionary
int destroyDict(node1** dict){
    if(*dict == NULL){
        printf("\nWarning!! Attempting to delete Dictionary.");
        return 0;
    }
    for(int i = 0;i<26;i++){
        if((*dict)->alphabets[i]!=NULL){
            destroyDict(&((*dict)->alphabets[i]));
            free((*dict)->alphabets[i]);
            if((*dict)->endOfWord == 1){
                free((*dict)->meaning);
            }
        }
    }
    free(*dict);
    *dict = NULL;
    return 1;
}

//To add word in dictionary File
void addWord(){
    char word[wordSize];
    printf("Enter the word to add : ");
    scanf("%s",word);
    printf("Enter the Meaning : ");
    fflush(stdin);
    char mean[meanSize];
    gets(mean);
    FILE* file = fopen("dict.txt","a");
    FILE* file1 = fopen("mean.txt","a");
    if(file != NULL){
        fprintf(file,"%s\n",word);
    }
    if(file1 !=NULL){
        fprintf(file1,"%s\n",mean);
    }
    fclose(file1);
    fclose(file);
    return;
}

node1* loadDict(){
    char word[20];
    char mean[100];
    FILE *fp = fopen("dict.txt","r");       //dict.txt contains words
    FILE *m = fopen("mean.txt","r");        
    //mean.txt contains respective meaning

    node1* dict = createDict();
    if(fp == NULL || m == NULL){
        return NULL;
    }
    while(fgets(word,20,fp) != NULL && fgets(mean,100,m) != NULL){    
        //till eof
        insertWord(&dict,word,mean);
        count++;                                        
        //counter of loaded word
    }
    fclose(m);
    fclose(fp);

    return dict;
}

void autoFill(node1* q,char* str){
    int j;
    node1 *p = NULL;
    p = q;
    int len = strlen(str);
    for(int i = 0; i < len;i++){                        
        //loop till strlen
        j = convertCharToInt(str[i]);
        p = p->alphabets[j];
    }
    showString(p,q,str);
    //this will find all the words with the prefix str present in dict
    return;
}

char* showString(node1* p,node1* q,char* str){
    if(p == NULL)
        return NULL;
    if(p->endOfWord == 1){
        printf("%s : ", str);
        printf("%s",display(q, str));                 
        //if endofword then print the word and meaning
        printf("\n");
        return NULL;
    }
    for(int i =0; i<26; i++){                         
        //loop for every alphabet.
        if(p->alphabets[i] !=NULL){
            showString(p->alphabets[i], q, appendString(str, i));
        }
    }
    return NULL;
}

char* appendString(char* str, int index){               
    // Appends letter to the string
    int i = 0;
    char* q = malloc(sizeof(char)*strlen(str)+2);
    while(str[i]!='\0'){
        q[i] = str[i];
        i++;
    }
    char c = index+'a';
    q[i++] = c;
    q[i] = '\0';
    return q;
}

// Check whether any child is present or not
int checkAlphabet(node1* p){
    for(int i = 0; i < 26; i++){
        if(p->alphabets[i] != NULL)
            return 1;
    }
    return 0;
}

//Deletion of Specific Word in Dictionary.
int delete(node1** p, char* str){
    if(*p == NULL){
        return 0;
    }
    if(*str){
        int i = convertCharToInt(*str);
        // if Dict not pointing to NULL and alphabet is present => if word is present and end of word is 0
        if((*p!=NULL) && (*p)->alphabets[i] != NULL && delete(&((*p)->alphabets[i]),str+1) && (*p)->endOfWord == 0){
                if(!checkAlphabet(*p)){
                    free(*p);
                    *p = NULL;
                    return 1;
                }
                return 0;
           }
    }
    if(*str == '\0' && (*p)->endOfWord){
        if(!checkAlphabet(*p)){
            free((*p)->meaning);
            free(*p);
            *p = NULL;
            return 1;
        }
        else{
            (*p)->endOfWord = 0;
            free((*p)->meaning);
            return 0;
        }
    }
    return 0;
}
