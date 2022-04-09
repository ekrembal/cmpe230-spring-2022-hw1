#ifndef _enums_h
#define _enums_h

void raiseError(){
    printf("Error!\n");
    exit(1);
}
// enum VarType {
//     TYPE_MATRIX,
//     TYPE_VECTOR,
//     TYPE_SCALAR,
//     TYPE_OPERATION,
//     TYPE_NUMBER
// };

enum type{OP, NUM, MAT, VEC, SCA};

// Enum for all token types
enum token_type {
    START,
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
    TR, // tr
    EXPRESSION,
    LIST_OF_NUMBERS
};

#endif