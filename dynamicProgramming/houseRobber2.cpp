#include<bits/stdc++.h>
using namespace std;

//memo
class Solution {
public:
    int solve(int i, int end, vector<int> &nums, vector<int> &dp) {
        if (i > end) return 0;
        if (dp[i] != -1) return dp[i];
        int take = nums[i] + solve(i+2, end, nums, dp);
        int skip = solve(i+1, end, nums, dp);
        return dp[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp1(n, -1), dp2(n, -1);

        int case1 = solve(0, n-2, nums, dp1);
        int case2 = solve(1, n-1, nums, dp2);

        return max(case1, case2);
    }
};

//tabulation

class Solution {
public:
    int robLine(vector<int> &nums, int l, int r) {
        int n = r - l + 1;
        if (n == 1) return nums[l];
        
        vector<int> dp(n);
        dp[0] = nums[l];
        dp[1] = max(nums[l], nums[l+1]);

        for (int i = 2; i < n; i++)
            dp[i] = max(dp[i-1], nums[l+i] + dp[i-2]);

        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int case1 = robLine(nums, 0, n-2);
        int case2 = robLine(nums, 1, n-1);

        return max(case1, case2);
    }
};
