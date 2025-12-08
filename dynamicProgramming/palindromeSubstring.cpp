#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int l, int r, string &s, vector<vector<int>> &dp) {
        if (l >= r) return 1;
        if (dp[l][r] != -1) return dp[l][r];
        if (s[l] != s[r]) return dp[l][r] = 0;
        return dp[l][r] = solve(l+1, r-1, s, dp);
    }

    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = 0;

        for (int i = 0; i < n; i++) ans++;  
        for (int l = 0; l < n; l++)
            for (int r = l+1; r < n; r++)
                if (solve(l, r, s, dp)) ans++;

        return ans;
    }
};
