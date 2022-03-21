#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

char allowedCharacters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_[],{}():*+-.#=";
bool isAllowdCharacter[256];

bool startsWith(const char *pre, const char *str)
{
    return strncmp(pre, str, strlen(pre)) == 0;
}


bool isAllowedCharacter(char c) {
	return isAllowdCharacter[(int)c];
}

void stripLeft(char *str) {
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r' && str[i] != '\v' && str[i] != '\f')
			str++;
	}
	// strcpy(str, str + i);
}

void formatString(char *str)
{
	int i;
	int len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if(!isAllowedCharacter(str[i]))
		{
			str[i] = ' ';
		}
		if (str[i] == '#')
		{
			str[i] = '\0';
			break;
		}
	}
	stripLeft(str);
}

int main(int argc, char *argv[])
{
	//test stripLeft
	char* of = "  asdfghj";
	stripLeft(of);
	printf("NEW STRING IS ###%s\n", of);
	// printf("%d",(int)startsWith("hela", "hellooooo"));
	int i;
	for (i = 0; i < 256; i++)
	{
		isAllowdCharacter[i] = false;
	}
	for (i = 0; i < strlen(allowedCharacters); i++)
	{
		isAllowdCharacter[allowedCharacters[i]] = true;
	}
	// Get the input file name
	char *input_file_name = argv[1];
	printf("input filename is %s\n", input_file_name);
	// Open file
	FILE *input_file = fopen(input_file_name, "r");
	if (input_file == NULL)
	{
		printf("Error opening file\n");
		return 1;
	}
	// Read file line by line
	char line[256];
	while (fgets(line, sizeof(line), input_file) != NULL)
	{
		formatString(line);
		if(startsWith("scalar", line)){
			printf("Creating a scalar\n");
			// strcpy(line, line + strlen("scalar"));
			// stripLeft(line);
			// printf("%s\n", line);
			// Erase scalar from line

		} else if(startsWith("vector", line)){
			printf("Creating a vector\n");
		} else if(startsWith("matrix", line)){
			printf("Creating a matrix\n");
		} else if(startsWith("printsep", line)){
			printf("Printing a separator\n");
		} else if(startsWith("print", line)){
			printf("Print is called\n");
		} else if(startsWith("for", line)){
			printf("For loop is called\n");
		} else if(startsWith("}", line)){
			printf("End of a block\n");
		} else if(strlen(line) > 0){
			printf("This is an assignment\n");
		} else{
			printf("Empty line\n");
		}
		printf("%s\n", line);
	}
	// Close file
	fclose(input_file);
	return 0;
}
