#ifndef _dictionary_h
#define _dictionary_h
#include <string.h>
#include "stack_operations.h"
// 1 ---> MATRIX       2 ----> VECTOR       3 ----> SCALAR
// typedef struct Variable {
//     char *name;
//     int feature;
//     int dim1,dim2;
// }Variable;
#define MAX_VARS 100005
Variable *dictVars[MAX_VARS];
int dictSize = 0;

void addToDict(Variable *v){
    dictVars[dictSize++] = v;
}

void addNewScalar(char *name){
    // Malloc new Variable
    Variable *v = (Variable *)malloc(sizeof(Variable));
    // Copy name to new Variable
    v->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(v->name, name);
    // Set feature to SCALAR
    v->feature = SCA;
    // Set dim1 and dim2 to 1
    v->dim1 = 1;
    v->dim2 = 1;
    addToDict(v);
}

void addNewVector(char *name, int dim){
    // Malloc new Variable
    Variable *v = (Variable *)malloc(sizeof(Variable));
    // Copy name to new Variable
    v->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(v->name, name);
    // Set feature to VECTOR
    v->feature = VEC;
    // Set dim1 and dim2 to dim
    v->dim1 = dim;
    v->dim2 = 1;
    addToDict(v);
}

void addNewMatrix(char *name, int dim1, int dim2){
    // Malloc new Variable
    Variable *v = (Variable *)malloc(sizeof(Variable));
    // Copy name to new Variable
    v->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(v->name, name);
    // Set feature to MATRIX
    v->feature = MAT;
    // Set dim1 and dim2 to dim1 and dim2
    v->dim1 = dim1;
    v->dim2 = dim2;
    addToDict(v);
}

Variable *getFromDict(char *name){
    for(int i = 0; i < dictSize; i++){
        if(strcmp(dictVars[i]->name, name) == 0){
            return dictVars[i];
        }
    }
    return NULL;
}

bool isExist(char *name){
    for(int i = 0; i < dictSize; i++){
        if(strcmp(dictVars[i]->name, name) == 0){
            return true;
        }
    }
    return false;
}

void checkExistence(Variable *a){
    if(!isExist(a->name)){
        printf("Variable %s does not exist.\n", a->name);
        exit(1);
    }
}

// struct dictNode {
//     char name[256];
//     int type;
//     int dim1;
//     int dim2;
//     struct Node* next;
// };

// typedef struct Dictionary{
//     struct dictNode* start;
//     struct dictNode* end;
//     int size;
// }Dictionary;

// void add(struct Dictionary* dictionary, char *name, int type){
//     struct dictNode* newNode = (struct dictNode*)malloc(sizeof(struct dictNode));

//     if(dictionary->start==NULL){
//         dictionary->start=newNode;

//     }
//     strcpy(newNode->name,name);
//     newNode->type = type;
//     if(dictionary->size!=0){
//         dictionary->end->next = newNode;
//     }
//     dictionary->end= newNode;
//     dictionary->size++;
// }

// int query(struct Dictionary* dictionary,char *name){
//     struct dictNode* temp = dictionary->start;
    
//     while(1){
//         if(strcmp(temp->name,name)==0){
//             return temp->type;
//         }
//         if(temp->next == NULL){
//             break;
//         }
//         temp=temp->next;
//     }
//     return -1;
    
// }

// int isEmpty(struct Dictionary* dictonary){
//     return dictonary->size == 0;
// }

// struct Dictionary* createDictionary(){
//     struct Dictionary* dictionary = (struct Dictionary*)malloc(sizeof(struct Dictionary));
//     dictionary->start = NULL;
//     dictionary->end = NULL;
//     dictionary->size = 0;
//     return dictionary;
// }




#endif