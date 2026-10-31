class Solution {
    int m, n, MOD = 1e9 + 7, LEFT, UP;

    int fun(auto& grid, int i, int j, int flag, auto& dp) {
        if(i >= m || j >= n) return 0;
        if(i == m - 1 and j == n - 1) return 1;

        if(dp[i][j][flag] != -1) return dp[i][j][flag];

        if(grid[i][j]) {
            if(flag) {
                return dp[i][j][flag] = fun(grid, i , j + 1, 0, dp);
            } else {
                return dp[i][j][flag] = fun(grid, i + 1, j, 1, dp);
            }
        }
        int ans = 0;
        ans = (ans + fun(grid, i + 1, j, UP, dp)) % MOD;
        ans = (ans + fun(grid, i, j + 1, LEFT, dp)) % MOD;

        return dp[i][j][flag] = ans;
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        LEFT = 0; UP = 1;
        vector<vector<vector<int>>>dp(m + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        return fun(grid, 0 , 0, LEFT, dp);
    }
};