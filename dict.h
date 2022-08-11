#ifndef DICT_H_INCLUDED
#define DICT_H_INCLUDED
#define size 26

// Structure of Trie Data Structure
typedef struct node{
    struct node** alphabets; // Array node Pointer of Size 26
    int endOfWord; // To know where the word Ends => 1 : End of word
    char* meaning; // Stores meaning of the word
}node1;

int count; // keeps the count of the words loaded in the dictionary

int convertCharToInt(char p); // Rewuired to store in Array

node1* createDict(); // Creation of node in Dictionary

void insertWord(node1** dict, char* word, char* mean); // Insertion of Word along with meaning

char* display(node1* dict, char* word); // For Displaying Meaning

int destroyDict(node1** dict); // Destroys the entire Dictionary

char* showString(node1* p, node1* dict, char* str); 

int checkPrefix(node1* dict, char* str); // if there is any word with entered prefix

int search(node1* dict, char* str); // Word is there or not

node1* loadDict(); // loading dictionary

void addWord(); // Adding word into the text file

char* appendString(char* str, int index); // Supporting function for autocomplete

void autoFill(node1* dict, char* str); 

int delete(node1** p, char* str);

int checkAlphabet(node1* p);

#endif // DICT_H_INCLUDED