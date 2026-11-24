class Solution {
public:
    void function(int row, vector<string>& board, vector<vector<string>>& ans,
                  int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isSafe(row, i, board, n)) {
                board[row][i] = 'Q';

                function(row + 1, board, ans, n);
                board[row][i] = '.';
            }
        }
    }
    bool isSafe(int row, int col, vector<string>& board, int n) {
        // col
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // leftdia
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // upperdia
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        function(0, board, ans, n);

        return ans;
    }
};