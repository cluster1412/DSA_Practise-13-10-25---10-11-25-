#include<bits/stdc++.h>
using namespace std;

//memo
class Solution {
public:
    int solve(int i, vector<int> &nums, vector<int> &dp) {
        if (i >= nums.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int take = nums[i] + solve(i+2, nums, dp);
        int skip = solve(i+1, nums, dp);
        return dp[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp);
    }
};

//tabulation

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        return dp[n-1];
    }
};
