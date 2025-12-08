#include<bits/stdc++.h>
using namespace std;

struct trie_node
{
    int value; // non zero if leaf
    trie_node_t *children[ALPHABET_SIZE];
};
class Solution {
  public:
    bool deleteUtil(trie_node_t* root, char key[], int depth, int n) {

        if (!root) return false;

        if (depth == n) {
            root->value = 0;   

            for (int i = 0; i < ALPHABET_SIZE; i++)
                if (root->children[i] != nullptr)
                    return false;

            return true; 
        }

        int idx = key[depth] - 'a';
        trie_node_t* child = root->children[idx];

        if (!child) return false;  

        bool shouldDelete = deleteUtil(child, key, depth + 1, n);

        if (shouldDelete) {
            delete child;
            root->children[idx] = nullptr;

            if (root->value != 0)
                return false;

            for (int i = 0; i < ALPHABET_SIZE; i++)
                if (root->children[i] != nullptr)
                    return false;

            return true;
        }

        return false;
    }

    void deleteKey(trie_node_t *root, char key[]) {
        // Code here
        int n = strlen(key);
        deleteUtil(root, key, 0, n);
        
    }
};