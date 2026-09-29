class Solution {
    int dp[101][101][204];

    bool fun(int r, int c, vector<vector<int>>& a, int sum) {
        if (r < 0 || c < 0)
            return false;

        int ns = sum + a[r][c];

        
        if (ns > 0 || ns < -101)
            return false;

        if (r == 0 && c == 0)
            return ns == 0;

        if (dp[r][c][sum + 101] != -1)
            return dp[r][c][sum + 101];

        return dp[r][c][sum + 101] =
            fun(r, c - 1, a, ns) ||
            fun(r - 1, c, a, ns);
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if ((n + m - 1) % 2 == 1) return false; 

        vector<vector<int>> a(n, vector<int>(m, 1));

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == ')')
                    a[r][c] = -1;
            }
        }

        memset(dp, -1, sizeof(dp));

        return fun(n - 1, m - 1, a, 0);
    }
};