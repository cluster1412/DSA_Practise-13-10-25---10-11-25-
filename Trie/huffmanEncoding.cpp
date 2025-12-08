#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node {
        int freq;
        char ch;
        Node *left, *right;
        Node(char c, int f) {
            ch = c;
            freq = f;
            left = right = nullptr;
        }
        Node(int f, Node* l, Node* r) {
            ch = '$';
            freq = f;
            left = l;
            right = r;
        }
    };

    struct cmp {
        bool operator()(Node* a, Node* b) {
            return a->freq > b->freq;
        }
    };

    void preorder(Node* root, string cur, vector<string> &ans) {
        if (!root) return;
        if (!root->left && !root->right) {
            ans.push_back(cur);
            return;
        }
        preorder(root->left, cur + "0", ans);
        preorder(root->right, cur + "1", ans);
    }
    
    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        priority_queue<Node*, vector<Node*>, cmp> pq;
        for (int i = 0; i < N; i++) {
            pq.push(new Node(S[i], f[i]));
        }
        while (pq.size() > 1) {
            Node* l = pq.top(); pq.pop();
            Node* r = pq.top(); pq.pop();
            Node* parent = new Node(l->freq + r->freq, l, r);
            pq.push(parent);
        }
        vector<string> ans;
        preorder(pq.top(), "", ans);
        return ans;
    }
};