#include<bits/stdc++.h>
using namespace std;


class TrieNode {
public:
    TrieNode* children[26];
    bool isLeaf;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        isLeaf = false;
    }
};


class Solution {
  public:
    int dfs(TrieNode* root) {
        if (!root) return 0;
        
        int cnt = root->isLeaf ? 1 : 0;
        
        for (int i = 0; i < 26; i++)
            cnt += dfs(root->children[i]);
        
        return cnt;
    }
    int wordCount(TrieNode* root) {
        return dfs(root);
    }
};
