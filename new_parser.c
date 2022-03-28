#include <stdio.h>

// Enum for all token types
enum token_type {
    IDENTIFIER, // <Identifier> starts with alpha or underscore and can contain numbers and underscores
    NUMBER, // <Number> starts with digit
    ASSIGNMENT, // =
    ADDITION, // +
    SUBTRACTION, // -
    MULTIPLICATION, // *
    LEFT_PARENTHESIS, // (
    RIGHT_PARENTHESIS, // )
    LEFT_BRACKET, // [
    RIGHT_BRACKET, // ]
    LEFT_BRACE, // {
    RIGHT_BRACE, // }
    COMMA, // ,
    FOR, // for
    PRINT, // print
    PRINTSEP, // printsep
    SCALAR, // scalar
    VECTOR, // vector
    MATRIX, // matrix
    UNKNOWN, // Unknown token
    IN, // in
    TWO_DOTS, // :
    END_OF_FILE, // EOF
    SQRT, // sqrt
    CHOOSE, // choose
    TR // tr
};



// States for parsing, used in the DFA, possible states are: START, KEYWORD, IDENTIFIER, 
enum parse_state{
    START,
}

void parse_line(char *line){
    int state = UNKNOWN;
    int i = 0;
    int len = strlen(line);
    for(i = 0; i < len; i++){
        switch(line[i]){
            case ' ':
        }
    }
}