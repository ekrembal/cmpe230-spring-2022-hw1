#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../expr.h"

int tokens[1024];
char tokenChars[1024][1024];

int tokenLen(int *tokens){
	for(int i = 0; i < MAX_TOKENS; i++){
		if(tokens[i] == -1){
			return i;
		}
	}
	return 1024;
}

int main(){
    ParserGraph *graph = createParserGraph();
    tokenizeLine(graph, "choose (i, 6, sqrt(x*y-5), choose (4, 1, tr ( i ) , 0 )) + choose (4, 1, tr ( x*9 ) , 0 )");
    int len = tokenLen(tokens);
    for(int i = 0; i < len; i++){
        printf("OFFF %s %d\n",tokenChars[i], tokens[i]);
        if(tokens[i] == NUMBER){
            printf("%d\n",atoi(tokenChars[i]));
        }
    }
    return 0;
}