#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#include "string_operations.h"
#include "parser_graph.h"
#define MAX_TOKENS 1024

// enum line_types {
// 	FOR_LOOP,
// 	DOUBLE_FOR_LOOP,
// 	CREATING_SCALAR,
// 	CREATING_VECTOR,
// 	CREATING_MATRIX,
// 	CONSTANT_ASSIGNMENT,
// 	EXPRESSION_ASSIGNMENT,
// 	PRINT,
// 	PRINTSEP,
// 	FOR_LOOP_END
// };
// enum token_type {
//     START,
//     IDENTIFIER, // <Identifier> starts with alpha or underscore and can contain numbers and underscores
//     NUMBER, // <Number> starts with digit
//     ASSIGNMENT, // =
//     ADDITION, // +
//     SUBTRACTION, // -
//     MULTIPLICATION, // *
//     LEFT_PARENTHESIS, // (
//     RIGHT_PARENTHESIS, // )
//     LEFT_BRACKET, // [
//     RIGHT_BRACKET, // ]
//     LEFT_BRACE, // {
//     RIGHT_BRACE, // }
//     COMMA, // ,
//     FOR, // for
//     PRINT, // print
//     PRINTSEP, // printsep
//     SCALAR, // scalar
//     VECTOR, // vector
//     MATRIX, // matrix
//     UNKNOWN, // Unknown token
//     IN, // in
//     TWO_DOTS, // :
//     END_OF_FILE, // EOF
//     SQRT, // sqrt
//     CHOOSE, // choose
//     TR, // tr
//     EXPRESSION,
//     LIST_OF_NUMBERS
// };

int FOR_LOOP_TOKENS[] = {FOR, LEFT_PARENTHESIS, IDENTIFIER, IN, EXPRESSION, TWO_DOTS, EXPRESSION, TWO_DOTS, EXPRESSION, RIGHT_PARENTHESIS, LEFT_BRACE, -1};
int DOUBLE_FOR_LOOP_TOKENS[] = {FOR, LEFT_PARENTHESIS, IDENTIFIER, COMMA, IDENTIFIER, IN, EXPRESSION, TWO_DOTS, EXPRESSION, TWO_DOTS, EXPRESSION, COMMA, EXPRESSION, TWO_DOTS, EXPRESSION, TWO_DOTS, EXPRESSION, RIGHT_PARENTHESIS, LEFT_BRACE, -1};
int CREATING_SCALAR_TOKENS[] = {SCALAR, IDENTIFIER, -1};
int CREATING_VECTOR_TOKENS[] = {VECTOR, IDENTIFIER, LEFT_BRACKET, NUMBER, RIGHT_BRACKET, -1};
int CREATING_MATRIX_TOKENS[] = {MATRIX, IDENTIFIER, LEFT_BRACKET, NUMBER, COMMA, NUMBER, RIGHT_BRACKET, -1};
int CONSTANT_ASSIGNMENT_TOKENS[] = {IDENTIFIER, ASSIGNMENT, LEFT_BRACE, LIST_OF_NUMBERS, RIGHT_BRACE, -1};
int EXPRESSION_ASSIGNMENT_TOKENS[] = {IDENTIFIER, ASSIGNMENT, EXPRESSION, -1};
int PRINT_TOKENS[] = {PRINT, LEFT_PARENTHESIS, EXPRESSION, RIGHT_PARENTHESIS, -1};
// int PRINT_TOKENS[] = {PRINT, LEFT_PARENTHESIS, IDENTIFIER, RIGHT_PARENTHESIS, -1};
int PRINTSEP_TOKENS[] = {PRINTSEP, LEFT_PARENTHESIS, RIGHT_PARENTHESIS, -1};
int FOR_LOOP_END_TOKENS[] = {RIGHT_BRACE, -1};

