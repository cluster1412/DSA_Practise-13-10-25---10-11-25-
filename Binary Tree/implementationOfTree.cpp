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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        int n = desc.size();
        unordered_map<int, TreeNode*> nodes;
        set<int> st;
        for(auto& it : desc){

            if(nodes.find(it[0])==nodes.end())
                nodes[it[0]] = new TreeNode(it[0]);
            if(nodes.find(it[1])==nodes.end())
                nodes[it[1]] = new TreeNode(it[1]);

            if(it[2]==1){
                nodes[it[0]]->left = nodes[it[1]];
            }
            else nodes[it[0]]->right = nodes[it[1]];
            st.insert(it[1]);
        }

        for(auto& it : nodes){
            if(st.find(it.first)==st.end()){
                return it.second;
            }
        }
        return NULL;
    }
};