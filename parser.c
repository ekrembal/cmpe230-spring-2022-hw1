#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#include "string_operations.h"




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
	stripLeftInplace(str);
}

int main(int argc, char *argv[])
{
	// Get the input file name
	char *input_file_name = argv[1];
	char *output_file_name = "file.c";
	printf("input filename is %s\n", input_file_name);
	printf("output filename is %s\n", output_file_name);
	// Open file
	FILE *input_file = fopen(input_file_name, "r");
	if (input_file == NULL)
	{
		printf("Error opening file\n");
		return 1;
	}
	// Read file line by line
	char line[1024];
	while (fgets(line, sizeof(line), input_file) != NULL)
	{
		// printf("%s", line);
		formatString(line);

		// printf("%s\n", line);
		if(startsWith("scalar", line)){
			// printf("Creating a scalar\n");
			// print("struct variable " + line + " = createScalar();\n");
			// strcpy(line, line + strlen("scalar"));
			// stripLeft(line);
			// printf("%s\n", line);
			// Erase scalar from line
			printf("scalar %s", line + strlen("scalar"));
			printf("= createScalar();\n");


		} else if(startsWith("vector", line)){

			char *vector_name = line + strlen("vector");
			char *vector_size = getStringBetween(vector_name, '[', ']');
			stripLeft(vector_name);
			int firstOpeningIndex = findIndex(vector_name, '[');
			vector_name[firstOpeningIndex] = '\0';

			printf("vector %s = createVector(%s);\n", vector_name, vector_size);
		} else if(startsWith("matrix", line)){
			char *vector_name = line + strlen("vector");
			char *vector_size = getStringBetween(vector_name, '[', ']');
			stripLeft(vector_name);
			int firstOpeningIndex = findIndex(vector_name, '[');
			vector_name[firstOpeningIndex] = '\0';

			printf("matrix %s = createMatrix(%s);\n", vector_name, vector_size);
		} else if(startsWith("printsep", line)){
			printf("printsep();\n");
		} else if(startsWith("print", line)){
			// printf("%s\n", line);
			printf("%s;\n", parseExpression(line));
		} else if(startsWith("for", line)){
			// printf("For loop is called\n");
			printf("%s\n", line);
		} else if(startsWith("}", line)){
			printf("}\n");
		} else if(strlen(line) > 0){
			// printf("This is an assignment\n");
			
		// printf("%s\n", line);
			printf("%s\n", parseAssignment(line));
		} else{
			printf("\n");
		}
		// printf("%s\n", line);
	}
	// Close file
	fclose(input_file);
	return 0;
}
