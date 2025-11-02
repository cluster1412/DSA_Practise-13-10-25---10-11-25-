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
    void sumOfLeaves(TreeNode* root,int& ans,int l){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL && l){
            ans += root->val;
            return;
        }
        sumOfLeaves(root->left,ans,1);
        sumOfLeaves(root->right,ans,0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        sumOfLeaves(root,ans,0);
        return ans;
    }
};