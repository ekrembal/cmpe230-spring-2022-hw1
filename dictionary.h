#ifndef _dictionary_h
#define _dictionary_h
#include<string.h>

struct Node {
    char name[256];
    int isMatrix;
    int isVector;
    int isScalar;
    int dim1;
    int dim2;
    struct Node* next;
};

struct Dictionary{
    struct Node* start;
    struct Node* end;
    int size;
};

void add(struct Dictionary* dictionary, char *name, int type){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(dictionary->start==NULL){
        dictionary->start=newNode;
    }
    strcpy(newNode->name,name);
    if(type==1){
        newNode->isMatrix=1;
    }
    if(type==2){
        newNode->isVector=1;
    }
    if(type==3){
        newNode->isScalar=1;
    }
    dictionary->end->next = newNode;
    dictionary->end= newNode;
    dictionary->size++;
}

int query(struct Dictionary* dictionary,char *name){
    struct Node* temp = dictionary->start;
    while(temp->next!=NULL){
        if(strcmp(temp->name,name)==0){
            if(temp->isMatrix==1){
                return 1;
            }
            if(temp->isVector==1){
                return 2;
            }
            if(temp->isScalar==1){
                return 3;
            }
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

// Here you can see the stack usage

// struct Stack* temp = createStack();
// push(temp, 5);
// push(temp, 6);
// push(temp, 7);
// printf("%d\n", top(temp));
// printf("%d\n", isEmpty(temp));
// pop(temp);
// printf("%d\n", top(temp));
// printf("%d\n", isEmpty(temp));
// pop(temp);
// printf("%d\n", top(temp));
// printf("%d\n", isEmpty(temp));
// pop(temp);
// printf("%d\n", isEmpty(temp));
// printf("%d\n", top(temp));


#endif