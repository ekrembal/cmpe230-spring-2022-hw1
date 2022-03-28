#ifndef _trie_h
#define _trie_h


struct TrieNode {
    struct TrieNode *children[26];
    bool isEndOfWord;
};

struct Trie{
    struct TrieNode *root;
};


#endif