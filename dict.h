struct Dict{
    int size;
    int capacity;
    int *keys;
    int *values;
};

void addToDict(struct Dict* dict, int key, int value){
    if(dict->size == dict->capacity){
        dict->capacity *= 2;
        dict->keys = (int*)realloc(dict->keys, sizeof(int) * dict->capacity);
        dict->values = (int*)realloc(dict->values, sizeof(int) * dict->capacity);
    }
    dict->keys[dict->size] = key;
    dict->values[dict->size] = value;
    dict->size++;
}

