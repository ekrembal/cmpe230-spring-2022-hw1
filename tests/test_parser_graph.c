#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../parser_graph.h"

int main(){
    ParserGraph *graph = createParserGraph();
    printf("Printing graph:\n");
    dfs(graph->root);
    return 0;
}