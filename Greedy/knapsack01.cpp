#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(int w,vector<int> &val, vector<int> &wt,vector<vector<int>>& dp,int i){
        if(i>=wt.size()){
            return 0;
        }
        if(dp[i][w]!=-1){
            return dp[i][w];
        }
        int take=0;
        if(w >= wt[i])
            take = val[i] + solve(w-wt[i],val,wt,dp,i+1);
        
        int ntake = solve(w,val,wt,dp,i+1);
        
        return dp[i][w] = max(take,ntake);
        
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return solve(W,val,wt,dp,0);
    }
};