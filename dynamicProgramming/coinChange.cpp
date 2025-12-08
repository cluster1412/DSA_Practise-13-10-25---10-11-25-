#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 1e9);
        dp[0] = 0;

        for (int c : coins)
            for (int a = c; a <= amount; a++)
                dp[a] = min(dp[a], dp[a-c] + 1);

        return dp[amount] >= 1e9 ? -1 : dp[amount];
    }
};
