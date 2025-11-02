#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    bool isHeap(Node* tree) {
        if(tree==NULL) return true;
        
        queue<Node*> q;
        q.push(tree);
        bool nullChildSeen = false;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->left) {
                if (nullChildSeen || curr->data < curr->left->data)
                    return false;
                q.push(curr->left);
            } else {
                nullChildSeen = true; 
            }
            
            if (curr->right) {
                if (nullChildSeen || curr->data < curr->right->data)
                    return false;
                q.push(curr->right);
            } else {
                nullChildSeen = true; 
            }
        }
        return true;
    }
};