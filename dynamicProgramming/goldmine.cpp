#include<bits/stdc++.h>
using namespace std;

//memo
class Solution {
public:
    int n, m;

    int solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp) {
        if (i < 0 || i >= n || j >= m) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int a = solve(i-1, j+1, mat, dp);
        int b = solve(i, j+1, mat, dp);
        int c = solve(i+1, j+1, mat, dp);
        
        return dp[i][j] = mat[i][j] + max(a, max(b, c));
    }

    int maxGold(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, solve(i, 0, mat, dp));

        return ans;
    }
};

//tabulation
class Solution {
public:
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m));

        for (int i = 0; i < n; i++)
            dp[i][m-1] = mat[i][m-1];

        for (int j = m-2; j >= 0; j--)
            for (int i = 0; i < n; i++) {
                int a = (i-1 >= 0) ? dp[i-1][j+1] : 0;
                int b = dp[i][j+1];
                int c = (i+1 < n) ? dp[i+1][j+1] : 0;
                dp[i][j] = mat[i][j] + max(a, max(b, c));
            }

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, dp[i][0]);

        return ans;
    }
};
