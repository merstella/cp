#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 128

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
} TrieNode;

TrieNode* getNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

void insert(TrieNode* root, char* key) {
    TrieNode* node = root;
    for (int i = 0; i < strlen(key); i++) {
        int index = key[i];
        if (!node->children[index])
            node->children[index] = getNode();
        node = node->children[index];
    }
    node->isEndOfWord = 1;
}

int search(TrieNode* root, char* key) {
    TrieNode* node = root;
    for (int i = 0; i < strlen(key); i++) {
        int index = key[i];
        if (!node->children[index])
            return 0;
        node = node->children[index];
    }
    
    return (node != NULL && node->isEndOfWord);
}

int main() {
    char key[51];
    TrieNode* root = getNode();

    while (scanf("%s", key) && strcmp(key, "*")) {
        insert(root, key);
    }

    while (scanf("%s", key) && strcmp(key, "***")) {
        if (strstr(key, "find")) {
            scanf("%s", key);
            printf("%d\n", search(root, key));
        } else if (strstr(key, "insert")) {
            scanf("%s", key);
            int found = search(root, key);
            if (!found) {
                insert(root, key);
            }
            printf("%d\n", !found);
        }
    }

    return 0;
}
