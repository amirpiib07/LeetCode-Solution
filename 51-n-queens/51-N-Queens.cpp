class Solution {
    void f(vector<vector<string>>& ans, vector<bool>& low, vector<bool>& up,
           vector<bool>& col, vector<string>& board, int colm, int n) {
        if (colm == n) {
            ans.push_back(board);
            return;
        }

        for (int idx = 0; idx < n; idx++) {
            if (board[idx][colm] == '.' && col[idx] == false &&
                up[n - idx + colm - 1] == false && low[idx + colm] == false) {
                board[idx][colm] = 'Q';
                col[idx] = true;
                up[n - idx + colm - 1] = true;
                low[idx + colm] = true;
                f(ans, low, up, col, board, colm + 1, n);
                col[idx] = false;
                up[n - idx + colm - 1] = false;
                low[idx + colm] = false;
                board[idx][colm] = '.';
            }
        }

        return;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');

        for (int idx = 0; idx < n; idx++) {
            board[idx] = s;
        }

        vector<bool> low_diag(2 * n - 1, false);
        vector<bool> up_diag(2 * n - 1, false);
        vector<bool> col(n, false);

        f(ans, low_diag, up_diag, col, board, 0, n);

        return ans;
    }
};