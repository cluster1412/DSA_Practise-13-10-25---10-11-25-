#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfsTraversal(vector<vector<int>>& adj,unordered_map<int,bool>& vis,int i){
        vis[i] = true;
        for(int nei : adj[i]){
            if(!vis[nei]){
                dfsTraversal(adj,vis,nei);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        unordered_map<int,bool> vis;
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                dfsTraversal(adj,vis,i);
                cnt++;
            }
        }
        return cnt;
    }
};
