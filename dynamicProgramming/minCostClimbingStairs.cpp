#include<bits/stdc++.h>
using namespace std;

//memoization
class Solution {
public:
    int solve(int i, vector<int> &cost, vector<int> &dp) {
        if (i >= cost.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int one = cost[i] + solve(i+1, cost, dp);
        int two = cost[i] + solve(i+2, cost, dp);
        return dp[i] = min(one, two);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(solve(0, cost, dp), solve(1, cost, dp));
    }
};

//tabulation
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1);
        dp[0] = dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            int one = dp[i-1] + cost[i-1];
            int two = dp[i-2] + cost[i-2];
            dp[i] = min(one, two);
        }
        return dp[n];
    }
};
