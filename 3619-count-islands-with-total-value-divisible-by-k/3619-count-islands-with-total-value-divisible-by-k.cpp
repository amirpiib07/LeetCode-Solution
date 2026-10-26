
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) continue;

                int inc = 0;

                q.push({r, c});
                inc = (inc + grid[r][c]) % k;
                grid[r][c] = 0;

                while (!q.empty()) {
                    auto [row, col] = q.front();
                    q.pop();

                    for (int idx = 0; idx < 4; ++idx) {
                        int n_r = row + dr[idx];
                        int n_c = col + dc[idx];

                        if (n_r >= 0 && n_c >= 0 &&
                            n_r < m && n_c < n &&
                            grid[n_r][n_c] != 0) {

                            inc = (inc + grid[n_r][n_c]) % k;

                            q.push({n_r, n_c});
                            grid[n_r][n_c] = 0;
                        }
                    }
                }

                if (inc == 0) ans++;
            }
        }

        return ans;
    }
};
