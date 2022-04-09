// #ifndef _stack_h
// #define _stack_h


// variable st[1024];
// int lastIndex;

// void add(Var x){
//     st[++lastIndex] = x;
// }

// Var top(){
// }


// struct Node {
//     int data;
//     struct Node* next;
// };

// typedef struct Stack {
//     struct Node* top;
//     int size;
// } Struct;

// void push(struct Stack* stack, int data){
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = stack->top;
//     stack->top = newNode;
//     stack->size++;
// }

// int top(struct Stack* stack){
//     return stack->top->data;
// }

// void pop(struct Stack* stack){
//     struct Node* temp = stack->top;
//     stack->top = stack->top->next;
//     free(temp);
//     stack->size--;
// }

// int isEmpty(struct Stack* stack){
//     return stack->size == 0;
// }

// struct Stack* createStack(){
//     struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
//     stack->top = NULL;
//     stack->size = 0;
//     return stack;
// }

// int sizeOf(struct Stack* stack){
//     return stack->size;
// }


// // Here you can see the stack usage

// // struct Stack* temp = createStack();
// // push(temp, 5);
// // push(temp, 6);
// // push(temp, 7);
// // printf("%d\n", top(temp));
// // printf("%d\n", isEmpty(temp));
// // pop(temp);
// // printf("%d\n", top(temp));
// // printf("%d\n", isEmpty(temp));
// // pop(temp);
// // printf("%d\n", top(temp));
// // printf("%d\n", isEmpty(temp));
// // pop(temp);
// // printf("%d\n", isEmpty(temp));
// // printf("%d\n", top(temp));


// #endif