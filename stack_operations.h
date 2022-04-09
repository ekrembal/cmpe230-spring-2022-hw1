#ifndef _stack_operations_h
#define _stack_operations_h

#include <stdio.h>
#include <string.h>
#include "enums.h"




typedef struct Variable {
    char *name;
    int feature;
    // int variable_type;
    int dim1,dim2;
}Variable;

typedef struct StackNode{
    struct Variable* data;
    struct StackNode* prev;
}StackNode;

typedef struct ListNode{
    struct Variable* data;
    struct ListNode* next;
} ListNode;

typedef struct Stack {
    struct StackNode* top;
    int size;
} Stack;

typedef struct List {
    ListNode* start;
    ListNode* end;
    int size;
} List;
List globalList;


void push(struct Stack* stack, struct Variable* data){
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->prev = stack->top;
    stack->top = newNode;
    stack->size++;

    // stack->top->next = newNode;
    // stack->top = newNode;
    // stack->size++;
    return;
    // newNode->next = stack->top;
    // stack->top = newNode;
    // printf("push %s\n", data->name);
    // struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));
    // // newNode->name = data.name;
    // // strcpy(newNode->name, data.name);
    // // newNode->feature = data.feature;
    // // newNode->variable_type = data.variable_type;
    // newNode->dim1 = data.dim1;
    // newNode->dim2 = data.dim2;
    // newNode->next = NULL;
    // stack->top->next = newNode;
    // // stack->top = newNode;
    // // stack->size++;
    // printf("push %s\n", data->name);
}
struct Variable* top(struct Stack* stack){
    return stack->top->data;
}
void pop(struct Stack* stack){
    struct StackNode* temp = stack->top;
    stack->top = stack->top->prev;
    // stack->top = stack->top->next;
    free(temp);
    stack->size--;
}
int isEmpty(struct Stack* stack){
    return stack->size == 0;
}
struct Stack* createStack(){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    printf("B\n");
    stack->top = NULL;
    printf("C\n");
    stack->size = 0;
    printf("D\n");
    return stack;
}
int sizeOfStack(struct Stack* stack){
    return stack->size;
}
int sizeOfList(struct List* list){
    return list->size;
}

struct List* createList(){
    struct List* list = (struct List*)malloc(sizeof(struct List));
    list->start = NULL;
    list->end = NULL;
    list->size = 0;
    return list;
}

void addToList( struct List* list , struct Variable* var ){
    // printf("Adding this var: %s %d\n",var->name, var->feature);
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = var;
    newNode->next = NULL;
    if(list->size == 0){
        list->start = newNode;
        list->end = newNode;
        list->size = 1;
    }
    else{
        list->end->next = newNode;
        list->end = newNode;
        list->size++;
    }
    return;
    // if(list->size==0){
    //     list->start = &var;
    //     list->end = &var;
    //     list->size++;
    // }
    // else{
    //     list->end->next = &var;
    //     list->end = &var;
    //     list->size++;
    // }
}   


void addOperationToList(const char *name){
    Variable* newVar = (Variable*)malloc(sizeof(Variable));
    newVar->name = (char*)malloc(sizeof(char)*(strlen(name)+1));
    strcpy(newVar->name,name);
    newVar->feature = OP;
    newVar->dim1 = -1;
    newVar->dim2 = -1;
    addToList(&globalList, newVar);
}


void addNumberToList(const char *name){
    Variable* newVar = (Variable*)malloc(sizeof(Variable));
    newVar->name = (char*)malloc(sizeof(char)*(strlen(name)+1));
    strcpy(newVar->name,name);
    newVar->feature = NUM;
    newVar->dim1 = 1;
    newVar->dim2 = 1;
    addToList(&globalList, newVar);
}
void addIdentifierToList(const char *name){
    Variable* newVar = (Variable*)malloc(sizeof(Variable));
    newVar->name = (char*)malloc(sizeof(char)*(strlen(name)+1));
    strcpy(newVar->name,name);
    newVar->feature = SCA;
    newVar->dim1 = 4;
    newVar->dim2 = 4;
    addToList(&globalList, newVar);
}

char *randString() {
    int length = 15;
    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";        
    char *randomString = NULL;

    if (length) {
        randomString = malloc(sizeof(char) * (length +1));

        if (randomString) {            
            for (int n = 0;n < length;n++) {            
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[n] = charset[key];
            }

            randomString[length] = '\0';
        }
    }
    return randomString;
}

void raiseError(){
    printf("Error Occured\n");
    exit(0);
}

Variable* generateScalarFromNumber(Variable *var){
    if(var->feature != NUM){
        raiseError();
    }
    Variable *newVar = (Variable*)malloc(sizeof(Variable));
    newVar->name = randString();
    newVar->feature = SCA;
    newVar->dim1 = 1;
    newVar->dim2 = 1;
    printf("Var %s = generateScalarFromNumber(%s);\n", newVar->name, var->name);
    return newVar;
}

Variable* processVars(Variable* a, Variable* b, const char *op){
    char *rndstr = randString();
    struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));
    newNode->name=rndstr;
    // newNode->feature= VARIABLE;
    if(a->feature == NUM){
        a = generateScalarFromNumber(a);
    }
    if(b->feature == NUM){
        b = generateScalarFromNumber(b);
    }
    // if( (a.feature == NUM && b.feature == VARIABLE ) || (a.feature == VARIABLE && b.feature == NUM ) || a.feature == NUM && b.feature == NUM){
    //     newNode->variable_type=3;
    // }                
    // else if(a.variable_type == b.variable_type){
    //     newNode->variable_type=a.variable_type;
    //     if(a.variable_type == 1 && a.dim1 == b. dim1  && a.dim2 == b. dim2){
    //         newNode->dim1 = a.dim1;
    //         newNode->dim1 = b.dim2;
    //     }
    //     if(a.variable_type == 2 && a.dim1 == b.dim1 ){
    //         newNode->dim1 = a.dim1;
    //     }
    // }
    // else{
    //     printf("ERROR");
    // }
    printf("Variable %s = %s( %s , %s );\n",  rndstr,  op, a->name , b->name  );
    return newNode;
}

