#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findPath(vector<vector<int>>& graph,vector<int>& path,vector<vector<int>>& ans,
        int n,int i){

        path.push_back(i);
        if(i==n){
            ans.push_back(path);
            path.pop_back();
            return;
        }

        for(int nei : graph[i]){
            findPath(graph,path,ans,n,nei);
        }

        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> path;
        vector<vector<int>> ans;
        findPath(graph,path,ans,n-1,0);
        return ans;
    }
};