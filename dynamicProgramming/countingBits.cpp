#include<bits/stdc++.h>
using namespace std;

//memo
class Solution {
public:
    int solve(int n, vector<int> &dp) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];
        return dp[n] = solve(n >> 1, dp) + (n & 1);
    }

    vector<int> countBits(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
            solve(i, dp);
        return dp;
    }
};

//tabulation
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        for (int i = 1; i <= n; i++)
            dp[i] = dp[i >> 1] + (i & 1);
        return dp;
    }
};
