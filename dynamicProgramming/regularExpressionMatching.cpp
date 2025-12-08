#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if (j == p.size()) return i == s.size();
        if (dp[i][j] != -1) return dp[i][j];

        bool first = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < p.size() && p[j+1] == '*') {
            if (solve(i, j+2, s, p, dp)) return dp[i][j] = 1;
            if (first && solve(i+1, j, s, p, dp)) return dp[i][j] = 1;
            return dp[i][j] = 0;
        }

        if (first) return dp[i][j] = solve(i+1, j+1, s, p, dp);

        return dp[i][j] = 0;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        return solve(0, 0, s, p, dp);
    }
};
