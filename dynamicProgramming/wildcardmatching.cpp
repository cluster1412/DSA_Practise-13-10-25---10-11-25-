#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if (i == s.size() && j == p.size()) return 1;
        if (j == p.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (p[j] == '*') {
            if (i < s.size() && solve(i+1, j, s, p, dp)) return dp[i][j] = 1;
            return dp[i][j] = solve(i, j+1, s, p, dp);
        }

        if (i < s.size() && (s[i] == p[j] || p[j] == '?'))
            return dp[i][j] = solve(i+1, j+1, s, p, dp);

        return dp[i][j] = 0;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        return solve(0, 0, s, p, dp);
    }
};
