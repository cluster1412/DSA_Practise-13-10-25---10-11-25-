#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void count(TreeNode* root,int& c,int m){
        if(root==NULL){
            return;
        }
        m++;
        count(root->left,c,m);
        if(m > c) c = m;
        count(root->right,c,m);
        if(m > c) c = m;
    }
public:
    int maxDepth(TreeNode* root) {
        int c = 0;
        count(root,c,0);
        return c;
    }
};