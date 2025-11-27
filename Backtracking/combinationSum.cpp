#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int> &res,vector<int>& can,int t,int idx){
        if(t==0){
            ans.push_back(res);
            return;
        }
        for(int i = idx ; i < can.size() ; i++){
            if(t >= can[i]){
                res.push_back(can[i]);
                solve(ans,res,can,t-can[i],i);
                res.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& can, int t) {
        sort(can.begin(),can.end());
        vector<vector<int>> ans;
        vector<int> res;
        solve(ans,res,can,t,0);
        return ans;
    }
};