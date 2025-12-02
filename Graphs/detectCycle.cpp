#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfsTraversal(unordered_map<int,list<int>>& adj,unordered_map<int,bool>& vis,int i){
        
        vis[i] = true;
        for(int nei : adj[i]){
            if(vis[nei] == true) return true;
            if(!vis[nei]){
                if(dfsTraversal(adj,vis,nei)) return true;
            }
        }
        
        vis[i]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        unordered_map<int,list<int>> adj;
        
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }
        
        unordered_map<int,bool> vis;
        
        for(int i = 0 ; i < V ; i++){
            
            if(!vis[i]) if (dfsTraversal(adj,vis,i)) return true;
        }
        
        return false;
    }
};