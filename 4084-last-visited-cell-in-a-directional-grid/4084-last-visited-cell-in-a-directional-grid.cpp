class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int s_r = 0, s_c = 0;

        while (true) {
            char ch = grid[s_r][s_c];
            grid[s_r][s_c] = '#';

            int r = s_r, c = s_c;

            if (ch == 'U') s_r--;
            else if (ch == 'D') s_r++;
            else if (ch == 'R') s_c++;
            else s_c--;

            
            if (s_r < 0 || s_r >= m ||
                s_c < 0 || s_c >= n ||
                grid[s_r][s_c] == '#') {
                return {r, c};
            }
        }
    }
};