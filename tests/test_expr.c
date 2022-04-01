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
    tokenizeLine(graph, "choose(i,6,sqrt(x*y-5),choose(4,1, tr ( i ) , 0 )) + choose (4, 1, tr ( x*9 ) , 0 )");

    struct variable temp1 = multiply(x, 9);
    struct varibale temp2 = tr(temp1);
    struct varibale temp3 = tr(temp1);
    // tokenizeLine(graph, "choose(1, 2, 3, 4)");
    // tokenizeLine(graph, "7 + 8*9");
    int len = tokenLen(tokens);
    for(int i = 0; i < len; i++){
        printf("%s %s\n",tokenChars[i], enumToString(tokens[i]));
    }
    int last = expr(0, len - 1);
    // printf("SURAYA KADAR GELDI = %d\n",last);
    // printf("SURAYA KADAR GELDI = %d\n",last);
    // printf("SURAYA KADAR GELDI = %d\n",last);
    // printf("SURAYA KADAR GELDI = %d\n",last);
    return 0;
}