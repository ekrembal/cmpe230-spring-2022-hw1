#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

FILE *out;
#include "stack.h"
#include "string_operations.h"
#include "parser_graph.h"
#include "stack_operations.h"
#include "expr.h"
#define MAX_TOKENS 1024
int lineCount = 0;

int CREATING_SCALAR_TOKENS[] = {SCALAR, IDENTIFIER, -1};
int CREATING_VECTOR_TOKENS[] = {VECTOR, IDENTIFIER, LEFT_BRACKET, NUMBER, RIGHT_BRACKET, -1};
int CREATING_MATRIX_TOKENS[] = {MATRIX, IDENTIFIER, LEFT_BRACKET, NUMBER, COMMA, NUMBER, RIGHT_BRACKET, -1};
int CONSTANT_ASSIGNMENT_TOKENS[] = {IDENTIFIER, ASSIGNMENT, LEFT_BRACE, LIST_OF_NUMBERS, RIGHT_BRACE, -1};
int EXPRESSION_ASSIGNMENT_TOKENS[] = {IDENTIFIER, ASSIGNMENT, EXPRESSION, -1};
int PRINT_SCALAR_TOKENS[] = {PRINT, LEFT_PARENTHESIS, EXPRESSION, RIGHT_PARENTHESIS, -1};
int PRINT_VECTOR_TOKENS[] = {PRINT, LEFT_PARENTHESIS, EXPRESSION, RIGHT_PARENTHESIS, -1};
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

