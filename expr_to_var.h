typedef struct Var {
    char *name;
    int row;
    int col;
    int token_type;
} Var;

char dict_str[1024][256];
Var dict_var[1024];
int dict_size = 0;

void addToDict(char *name, int type, int row = -1, int col = -1) {
    strcpy(dict_str[dict_size], name);
    dict_var[dict_size].name = dict[dict_size];
    dict_var[dict_size].token_type = type;
    dict_size++;
}

Var getVar(char *name) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(dict_str[i], name) == 0) {
            return dict_var[i];
        }
    }
    return NULL;
}