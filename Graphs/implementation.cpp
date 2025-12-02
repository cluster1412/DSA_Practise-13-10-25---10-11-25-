#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(V);
        
        for(auto edge:edges){
            int u = edge.first;
            int v = edge.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return adj;
    }
};