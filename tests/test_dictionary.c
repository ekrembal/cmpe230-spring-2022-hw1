#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../dictionary.h"

int main(){

    printf("DICTIONARY TEST");

    struct Dictionary* temp = createDictionary();

    // assert(temp != NULL);
    assert(isEmpty(temp) == 1);

    add(temp, "AAAA1111",1);

    assert(isEmpty(temp) == 0);
    assert(query(temp,  "AAAA1111") == 1);

    add(temp, "BBBBB22222", 2);

    assert(isEmpty(temp) == 0);
    assert(query(temp, "BBBBB22222" ) == 2);

    add(temp, "CCCCCC33333" , 3 );

    assert(isEmpty(temp) == 0);
    assert(query(temp, "CCCCCC33333") == 3 );


    printf("%d\n", query(temp, "CCCCCC33333"));


    return 0;
}