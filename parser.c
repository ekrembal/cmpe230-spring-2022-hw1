#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#include "string_operations.h"
#define MAX_TOKENS 1024

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
	for (i = 0; i < len; i++) {
		if (str[i] == '#') {
			str[i] = '\0';
			break;
		}
	}
}

bool isValidLine(char *str) {
	int len = strlen(str);
	for (i = 0; i < len; i++) {
		if (!isAllowedCharacter(str[i]) && !isWhiteSpace(str[i])) {
			return false;
		}
	}
	return true;
}


enum line_types {
	FOR_LOOP,
	DOUBLE_FOR_LOOP,
	CREATING_SCALAR,
	CREATING_VECTOR,
	CREATING_MATRIX,
	CONSTANT_ASSIGNMENT,
	EXPRESSION_ASSIGNMENT,
	PRINT,
	PRINTSEP,
	FOR_LOOP_END
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
		// Get length of tokens
		int len = tokenLen(tokens);
		if(len == 0){
			printf("Empyt line");
		} else if(len > 0 && tokens[0] == SCALAR){
			printf("SCALAR");
		} else if(len > 0 && tokens[0] == VECTOR){
			printf("VECTOR");
		} else if(len > 0 && tokens[0] == MATRIX){
			printf("MATRIX");
		} else if(len > 0 && tokens[0] == PRINT){
			printf("PRINT");
		else if(len > 0 && tokens[0] == PRINTSEP){
		} else if(len > 2 && tokens[0] == IDENTIFIER && tokens[1] == ASSIGNMENT && tokens[2] == LEFT_BRACE){
			printf("CONSTANT ASSIGNMENT");
		}

	}
	// Close file
	fclose(input_file);
	return 0;
}
