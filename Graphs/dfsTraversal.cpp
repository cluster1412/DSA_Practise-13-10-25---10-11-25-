#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfsTraversal(vector<vector<int>>& adj,vector<int>& ans,unordered_map<int,bool>& vis,int i){
        
        vis[i] = true;
        ans.push_back(i);
        for(int nei : adj[i]){
            if(!vis[nei]){
                dfsTraversal(adj,ans,vis,nei);
            }
        }
        
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> ans;
        unordered_map<int,bool> vis;
        dfsTraversal(adj,ans,vis,0);
        return ans;
    }
};