#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) child[i] = nullptr;
        isEnd = false;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(string &w) {
        TrieNode* p = root;
        for (char c : w) {
            int id = c - 'a';
            if (!p->child[id]) p->child[id] = new TrieNode();
            p = p->child[id];
        }
        p->isEnd = true;
    }

    bool wordBreak(string s, vector<string>& dict) {
        for (auto &w : dict) insert(w);

        queue<int> q;
        q.push(0);
        vector<bool> vis(s.size(), false);

        while (!q.empty()) {
            int start = q.front();
            q.pop();
            if (vis[start]) continue;
            vis[start] = true;

            TrieNode* p = root;
            for (int i = start; i < s.size(); i++) {
                int id = s[i] - 'a';
                if (!p->child[id]) break;
                p = p->child[id];
                if (p->isEnd) {
                    if (i + 1 == s.size()) return true;
                    q.push(i + 1);
                }
            }
        }
        return false;
    }
};
