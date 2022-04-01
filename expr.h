#ifndef _expr_h
#define _expr_h
#include "parser_graph.h"
#include "stack_operations.h"

#define DEBUG false

int factor(int, int);
int term(int, int);
int expr(int, int);
int moreterms(int, int);
int morefactors(int, int);

int factor(int left, int right){
    if(DEBUG){ printf("factor(%d, %d)->", left, right); for(int i = left; i <= right; i++) printf("%s ", tokenChars[i]); printf("\n"); }
    if(left > right)return -1;
    int tempLeft = 0;
	if(tokens[left] == LEFT_PARENTHESIS && (tempLeft = expr(left + 1, right)) != -1 && tokens[tempLeft] == RIGHT_PARENTHESIS ){
        return tempLeft;
	}
    tempLeft = 0;
    if(
        tokens[left] == IDENTIFIER &&
        tokens[left + 1] == LEFT_BRACKET &&
        (tempLeft = expr(left + 2, right)) != -1 &&
        tokens[tempLeft] == COMMA &&
        (tempLeft = expr(tempLeft + 1, right)) != -1 &&
        tokens[tempLeft] == RIGHT_BRACKET
        )
        {
            printf("getDoubleIndex ");
            return tempLeft + 1;
        }
    tempLeft = 0;
    if(
        tokens[left] == IDENTIFIER &&
        tokens[left + 1] == LEFT_BRACKET &&
        (tempLeft = expr(left + 2, right)) != -1 &&
        tokens[tempLeft] == RIGHT_BRACKET
        )
        {
            printf("getSingleIndex ");
            return tempLeft + 1;
        }
    tempLeft = 0;
    if(
        tokens[left] == SQRT &&
        tokens[left + 1] == LEFT_PARENTHESIS &&
        (tempLeft = expr(left + 2, right)) != -1 &&
        tokens[tempLeft] == RIGHT_PARENTHESIS
        )
        {
            printf("sqrt ");
            add_stack(Var())
            return tempLeft + 1;
        }
    tempLeft = 0;
    // if(tokens[left] == CHOOSE){
    //     printf("Choose bulundu\n");
    //     if((tempLeft = expr(left + 2, right)) != -1){
    //         printf("%d'e kadar expr bulundu\n", tempLeft);
    //     }
    //     printf("OFF teni templeft = %d\n", tempLeft);
    //     if(tokens[tempLeft] == COMMA){
    //         printf("%d'de virgul bulundu\n",tempLeft);
    //     }
    //     return tempLeft;


    // }
    tempLeft = 0;
    if(
        tokens[left] == CHOOSE &&
        tokens[left + 1] == LEFT_PARENTHESIS &&
        (tempLeft = expr(left + 2, right)) != -1 &&
        tokens[tempLeft] == COMMA &&
        (tempLeft = expr(tempLeft + 1, right)) != -1 &&
        tokens[tempLeft] == COMMA &&
        (tempLeft = expr(tempLeft + 1, right)) != -1 &&
        tokens[tempLeft] == COMMA &&
        (tempLeft = expr(tempLeft + 1, right)) != -1 &&
        tokens[tempLeft] == RIGHT_PARENTHESIS
        )
        {
            printf("Choose ");
            return tempLeft + 1;
        }
    tempLeft = 0;
    if(tokens[left] == IDENTIFIER){
        printf("%s ",tokenChars[left]);
        return left + 1;
    }
    tempLeft = 0;
    if(tokens[left] == NUMBER){
        printf("%s ", tokenChars[left]);
        return left + 1;
    }
    tempLeft = 0;
    if(
        tokens[left] == TR &&
        tokens[left + 1] == LEFT_PARENTHESIS &&
        (tempLeft = expr(left + 2, right)) != -1 &&
        tokens[tempLeft] == RIGHT_PARENTHESIS
        )
        {
            printf("tr ");
            return tempLeft + 1;
        }
    return -1;
}

int moreterms(int left, int right){
    if(DEBUG){ printf("moreterms(%d, %d)->", left, right); for(int i = left; i <= right; i++) printf("%s ", tokenChars[i]); printf("\n"); }
    if(left > right)return left;
    // if(DEBUG) printf("moreterms(%d, %d)\n", left, right);
    int tempLeft;
	if( ((tokens[left] == ADDITION) || (tokens[left] == SUBTRACTION)) && ((tempLeft = term(left + 1, right)) != -1) && ((tempLeft = moreterms(tempLeft, right)) != -1)){
        printf("%s ", tokenChars[left]);
        // exit(0);
		return tempLeft;
	}
	return left;
}

int morefactors(int left, int right){
    if(DEBUG){ printf("morefactors(%d, %d)->", left, right); for(int i = left; i <= right; i++) printf("%s ", tokenChars[i]); printf("\n"); }
    if(left > right)return left;
    int tempLeft;
    if(left >= right)
        return left;
        // exit(0);
	if(tokens[left] == MULTIPLICATION && ((tempLeft = factor(left + 1, right)) != -1) && ((tempLeft = morefactors(tempLeft, right)) != -1)){
        printf("* ");
        // printf("%s ",enumToString(tokens[left]));
        // printf("GELDIIIIIIII %d %d %d\n",left,right, tempLeft);
        // exit(0);
        return tempLeft;
    }
    return left;
	// printf("%d\n", tokens[left]);
	// left++;
	// if()
	// 	return -1;
	// if( (left = morefactors(left, right)) == -1)
	// 	return -1;
	// return left;
}

int term(int left, int right){
    if(DEBUG){ printf("term(%d, %d)->", left, right); for(int i = left; i <= right; i++) printf("%s ", tokenChars[i]); printf("\n"); }
    if(left > right)return -1;
    int tempLeft;
    if((tempLeft = factor(left, right)) != -1 && ((tempLeft = morefactors(tempLeft, right)) != -1)){
        return tempLeft;
    }
    return -1;
}

int expr(int left, int right){
    if(DEBUG){ printf("expr(%d, %d)->", left, right); for(int i = left; i <= right; i++) printf("%s ", tokenChars[i]); printf("\n"); }
    if(left > right)return -1;
	int tempLeft;
    if((tempLeft = term(left, right)) != -1 && ((tempLeft = moreterms(tempLeft, right)) != -1))
        return tempLeft;
    return -1;
}

#endif