void giveError(){
	printf("Error in line %d\n", lineCount);
	exit(1);
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

int checkConstantAssignment(){
	if(!(tokens[0] == IDENTIFIER && tokens[1] == ASSIGNMENT && tokens[2] == LEFT_BRACE))
		return 0;
	int i = 3;
	for(; tokens[i] != -1; i++){
		if(tokens[i] == RIGHT_BRACE){
			if(tokens[i + 1] == -1)
				return i - 3;
			else
				return 0;
		} else if(tokens[i] != NUMBER){
			return 0;
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	// Get the input file name
	char *input_file_name = argv[1];
    // Copy input file name to output file name and change the extension to .c
    char *output_file_name = (char *)malloc(strlen(input_file_name) + 5);
    strcpy(output_file_name, input_file_name);
    int output_file_len = strlen(output_file_name);

    output_file_name[output_file_len - 3] = 'c';
    output_file_name[output_file_len - 2] = '\0';

	printf("input filename is %s\n", input_file_name);
	printf("output filename is %s\n", output_file_name);
	// Open file
	FILE *input_file = fopen(input_file_name, "r");
	if (input_file == NULL) {
		printf("Error opening file\n");
		return 1;
	}
    // Open output file
    out = fopen(output_file_name, "w");
    if (out == NULL) {
        printf("Error opening file\n");
        return 1;
    }
	// Read file line by line
	char line[1024];
	ParserGraph *graph = createParserGraph();
    int forLoopType = 0;
	while (fgets(line, sizeof(line), input_file) != NULL) {
        
		lineCount++;
		// Remove comments
		removeComments(line);

		// Check if line is valid
		if (!isValidLine(line))
			giveError();
		// Tokenize line
		// printf("GELDI");
		// return 0;
		tokenizeLine(graph, line);
		
		int len = tokenLen(tokens);
		// for(int i = 0; i < len; i++){
		// 	printf("OFFF %s %s\n",tokenChars[i], enumToString(tokens[i]));
		// 	if(tokens[i] == NUMBER){
		// 		printf("%d\n",atoi(tokenChars[i]));
		// 	}
		// }
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
		int constantAssignment = checkConstantAssignment();
		if(tokens[0] == -1){
			continue;
		} else if(isArraysEqual(tokens, CREATING_SCALAR_TOKENS)){
			// printf("CREATING SCALAR\n");
			// TODO: Check if variable is already declared
			// TODO: Check if numbers are not floating point
			fprintf(out, "Variable *%s = createScalar();\n", tokenChars[1]);
			// TODO: add this scalar to dictionary
		} else if(isArraysEqual(tokens, CREATING_VECTOR_TOKENS)){
			// printf("CREATING VECTOR with len %d\n", atoi(tokenChars[3]));
			// TODO: Check if variable is already declared
			// TODO: Check if numbers are not floating point
			fprintf(out, "Variable *%s = createVector(%d);\n", tokenChars[1], atoi(tokenChars[3]));
			// TODO: add this vector to dictionary
		} else if(isArraysEqual(tokens, CREATING_MATRIX_TOKENS)){
			// printf("CREATING MATRIX with shape %d %d\n", atoi(tokenChars[3]), atoi(tokenChars[5]));
			// TODO: Check if variable is already declared
			// TODO: Check if numbers are not floating point
			fprintf(out, "Variable *%s = createMatrix(%d, %d);\n", tokenChars[1], atoi(tokenChars[3]), atoi(tokenChars[5]));
			// TODO: Add this matrix to dictionary
		} else if(constantAssignment){
			// printf("CONSTANT ASSIGNMENT to the variable %s with %d numbers\n", tokenChars[0], constantAssignment);
			// TODO: check if sizes match
			// printf("assignMultiple(&%s, ", tokenChars[0]);
			for(int i = 0; i < constantAssignment; i++){
                fprintf(out, "assignToFlatten(%s, %s, %d);", tokenChars[0], tokenChars[i + 3], i);
				// printf("%s", tokenChars[i + 3]);
				// if(i != constantAssignment - 1)
				// 	printf(", ");
			}
			fprintf(out, "\n");
		} else if(isArraysEqual(tokens, PRINTSEP_TOKENS)){
			fprintf(out, "printsep();\n");
		} else if(tokens[0] == PRINT){
            // printf("PRINTEE geldiii\n");
            if(tokens[1] == LEFT_PARENTHESIS
            && (tokens[2] == IDENTIFIER)
            && (tokens[3] == RIGHT_PARENTHESIS)
            ){
                fprintf(out, "print(%s);\n", tokenChars[2]);
            } else if(tokens[1] == LEFT_PARENTHESIS
            && (tokens[2] == IDENTIFIER)
            && (tokens[3] == LEFT_BRACKET)
            && (tokens[4] == NUMBER)
            && (tokens[5] == RIGHT_BRACKET)
            && (tokens[6] == RIGHT_PARENTHESIS)
            ){
                fprintf(out, "print(getSingleIndex(%s, %s));\n", tokenChars[2], tokenChars[4]);
            } else if(tokens[1] == LEFT_PARENTHESIS
            && (tokens[2] == IDENTIFIER)
            && (tokens[3] == LEFT_BRACKET)
            && (tokens[4] == NUMBER)
            && (tokens[5] == COMMA)
            && (tokens[6] == NUMBER)
            && (tokens[7] == RIGHT_BRACKET)
            && (tokens[8] == RIGHT_PARENTHESIS)
            ){
                fprintf(out, "print(getDoubleIndex(%s, %s, %s));\n", tokenChars[2], tokenChars[4], tokenChars[6]);
            } else {
                raiseError();
            }
        }
// int FOR_LOOP_TOKENS[] = {FOR, LEFT_PARENTHESIS, IDENTIFIER, IN, EXPRESSION, TWO_DOTS, EXPRESSION, TWO_DOTS, EXPRESSION, RIGHT_PARENTHESIS, LEFT_BRACE, -1};
// int DOUBLE_FOR_LOOP_TOKENS[] = {FOR, LEFT_PARENTHESIS, IDENTIFIER, COMMA, IDENTIFIER, IN, EXPRESSION, TWO_DOTS, EXPRESSION, TWO_DOTS, EXPRESSION, COMMA, EXPRESSION, TWO_DOTS, EXPRESSION, TWO_DOTS, EXPRESSION, RIGHT_PARENTHESIS, LEFT_BRACE, -1};

        else if(tokens[0] == FOR){
            int tempLeft;
            if(tokens[1] == LEFT_PARENTHESIS
            && (tokens[2] == IDENTIFIER)
            && (tokens[3] == IN)
            && (tempLeft = expr(4, len, false)) != -1
            && (tokens[tempLeft] == TWO_DOTS)
            && (tempLeft = expr(tempLeft + 1, len, false)) != -1
            && (tokens[tempLeft] == TWO_DOTS)
            && (tempLeft = expr(tempLeft + 1, len, false)) != -1
            && (tokens[tempLeft] == RIGHT_PARENTHESIS)
            && (tokens[tempLeft + 1] == LEFT_BRACE)
            ){
                tempLeft = parseExpression(4, len);
                Variable* expr1 = evaluateList(&globalList);

                tempLeft = parseExpression(tempLeft + 1, len);
                Variable* expr2 = evaluateList(&globalList);

                tempLeft = parseExpression(tempLeft + 1, len);
                Variable* expr3 = evaluateList(&globalList);
                forLoopType=1;
                fprintf(out, "for(assign(%s,%s); isLower(%s,%s); increase(%s,%s)){\n", tokenChars[2],expr1->name, tokenChars[2],expr2->name, tokenChars[2],expr3->name);
            } else if(tokens[1] == LEFT_PARENTHESIS
            && (tokens[2] == IDENTIFIER)
            && (tokens[3] == COMMA)
            && (tokens[4] == IDENTIFIER)
            && (tokens[5] == IN)
            && (tempLeft = expr(6, len, false)) != -1
            && (tokens[tempLeft] == TWO_DOTS)
            && (tempLeft = expr(tempLeft + 1, len, false)) != -1
            && (tokens[tempLeft] == TWO_DOTS)
            && (tempLeft = expr(tempLeft + 1, len, false)) != -1
            && (tokens[tempLeft] == COMMA)
            && (tempLeft = expr(tempLeft + 1, len, false)) != -1
            && (tokens[tempLeft] == TWO_DOTS)
            && (tempLeft = expr(tempLeft + 1, len, false)) != -1
            && (tokens[tempLeft] == TWO_DOTS)
            && (tempLeft = expr(tempLeft + 1, len, false)) != -1
            && (tokens[tempLeft] == RIGHT_PARENTHESIS)
            && (tokens[tempLeft + 1] == LEFT_BRACE)
            ){
                tempLeft = parseExpression(6, len);
                Variable* expr1 = evaluateList(&globalList);

                tempLeft = parseExpression(tempLeft + 1, len);
                Variable* expr2 = evaluateList(&globalList);

                tempLeft = parseExpression(tempLeft + 1, len);
                Variable* expr3 = evaluateList(&globalList);

                tempLeft = parseExpression(tempLeft + 1, len);
                Variable* expr4 = evaluateList(&globalList);

                tempLeft = parseExpression(tempLeft + 1, len);
                Variable* expr5 = evaluateList(&globalList);


                tempLeft = parseExpression(tempLeft + 1, len);
                Variable* expr6 = evaluateList(&globalList);
                forLoopType=2;
                fprintf(out, "for(assign(%s,%s); isLower(%s,%s); increase(%s,%s)){\n", tokenChars[2],expr1->name, tokenChars[2],expr2->name, tokenChars[2],expr3->name);
                fprintf(out, "for(assign(%s,%s); isLower(%s,%s); increase(%s,%s)){\n", tokenChars[4],expr4->name, tokenChars[4],expr5->name, tokenChars[5],expr6->name);
            } else {
                raiseError();
            }
        }
        else if(isArraysEqual(tokens, FOR_LOOP_END_TOKENS)){
            if(forLoopType==1){
                fprintf(out, "}\n");
            } else if(forLoopType==2){
                fprintf(out, "}}\n");
            } else{
                raiseError();
            }
            forLoopType=0;
        }
        
        else{
            if(len <= 0){
                continue;
            }
            int tempLeft = 0;
            if(tokens[0] == IDENTIFIER
            && (tokens[1] == ASSIGNMENT)
            && (tempLeft = expr(2, len - 1, false)) != -1
            ){
                tempLeft = parseExpression(2, len - 1);
                Variable* expr1 = evaluateList(&globalList);
                fprintf(out, "assign(%s, %s);\n", tokenChars[0], expr1->name);
            } else if(
            tokens[0] == IDENTIFIER
            && (tokens[1] == LEFT_BRACKET)
            && (tokens[2] == NUMBER)
            && (tokens[3] == RIGHT_BRACKET)
            && (tokens[4] == ASSIGNMENT)
            && (tempLeft = expr(5, len - 1, false)) != -1
            ){
                tempLeft = parseExpression(5, len - 1);
                Variable* expr1 = evaluateList(&globalList);
                fprintf(out, "assignToSingleIndex(%s, %s, %s);\n", tokenChars[0], tokenChars[3], expr1->name);
            } else if(
            tokens[0] == IDENTIFIER
            && (tokens[1] == LEFT_BRACKET)
            && (tokens[2] == NUMBER)
            && (tokens[3] == COMMA)
            && (tokens[4] == NUMBER)
            && (tokens[5] == RIGHT_BRACKET)
            && (tokens[6] == ASSIGNMENT)
            && (tempLeft = expr(7, len - 1, false)) != -1
            ){
                tempLeft = parseExpression(7, len - 1);
                Variable* expr1 = evaluateList(&globalList);
                fprintf(out, "assignToDoubleIndex(%s, %s, %s, %s);\n", tokenChars[0], tokenChars[3], tokenChars[5], expr1->name);
            } else {
                printf("Buradayken error veri expr assignment bulunamadi\n");
                printf("%s %d\n", line, len);
                raiseError();
            }
			// printf("UNKNOWN %d\n", len);
		}
		// printf("%s\n", line);

	}
	// Close file
	fclose(input_file);
    fclose(out);
	return 0;
}