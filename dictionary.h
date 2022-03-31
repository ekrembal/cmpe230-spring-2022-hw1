#ifndef _dictionary_h
#define _dictionary_h
#include<string.h>
// 1 ---> MATRIX       2 ----> VECTOR       3 ----> SCALAR
struct dictNode {
    char name[256];
    int type;
    int dim1;
    int dim2;
    struct Node* next;
};

typedef struct Dictionary{
    struct dictNode* start;
    struct dictNode* end;
    int size;
}Dictionary;

void add(struct Dictionary* dictionary, char *name, int type){
    struct dictNode* newNode = (struct dictNode*)malloc(sizeof(struct dictNode));

    if(dictionary->start==NULL){
        dictionary->start=newNode;

    }
    strcpy(newNode->name,name);
    newNode->type = type;
    if(dictionary->size!=0){
        dictionary->end->next = newNode;
    }
    dictionary->end= newNode;
    dictionary->size++;
}

int query(struct Dictionary* dictionary,char *name){
    struct dictNode* temp = dictionary->start;
    
    while(1){
        if(strcmp(temp->name,name)==0){
            return temp->type;
        }
        if(temp->next == NULL){
            break;
        }
        temp=temp->next;
    }
    return -1;
    
}

int isEmpty(struct Dictionary* dictonary){
    return dictonary->size == 0;
}

struct Dictionary* createDictionary(){
    struct Dictionary* dictionary = (struct Dictionary*)malloc(sizeof(struct Dictionary));
    dictionary->start = NULL;
    dictionary->end = NULL;
    dictionary->size = 0;
    return dictionary;
}




#endif