#ifndef _char_graph_h
#define _char_graph_h

#include <stdio.h>
#define MAX_CHAR_GRAPH_SIZE 256

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
    TR // tr
};

int lastNodeId = 0;
typedef struct ParserNode {
    int nodeId;
    struct ParserNode *edges[MAX_CHAR_GRAPH_SIZE];
    char edgeChars[MAX_CHAR_GRAPH_SIZE];
    int edgeCount;
    int tokenType;
    struct ParserNode *elseNode;
} ParserNode;

typedef struct ParserGraph {
    struct ParserNode *root;
} ParserGraph;

/**
 * @brief Depth-first search of the graph
 * @param graph The graph to search
 */
void dfs(ParserNode *node){
    ParserNode *next;

    for(int i = 0; i < node->edgeCount; i++){
        next = node->edges[i];
        printf("%d %d %c\n", node->nodeId, next->nodeId, node->edgeChars[i]);
        if(next->nodeId != node->nodeId){
            dfs(next);
        }
    }
}

/**
 * @brief Adds a new edge to the graph.
 * @param node The node to add the edge to.
 * @param child The child node to add.
 * @param edgeChar The character that represents the edge.
 */
void addEdge(ParserNode *node, ParserNode *child, char edgeChar){
    node->edges[node->edgeCount] = child;
    node->edgeChars[node->edgeCount] = edgeChar;
    node->edgeCount++;
}

/**
 * @brief Adds multiple edges to the graph.
 * @param node The node to add the edges to.
 * @param children The children nodes to add.
 * @param edgeCharsStart The start of the edge characters.
 * @param edgeCharsEnd The end of the edge characters.
 * 
 */
void addEdges(ParserNode *node, ParserNode *children, char edgeCharsStart, char edgeCharsEnd){
    for(int i = edgeCharsStart; i <= edgeCharsEnd; i++){
        addEdge(node, children, i);
    }
}

/**
 * @brief creates a new node for the graph
 * @param tokenType the token type of the node
 */
ParserNode *createNode(int tokenType) {
    ParserNode *node = (ParserNode *)malloc(sizeof(ParserNode));
    node->tokenType = tokenType;
    node->edgeCount = 0;
    node->nodeId = lastNodeId;
    lastNodeId++;
    return node;
}

/**
 * @brief Generates a new ParserGraph
 * 
 */
ParserGraph *createParserGraph() {
    ParserGraph *graph = (ParserGraph*)malloc(sizeof(ParserGraph));
    graph->root = createNode(START);

    ParserNode *numberNode = createNode(NUMBER);
    addEdges(graph->root, numberNode, '0', '9');
    addEdges(numberNode, numberNode, '0', '9');
    ParserNode *dotNode = createNode(NUMBER);
    addEdge(numberNode, dotNode, '.');
    ParserNode *decimalNumberNode = createNode(NUMBER);
    addEdges(dotNode, decimalNumberNode, '0', '9');
    addEdges(decimalNumberNode, decimalNumberNode, '0', '9');


    ParserNode *identifierNode = createNode(IDENTIFIER);
    addEdges(graph->root, identifierNode, 'a', 'z');
    addEdges(graph->root, identifierNode, 'A', 'Z');
    addEdge(graph->root, identifierNode, '_');
    addEdges(identifierNode, identifierNode, 'a', 'z');
    addEdges(identifierNode, identifierNode, 'A', 'Z');
    addEdges(identifierNode, identifierNode, '0', '9');
    addEdge(identifierNode, identifierNode, '_');

    ParserNode *assignmentNode = createNode(ASSIGNMENT);
    addEdge(graph->root, assignmentNode, '=');

    ParserNode *additionNode = createNode(ADDITION);
    addEdge(graph->root, additionNode, '+');

    ParserNode *subtractionNode = createNode(SUBTRACTION);
    addEdge(graph->root, subtractionNode, '-');

    ParserNode *multiplicationNode = createNode(MULTIPLICATION);
    addEdge(graph->root, multiplicationNode, '*');

    ParserNode *leftParenthesisNode = createNode(LEFT_PARENTHESIS);
    addEdge(graph->root, leftParenthesisNode, '(');

    ParserNode *rightParenthesisNode = createNode(RIGHT_PARENTHESIS);
    addEdge(graph->root, rightParenthesisNode, ')');

    ParserNode *leftBracketNode = createNode(LEFT_BRACKET);
    addEdge(graph->root, leftBracketNode, '[');

    ParserNode *rightBracketNode = createNode(RIGHT_BRACKET);
    addEdge(graph->root, rightBracketNode, ']');

    ParserNode *leftBraceNode = createNode(LEFT_BRACE);
    addEdge(graph->root, leftBraceNode, '{');

    ParserNode *rightBraceNode = createNode(RIGHT_BRACE);
    addEdge(graph->root, rightBraceNode, '}');

    ParserNode *commaNode = createNode(COMMA);
    addEdge(graph->root, commaNode, ',');

    ParserNode *twoDotsNode = createNode(TWO_DOTS);
    addEdge(graph->root, twoDotsNode, ':');

    // addKeyword(graph->root, "for", FOR, identifierNode);
    // addKeyword(graph->root, "print", PRINT, identifierNode);
    // addKeyword(graph->root, "printsep", PRINTSEP, identifierNode);
    // addKeyword(graph->root, "scalar", SCALAR, identifierNode);
    // addKeyword(graph->root, "vector", VECTOR, identifierNode);
    // addKeyword(graph->root, "matrix", MATRIX, identifierNode);
    // addKeyword(graph->root, "in", IN, identifierNode);
    // addKeyword(graph->root, "sqrt", SQRT, identifierNode);
    // addKeyword(graph->root, "choose", CHOOSE, identifierNode);
    // addKeyword(graph->root, "tr", TR, identifierNode);

    return graph;
}

#endif
