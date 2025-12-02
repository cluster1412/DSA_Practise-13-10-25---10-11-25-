#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(unordered_map<int,list<int>>& adj, unordered_map<int,bool>& vis,int i){
        vis[i]=true;
        for(auto nei : adj[i]){
            if(!vis[nei]){
                dfs(adj,vis,nei);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,list<int>> adj;
        int n = isConnected.size() ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == j) continue;
                if(isConnected[i][j] == 1)
                adj[i+1].push_back(j+1);
            }
        }
        unordered_map<int,bool> vis;
        int cnt = 0;
        for(int i = 1 ; i <= n ; i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                cnt++;
            }
        }
        return cnt;
    }
};