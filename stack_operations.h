#ifndef _stack_operations_h
#define _stack_operations_h

#include <stdio.h>
#include <string.h>

enum type{OPERATION, NUMBER, VARIABLE};


struct Variable {
    char *name;
    enum type feature;
    struct Variable* next;
    int variable_type;
    int dim1,dim2;
}Variable;

typedef struct Stack {
    struct Variable* top;
    int size;
} Stack;

typedef struct List {
    struct Variable* start;
    struct Variable* end;
    int size;
} List;

void push(struct Stack* stack, struct Variable data){
    struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));
    newNode->name = data.name;
    newNode->feature = data.feature;
    newNode->variable_type = data.variable_type;
    newNode->dim1 = data.dim1;
    newNode->dim2 = data.dim2;
    newNode->next = stack->top->next;
    stack->top = newNode;
    stack->size++;
}
struct Variable top(struct Stack* stack){
    return *stack->top;
}
void pop(struct Stack* stack){
    struct Variable* temp = stack->top;
    stack->top = stack->top->next;
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

void addToList( struct List* list , struct Variable var ){
    if(list->size==0){
        list->start = &var;
        list->end = &var;
        list->size++;
    }
    else{
        list->end->next = &var;
        list->end = &var;
        list->size++;
    }
}   

char *randString() {
    int length = 15;
    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";        
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

//TODO: NORMALLY RETURNS STRUCT VARIABLE BUT FOR NOW IT WILL BE VOID
void evaluateList( struct List* list){
    printf("EVALUATIONA GIRDI\n");
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    printf("A\n");
    stack->top = NULL;
    printf("B\n");
    //stack->size = 0;
    printf("STACK OLUSTURDU");
    while(list->size!=0){
        
        printf(" %s",list->start->name);

        if(list->start->feature == NUMBER){
            push(stack, *list->start);
            list->start=list->start->next;
            list->size--;
        }
        if(list->start->feature == VARIABLE){
            push(stack, *list->start);
            list->start=list->start->next;
            list->size--;
        }
        if(list->start->feature == OPERATION){
            if(strcmp(list->start->name , "+")==0){
                struct Variable a = top(stack);
                pop(stack);
                struct Variable b = top(stack);
                pop(stack);
                char *rndstr = randString();
                struct Variable* newNode = (struct Variable*)malloc(sizeof(struct Variable));
                newNode->name=rndstr;
                newNode->feature= VARIABLE;
                if( (a.feature == NUMBER && b.feature == VARIABLE ) || (a.feature == VARIABLE && b.feature == NUMBER ) || a.feature == NUMBER && b.feature == NUMBER){
                    newNode->variable_type=3;
                }                
                else if(a.variable_type == b.variable_type){
                    newNode->variable_type=a.variable_type;
                    if(a.variable_type == 1 && a.dim1 == b. dim1  && a.dim2 == b. dim2){
                        newNode->dim1 = a.dim1;
                        newNode->dim1 = b.dim2;
                    }
                    if(a.variable_type == 2 && a.dim1 == b.dim1 ){
                        newNode->dim1 = a.dim1;
                    }
                }
                else{
                    printf("ERROR");
                }
                printf("Variable %s = addition( %s , %s );\n", rndstr , a.name , b.name  );
            }
            if(strcmp(list->start->name , "-")==0){
                struct Variable a = top(stack);
                pop(stack);
                struct Variable b = top(stack);
                pop(stack);
                char *rndstr = randString();
                //TODO: EXECUTE OPERATION ALSO IN HERE AND ASSIGN rndstr to a variable
                printf("Variable %s = substraction ( %s , %s );\n", rndstr  , a.name , b.name  );
            }   
            if(strcmp(list->start->name , "*")==0){
                struct Variable a = top(stack);
                pop(stack);
                struct Variable b = top(stack);
                pop(stack);
                char *rndstr = randString();
                //TODO: EXECUTE OPERATION ALSO IN HERE AND ASSIGN rndstr to a variable
                printf("Variable %s = multiplication ( %s , %s );\n", rndstr  , a.name , b.name  );
            }
            if(strcmp(list->start->name , "/")==0){
                struct Variable a = top(stack);
                pop(stack);
                struct Variable b = top(stack);
                pop(stack);
                char *rndstr = randString();
                //TODO: EXECUTE OPERATION ALSO IN HERE AND ASSIGN rndstr to a variable
                printf("Variable %s = division ( %s , %s );\n", rndstr , a.name , b.name  );
            }
            if(strcmp(list->start->name , "tr")==0){  
                struct Variable a = top(stack);
                pop(stack);
                char *rndstr = randString();
                //TODO: EXECUTE OPERATION ALSO IN HERE AND ASSIGN rndstr to a variable
                printf("Variable %s = transpose ( %s );\n", rndstr  , a.name );
            }
            if(strcmp(list->start->name , "choose")==0){
                struct Variable a = top(stack);
                pop(stack);
                struct Variable b = top(stack);
                pop(stack);
                struct Variable c = top(stack);
                pop(stack);
                struct Variable d = top(stack);
                pop(stack);
                char *rndstr = randString();
                //TODO: EXECUTE OPERATION ALSO IN HERE AND ASSIGN rndstr to a variable
                printf("Variable %s = choose ( %s , %s , %s , %s);\n", rndstr  , a.name , b.name , c.name , d.name);
            }
            if(strcmp(list->start->name , "sqrt")==0){
                struct Variable a = top(stack);
                pop(stack);
                char *rndstr = randString();
                //TODO: EXECUTE OPERATION ALSO IN HERE AND ASSIGN rndstr to a variable
                printf("Variable %s = sqrt ( %s );\n", rndstr  , a.name );
            }

        }
    }

}

/*

choose(i,6,sqrt(x*y-5),choose(4,1, tr ( i ) , 0 )) + choose (4, 1, tr ( x*9 ) , 0 )


choose CHOOSE
( LEFT_PARENTHESIS
i IDENTIFIER
, COMMA
6 NUMBER
, COMMA
sqrt SQRT
( LEFT_PARENTHESIS
x IDENTIFIER
* MULTIPLICATION
y IDENTIFIER
- SUBTRACTION
5 NUMBER
) RIGHT_PARENTHESIS
, COMMA
choose CHOOSE
( LEFT_PARENTHESIS
4 NUMBER
, COMMA
1 NUMBER
, COMMA
tr TR
( LEFT_PARENTHESIS
i IDENTIFIER
) RIGHT_PARENTHESIS
, COMMA
0 NUMBER
) RIGHT_PARENTHESIS
) RIGHT_PARENTHESIS
+ ADDITION
choose CHOOSE
( LEFT_PARENTHESIS
4 NUMBER
, COMMA
1 NUMBER
, COMMA
tr TR
( LEFT_PARENTHESIS
x IDENTIFIER
* MULTIPLICATION
9 NUMBER
) RIGHT_PARENTHESIS
, COMMA
0 NUMBER
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