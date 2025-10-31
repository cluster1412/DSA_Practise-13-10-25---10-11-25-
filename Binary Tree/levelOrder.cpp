#include<bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
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
    void lvl(TreeNode* root,vector<vector<int>>& res,int levl){
        if(root==NULL) return ;

        if(levl == res.size()) res.push_back({});
        res[levl].push_back(root->val);

        lvl(root->left,res,levl+1);
        lvl(root->right,res,levl+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        lvl(root,result,0);
        return result;
    }
};
