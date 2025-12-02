#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,list<int>> adj;
        if(source == destination) return true;
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        unordered_map<int,bool> vis;
        q.push(source);
        vis[source]=true;

        while(!q.empty()){
            int f = q.front();
            q.pop();

            for(int nei:adj[f]){
                if(nei==destination) return true;
                if(!vis[nei]){
                    vis[nei] = true;
                    q.push(nei);
                }
            }
        }
        return false;
    }
};