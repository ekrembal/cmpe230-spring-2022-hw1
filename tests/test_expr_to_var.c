#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../expr.h"
#include "../expr_to_var.h"

int main(){
    ParserGraph *graph = createParserGraph();
    tokenizeLine(graph, "choose(i,6,sqrt(x*y-5),choose(4,1, tr ( i ) , 0 )) + choose (4, 1, tr ( x*9 ) , 0 )");

  
    // tokenizeLine(graph, "choose(1, 2, 3, 4)");
    // tokenizeLine(graph, "7 + 8*9");
    int len = tokenLen(tokens);    
    for(int i = 0; i < len; i++){
        printf("%s %s\n",tokenChars[i], enumToString(tokens[i]));
    }
    int last = expr(0, len - 1);
    return 0;
}