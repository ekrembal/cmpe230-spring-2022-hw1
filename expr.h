#ifndef _expr_h
#define _expr_h
#include "parser_graph.h"
#include "stack.h"

int factor(int, int);
int term(int, int);
int expr(int, int);
int moreterms(int, int);
int morefactors(int, int);

int factor(int left, int right){
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
	if(left > right){
		return left;
	}
	if(tokens[left] != ADDITION && tokens[left] != SUBTRACTION){
		return -1;
	}
	printf("%d\n", tokens[left]);
	left++;
	if((left = term(left, right)) == -1)
		return -1;
	if( (left = moreterms(left, right)) == -1)
		return -1;
	return left;
}

int morefactors(int left, int right){
	if(left > right){
		return left;
	}
	if(tokens[left] != MULTIPLICATION){
		return -1;
	}
	printf("%d\n", tokens[left]);
	left++;
	if((left = factor(left, right)) == -1)
		return -1;
	if( (left = morefactors(left, right)) == -1)
		return -1;
	return left;
}

int term(int left, int right){
	if(left > right){
		return -1;
	}
	if((left = factor(left, right)) == -1)
		return -1;
	if( (left = morefactors(left, right)) == -1)
		return -1;
	return left;
}

int expr(int left, int right){
	if(left > right){
		return -1;
	}
	if((left = term(left, right)) == -1)
		return -1;
	if( (left = moreterms(left, right)) == -1)
		return -1;
	return left;
}

#endif