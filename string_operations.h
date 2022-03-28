#ifndef _string_operations_h
#define _string_operations_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool isVariableChar(char c) {
    if(c >= 'a' && c <= 'z')
        return true;
    if(c >= 'A' && c <= 'Z')
        return true;
    if(c >= '0' && c <= '9')
        return true;
    if(c == '_')
        return true;
    return false;
}

bool isAllowedCharacter(char c) {
    if(c >= 'a' && c <= 'z')
        return true;
    if(c >= 'A' && c <= 'Z')
        return true;
    if(c >= '0' && c <= '9')
        return true;
    switch(c) {
        case '_':
        case '[':
        case ']':
        case ',':
        case '{':
        case '}':
        case '(':
        case ')':
        case ':':
        case '*':
        case '+':
        case '-':
        case '.':
        case '#':
        case '=':
            return true;
    }
    return false;
}

bool isWhiteSpace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f');
}

typedef struct stringPair {
    char* first;
    char* second;
} stringPair;

char *stripLeft(char *str) {
    while(isWhiteSpace(str[0]))
        str++;
    return str;
}

void stripLeftInplace(char *str) {
	int i = 0;
	while (isWhiteSpace(str[i]))
		i++;
	for(int j = i; str[j] != '\0'; j++) {
		str[j - i] = str[j];
	}
	str[strlen(str) - i] = '\0';
}

bool startsWith(const char *pre, const char *str)
{
    return strncmp(pre, str, strlen(pre)) == 0;
}

stringPair split(char *str, char delimiter) {
    stringPair result;
    result.first = NULL;
    result.second = str;
    int i = 0;
    while(result.second[0] != '\0') {
        // printf("%c\n", result.second[0]);
        if(result.second[0] == delimiter) {
            result.first = (char*)malloc(sizeof(char) * i);
            int j = 0;
            while(j < i) {
                result.first[j] = str[j];
                j++;
            }
            result.first[j] = '\0';
            result.second++;
            break;
        }
        i++;
        result.second++;
    }
    return result;
}

int findIndex(char *str, char delimiter) {
    int i = 0;
    while(str[i] != '\0') {
        if(str[i] == delimiter)
            return i;
        i++;
    }
    return -1;
}


char *getStringBetween(char *str, char start, char end) {
    int i = 0;
    while(str[i] != '\0') {
        if(str[i] == start) {
            i++;
            break;
        }
        i++;
    }
    int j = 0;
    while(str[i+j] != '\0') {
        if(str[i+j] == end) {
            break;
        }
        j++;
    }
    char *result = (char*)malloc(sizeof(char) * (j + 1));
    int k = 0;
    while(k < j) {
        result[k] = str[i];
        i++;
        k++;
    }
    result[k] = '\0';
    return result;
}

char *parseGetIndex(char *str){
    int foundIndex = -1;
    int len = strlen(str);
    if((foundIndex = findIndex(str, '[')) != -1){
        // printf("Found [ in %d\n", foundIndex);
        int newStringLen = strlen(str) + 1 + strlen("getIndex");
        char *newString = (char*)malloc(sizeof(char) * (newStringLen + 1));
        int i = foundIndex - 1;
        while(i >= 0 && isVariableChar(str[i])) 
            i--;
        i++;
        // copy first i index to newString
        for(int j = 0; j < i; j++)
            newString[j] = str[j];
        // copy getIndex to newString
        for(int j = 0; j < strlen("getIndex("); j++)
            newString[i + j] = "getIndex("[j];
        //copy variable name to newString
        for(int j = i; j < foundIndex; j++)
            newString[i + strlen("getIndex(") + j - i] = str[j];
        newString[i + (int)strlen("getIndex(") + (foundIndex) - i] = ',';

        // printf("Last edited index is %d\n", i + (int)strlen("getIndex(") + (foundIndex) - i);
        // copy rest of string to newString
        bool isAlreadyClosed = false;
        for(int j = foundIndex + 1; j < len; j++){
            // printf("%d\n",(int)strlen("getIndex(") + j);
            // printf("%c\n", str[j]);
            if((!isAlreadyClosed) && str[j] == ']'){
                // printf("Closed at %d\n", j);
                isAlreadyClosed = true;
                newString[strlen("getIndex(") + j] = ')';
                continue;
            }
            newString[strlen("getIndex(") + j] = str[j];
        }
        newString[newStringLen] = '\0';
        // for(int j = i; j < foundIndex; j++)
        //     printf("%c", str[j]);
        // printf("\n");
        // printf("i = %d\n", i);
        // printf("%s\n", newString);
        return parseGetIndex(newString);
    }
    return str;
}



int findExpressionLength(char *str){
    //This function finds the length of the expression recursiveley
    //It returns the length of the expression

    if(str[0] == '\0')
        return 0;
    int result = 0;
    stringPair expressionPair = split(str, '*');
    if(expressionPair.first != NULL){
        result += strlen("multiply(");
        result += findExpressionLength(expressionPair.first);
        result += strlen(",");
        result += findExpressionLength(expressionPair.second);
        result += strlen(")");
        return result;
    }
    expressionPair = split(str, '+');
    if(expressionPair.first != NULL){
        result += strlen("add(");
        result += findExpressionLength(expressionPair.first);
        result += strlen(",");
        result += findExpressionLength(expressionPair.second);
        result += strlen(")");
        return result;
    }
    expressionPair = split(str, '-');
    if(expressionPair.first != NULL){
        result += strlen("subtract(");
        result += findExpressionLength(expressionPair.first);
        result += strlen(",");
        result += findExpressionLength(expressionPair.second);
        result += strlen(")");
        return result;
    }
    return strlen(parseGetIndex(str));
}


char *parseExpression(char *str){
    //This function recursively parses expression from * + -
    //It returns the result of the expression
    char *result = (char*)malloc(sizeof(char) * findExpressionLength(str));
    stringPair expressionPair = split(str, '*');
    if(expressionPair.first != NULL){
        strcpy(result, "multiply(");
        strcat(result, parseExpression(expressionPair.first));
        strcat(result, ",");
        strcat(result, parseExpression(expressionPair.second));
        strcat(result, ")");
        return result;
    }
    expressionPair = split(str, '+');
    if(expressionPair.first != NULL){
        strcpy(result, "add(");
        strcat(result, parseExpression(expressionPair.first));
        strcat(result, ",");
        strcat(result, parseExpression(expressionPair.second));
        strcat(result, ")");
        return result;
    }
    expressionPair = split(str, '-');
    if(expressionPair.first != NULL){
        strcpy(result, "subtract(");
        strcat(result, parseExpression(expressionPair.first));
        strcat(result, ",");
        strcat(result, parseExpression(expressionPair.second));
        strcat(result, ")");
        return result;
    }
    strcpy(result, parseGetIndex(str));
    return result;
}



char *parseAssignment(char *str) {
    stringPair result = split(str, '=');
    char * resultt = (char*)malloc(sizeof(char) * (strlen("assign(") + strlen(result.first) + strlen(",") + findExpressionLength(result.second) + strlen(");")));
    strcpy(resultt, "assign(");
    strcat(resultt, result.first);
    strcat(resultt, ",");
    strcat(resultt, parseExpression(result.second));
    strcat(resultt, ");");
    return resultt;
}

// char *removeConsecu



#endif