#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int k, int n, vector<vector<int>>& dp) {
        if (n == 0 || n == 1) return n;
        if (k == 1) return n;
        if (dp[k][n] != -1) return dp[k][n];

        int l = 1, r = n, ans = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            int broken = solve(k - 1, mid - 1, dp);
            int notBroken = solve(k, n - mid, dp);

            int worst = 1 + max(broken, notBroken);
            ans = min(ans, worst);

            if (broken < notBroken) l = mid + 1;
            else r = mid - 1;
        }
        return dp[k][n] = ans;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return solve(k, n, dp);
    }
};
