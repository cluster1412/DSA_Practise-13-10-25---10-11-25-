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
    bool checkPathSum(TreeNode* root, int t){
        if(root==nullptr) return 0;
        int diff = t - root->val;
        if(diff==0 && !root->left && !root->right) return 1;
        bool a = checkPathSum(root->left,diff);
        bool b = checkPathSum(root->right,diff);
        
        return a||b ;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return checkPathSum(root,targetSum);
    }
};