#include <stdio.h>





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