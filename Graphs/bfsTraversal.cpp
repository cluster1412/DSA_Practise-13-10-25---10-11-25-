#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        
        vector<int> ans;
        unordered_map<int,bool> vis;
        queue<int> q;
        q.push(0);
        ans.push_back(0);
        vis[0]=true;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(int nei : adj[front]){
                if(!vis[nei]){
                    q.push(nei);
                    ans.push_back(nei);
                    vis[nei] = true;
                }
            }
        }
        
        return ans;
    }
};