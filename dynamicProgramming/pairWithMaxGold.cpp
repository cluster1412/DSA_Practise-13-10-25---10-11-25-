#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int n, m;

    int dfs(vector<vector<int>>& g, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || g[i][j] == 0) return 0;

        int val = g[i][j];
        g[i][j] = 0;

        int up = dfs(g, i-1, j);
        int down = dfs(g, i+1, j);
        int left = dfs(g, i, j-1);
        int right = dfs(g, i, j+1);

        g[i][j] = val;
        return val + max(max(up, down), max(left, right));
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] > 0)
                    ans = max(ans, dfs(grid, i, j));
        return ans;
    }
};
