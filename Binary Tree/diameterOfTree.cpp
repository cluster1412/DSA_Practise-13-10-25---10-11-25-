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

    int findDiameter(TreeNode* root,int& max_ans){
        if(root==NULL) return 0;

        int l = findDiameter(root->left,max_ans);
        int r = findDiameter(root->right,max_ans);

        max_ans = max(l+r,max_ans);

        return max(l,r)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter = 0;
        findDiameter(root,max_diameter);
        return max_diameter;
    }
};