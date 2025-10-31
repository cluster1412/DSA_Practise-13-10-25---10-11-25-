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
public:

    bool check(TreeNode* l,TreeNode* r){
        if(l == NULL && r == NULL) return true;
        if(l == NULL && r != NULL) return false;
        if(l != NULL && r == NULL) return false;
        if(l->val != r->val) return false;
        bool isleft = check(l->left,r->right);
        bool isright = check(l->right,r->left);

        if(isleft==true && isright==true && l->val == r->val) return true;
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return check(root->left,root->right);
    }
};