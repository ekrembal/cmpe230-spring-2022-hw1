#ifndef _expr_h
#define _expr_h
#include "parser_graph.h"
#include "stack.h"

#define DEBUG true

int factor(int, int);
int term(int, int);
int expr(int, int);
int moreterms(int, int);
int morefactors(int, int);

int factor(int left, int right){
    if(DEBUG){ printf("factor(%d, %d) for ", left, right); for(int i = left; i <= right; i++) printf("%s ", tokenChars[i]); printf("\n"); }
    if(left > right)return -1;
    if(tokens[left] == NUMBER){
        printf("%s ",tokenChars[left]);
        return left + 1;
    }
    return -1;
	// int left1, left2, left3, left4;
	// if(tokens[left] == LEFT_PARENTHESIS && tokens[right] == RIGHT_PARENTHESIS){
	// 	if(left1 = expr(left + 1, right - 1)){
	// 		return left1;
	// 	} else{
	// 		return -1;
	// 	}
	// 	return right + 1;
	// }
	// if(tokens[left] == IDENTIFIER && tokens[left + 1] == LEFT_BRACKET && tokens[right] == RIGHT_BRACKET){
	// 	if((left = expr(left + 2, right - 1)) != -1){
	// 		if()
	// 	}

	// }
}

int moreterms(int left, int right){
    if(DEBUG){ printf("moreterms(%d, %d) for ", left, right); for(int i = left; i <= right; i++) printf("%s ", tokenChars[i]); printf("\n"); }
    if(left > right)return left;
    // if(DEBUG) printf("moreterms(%d, %d)\n", left, right);
    int tempLeft;
	if( ((tokens[left] == ADDITION) || (tokens[left] == SUBTRACTION)) && ((tempLeft = term(left + 1, right)) != -1) && ((tempLeft = moreterms(tempLeft, right)) != -1)){
        printf("%s ", enumToString(tokens[left]));
		return tempLeft;
	}
	return left;
}

int morefactors(int left, int right){
    if(DEBUG){ printf("morefactors(%d, %d) for ", left, right); for(int i = left; i <= right; i++) printf("%s ", tokenChars[i]); printf("\n"); }
    if(left > right)return left;
    int tempLeft;
    if(left >= right)
        exit(0);
	if(tokens[left] == MULTIPLICATION && ((tempLeft = factor(left + 1, right)) != -1) && ((tempLeft = morefactors(tempLeft, right)) != -1)){
        printf("%s ",enumToString(tokens[left]));
        printf("GELDIIIIIIII %d %d\n",left,right);
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
    if(DEBUG){ printf("term(%d, %d) for ", left, right); for(int i = left; i <= right; i++) printf("%s ", tokenChars[i]); printf("\n"); }
    if(left > right)return -1;
    int tempLeft;
    if((tempLeft = factor(left, right)) != -1 && (tempLeft = morefactors(tempLeft, right) != -1)){
        return tempLeft;
    }
    return -1;
}

int expr(int left, int right){
    if(DEBUG){ printf("expr(%d, %d) for ", left, right); for(int i = left; i <= right; i++) printf("%s ", tokenChars[i]); printf("\n"); }
    if(left > right)return -1;
	int tempLeft;
    if((tempLeft = term(left, right)) != -1 && (tempLeft = moreterms(tempLeft, right) != -1))
        return tempLeft;
    return -1;
}

#endif