#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../parser_graph.h"

int main(){
    ParserGraph *graph = createParserGraph();
    // printf("Printing graph:\n");
    // dfs(graph->root);
    parseLine(graph, "matrix B[2,3]");puts("");
    parseLine(graph, "z = A*B*y");puts("");
    parseLine(graph, "B = { 1 0 0 1 }");puts("");
    parseLine(graph, "for(i in 1:n:1) {");puts("");
    parseLine(graph, "print(x)");puts("");
    parseLine(graph, "printsep()");puts("");
    return 0;
}