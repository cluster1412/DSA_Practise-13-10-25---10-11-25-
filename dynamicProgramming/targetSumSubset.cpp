#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int sum, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (i == nums.size()) return sum == target;
        int offset = 2000;
        if (dp[i][sum + offset] != -1) return dp[i][sum + offset];
        int plus = solve(i+1, sum + nums[i], nums, target, dp);
        int minus = solve(i+1, sum - nums[i], nums, target, dp);
        return dp[i][sum + offset] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(4001, -1));
        return solve(0, 0, nums, target, dp);
    }
};
