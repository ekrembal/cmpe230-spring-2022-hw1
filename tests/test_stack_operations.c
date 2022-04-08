#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../stack_operations.h"


// i 6 x y * 5 - 4 1 i tr 0 Choose Choose 4 1 x 9 * tr 0 Choose +
int main(){

    printf("BASLADI\n");
    struct List* temp =    createList();

    // assert(temp != NULL);
    assert(sizeOfList(temp) == 0);

    struct Variable var;
    var.name = "5";
    var.feature = NUMBER;
    var.variable_type = -1;
    var.dim1=-1;
    var.dim1=-1;

    addToList(temp, var);

    assert(sizeOfList(temp) == 1);


    struct Variable var1;
    var1.name = "+";
    var1.feature = OPERATION;
    var1.variable_type = 0;
    var1.dim1=-1;
    var1. dim1=-1;

    addToList(temp, var1);

    assert(sizeOfList(temp) == 2);

    struct Variable var2;
    var.name = "6";
    var.feature = NUMBER;
    var.variable_type = -1;
    var.dim1=-1;
    var.dim1=-1;

    addToList(temp, var2);

    assert(sizeOfList(temp) == 3);

    evaluateList(temp);
    printf("BITTI\n");
    



    return 0;
}