Variable* processTr(Variable *a){
    char *rndstr = randString();
    struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));
    newNode->name=rndstr;
    newNode->feature= MAT;
    if(a->feature == NUM){
        a = generateScalarFromNumber(a);
    }
    printf("Variable %s = transpose( %s );\n",  rndstr,  a->name  );
    return newNode;
}

Variable* processChoose(Variable *a,Variable *b,Variable *c,Variable *d){
    char *rndstr = randString();
    struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));
    newNode->name=rndstr;
    newNode->feature= SCA;
    if(a->feature == NUM){
        a = generateScalarFromNumber(a);
    }
    if(b->feature == NUM){
        b = generateScalarFromNumber(b);
    }
    if(c->feature == NUM){
        c = generateScalarFromNumber(c);
    }
    if(d->feature == NUM){
        d = generateScalarFromNumber(d);
    }
    printf("Variable %s = choose( %s, %s, %s, %s );\n",  rndstr,  a->name, b->name, c->name, d->name  );
    return newNode;
}

Variable* processSqrt(Variable *a){
    char *rndstr = randString();
    struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));
    newNode->name=rndstr;
    newNode->feature= MAT;
    if(a->feature == NUM){
        a = generateScalarFromNumber(a);
    }
    printf("Variable %s = sqrt( %s );\n",  rndstr,  a->name  );
    return newNode;
}


//TODO: NORMALLY RETURNS STRUCT VARIABLE BUT FOR NOW IT WILL BE VOID
Variable* evaluateList( struct List* list){
    printf("EVALUATIONA GIRDI\n");
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    printf("A\n");
    stack->top = NULL;
    printf("B\n");
    //stack->size = 0;
    printf("STACK OLUSTURDU list size = %d\n",list->size);

    for(struct ListNode* ind = list->start; ind != NULL; ind=ind->next){
        Variable* var = ind->data;
    // for(int i = 0; i < 3; i++){

        
        // printf("%s %d\n",var->name, var->feature);
        

        if(var->feature == NUM){
            // printf("NUM in the list\n");
            push(stack, var);
        }
        if(var->feature == MAT || var->feature == VEC || var->feature == SCA){
            // printf("VARIABLE in the list\n");
            push(stack, var);
        }
        if(var->feature == OP){
            // printf("OP in the list\n");
            if(strcmp(var->name , "+")==0){
                Variable* a = top(stack);
                pop(stack);
                Variable* b = top(stack);
                pop(stack);
                Variable* c = processVars(a,b, "addition");
                push(stack, c);

            }
            if(strcmp(var->name , "-")==0){
                Variable* a = top(stack);
                pop(stack);
                Variable* b = top(stack);
                pop(stack);
                Variable* c = processVars(b, a, "substraction");
                push(stack, c);
            }   
            if(strcmp(var->name , "*")==0){
                Variable* a = top(stack);
                pop(stack);
                Variable* b = top(stack);
                pop(stack);
                Variable* c = processVars(a,b, "multiplication");
                push(stack, c);
            }
            if(strcmp(var->name , "tr")==0){  
                Variable* a = top(stack);
                pop(stack);
                Variable* c = processTr(a);
                push(stack, c);
            }
            if(strcmp(var->name , "choose")==0){
                Variable* a = top(stack);
                pop(stack);
                Variable* b = top(stack);
                pop(stack);
                Variable* c = top(stack);
                pop(stack);
                Variable* d = top(stack);
                pop(stack);
                Variable* result = processChoose(a,b,c,d);
                push(stack, result);
            }
            if(strcmp(var->name , "sqrt")==0){
                Variable* a = top(stack);
                pop(stack);
                Variable* result = processSqrt(a);
                push(stack, result);
            }

        }
        
    }
    if(stack->size != 1){
        raiseError();
    }
    Variable* topp = top(stack);
    pop(stack);
    return topp;
    // printf("last stack size: %d\n", stack->size);

}

/*

choose(i,6,sqrt(x*y-5),choose(4,1, tr ( i ) , 0 )) + choose (4, 1, tr ( x*9 ) , 0 )


choose CHOOSE
( LEFT_PARENTHESIS
i IDENTIFIER
, COMMA
6 NUM
, COMMA
sqrt SQRT
( LEFT_PARENTHESIS
x IDENTIFIER
* MULTIPLICATION
y IDENTIFIER
- SUBTRACTION
5 NUM
) RIGHT_PARENTHESIS
, COMMA
choose CHOOSE
( LEFT_PARENTHESIS
4 NUM
, COMMA
1 NUM
, COMMA
tr TR
( LEFT_PARENTHESIS
i IDENTIFIER
) RIGHT_PARENTHESIS
, COMMA
0 NUM
) RIGHT_PARENTHESIS
) RIGHT_PARENTHESIS
+ ADDITION
choose CHOOSE
( LEFT_PARENTHESIS
4 NUM
, COMMA
1 NUM
, COMMA
tr TR
( LEFT_PARENTHESIS
x IDENTIFIER
* MULTIPLICATION
9 NUM
) RIGHT_PARENTHESIS
, COMMA
0 NUM
) RIGHT_PARENTHESIS
i 6 x y * 5 - 4 1 i tr 0 Choose Choose 4 1 x 9 * tr 0 Choose +


*/






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