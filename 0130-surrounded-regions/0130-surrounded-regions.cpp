class Solution {
private:
    void markSafe(vector<vector<char>>& board, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
            return;
        board[i][j] = '2';
        markSafe(board, i + 1, j, m, n);
        markSafe(board, i, j + 1, m, n);
        markSafe(board, i - 1, j, m, n);
        markSafe(board, i, j - 1, m, n);
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m==0) return;
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool isSafe = (i == 0 || j == 0 || i == m - 1 || j == n - 1);
                if (isSafe && board[i][j] == 'O') {
                    markSafe(board, i, j, m, n);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '2') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};