bool isArraysEqual(int *arr1, int *arr2){
	int i = 0;
	while(arr1[i] != -1 && arr2[i] != -1){
		if(arr1[i] != arr2[i]){
			return false;
		}
		i++;
	}
	return (arr1[i] == -1 && arr2[i] == -1);
}

void giveError(int errorLine){
	printf("Error in line %d\n", errorLine);
	exit(1);
}

int tokenLen(int *tokens){
	for(int i = 0; i < MAX_TOKENS; i++){
		if(tokens[i] == -1){
			return i;
		}
	}
	return MAX_TOKENS;
}

void removeComments(char *str) {
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] == '#') {
			str[i] = '\0';
			break;
		}
	}
}

bool isValidLine(char *str) {
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (!isAllowedCharacter(str[i]) && !isWhiteSpace(str[i])) {
			return false;
		}
	}
	return true;
}




int main(int argc, char *argv[]) {
	// Get the input file name
	char *input_file_name = argv[1];
	char *output_file_name = "file.c";
	printf("input filename is %s\n", input_file_name);
	printf("output filename is %s\n", output_file_name);
	// Open file
	FILE *input_file = fopen(input_file_name, "r");
	if (input_file == NULL) {
		printf("Error opening file\n");
		return 1;
	}
	// Read file line by line
	char line[1024];
	int tokens[MAX_TOKENS];
	ParserGraph *graph = createParserGraph();
	int lineCount = 0;
	while (fgets(line, sizeof(line), input_file) != NULL) {
		lineCount++;
		// Remove comments
		removeComments(line);
		// Check if line is valid
		if (!isValidLine(line))
			giveError(lineCount);
		// Tokenize line
		tokenizeLine(graph, line, tokens);
		// int len = tokenLen(tokens);
		// for(int i = 0; i < len; i++)
		// 	printf("%d ", tokens[i]);
		// printf("\n");

		// printf("CREATING_VECTOR_TOKENS = ");
		// len = tokenLen(CREATING_VECTOR_TOKENS);
		// for(int i = 0; i < len; i++)
		// 	printf("%d ", CREATING_VECTOR_TOKENS[i]);
		// printf("\n");

		// printf("CREATING_SCALAR_TOKENS = ");
		// len = tokenLen(CREATING_SCALAR_TOKENS);
		// for(int i = 0; i < len; i++)
		// 	printf("%d ", CREATING_SCALAR_TOKENS[i]);
		// printf("\n");
		if(tokens[0] == -1){
			continue;
		} else if(isArraysEqual(tokens, CREATING_SCALAR_TOKENS)){
			printf("CREATING SCALAR\n");
		} else if(isArraysEqual(tokens, CREATING_VECTOR_TOKENS)){
			printf("CREATING VECTOR\n");
		} else if(isArraysEqual(tokens, CREATING_MATRIX_TOKENS)){
			printf("CREATING MATRIX\n");
		} else if(isArraysEqual(tokens, CONSTANT_ASSIGNMENT_TOKENS)){
			printf("CONSTANT ASSIGNMENT\n");
		} else if(isArraysEqual(tokens, EXPRESSION_ASSIGNMENT_TOKENS)){
			printf("EXPRESSION ASSIGNMENT\n");
		} else if(isArraysEqual(tokens, PRINT_TOKENS)){
			printf("PRINT\n");
		} else if(isArraysEqual(tokens, PRINTSEP_TOKENS)){
			printf("PRINTSEP\n");
		} else if(isArraysEqual(tokens, FOR_LOOP_TOKENS)){
			printf("FOR LOOP\n");
		} else if(isArraysEqual(tokens, DOUBLE_FOR_LOOP_TOKENS)){
			printf("DOUBLE FOR LOOP\n");
		} else if(isArraysEqual(tokens, FOR_LOOP_END_TOKENS)){
			printf("FOR LOOP END\n");
		} else {
			printf("UNKNOWN\n");
		}
		printf("%s\n", line);

	}
	// Close file
	fclose(input_file);
	return 0;
}
