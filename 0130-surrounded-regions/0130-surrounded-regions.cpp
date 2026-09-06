class Solution {
public:
    void function(vector<vector<char>>& board, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 'O')
            return;
        board[i][j] = 's';
        function(board, i + 1, j, n, m);
        function(board, i, j - 1, n, m);
        function(board, i, j + 1, n, m);
        function(board, i - 1, j, n, m);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool isSafe = (i == 0 || i == n - 1 || j == 0 || j == m - 1);
                if (isSafe && board[i][j] == 'O')
                    function(board, i, j, n, m);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 's')
                    board[i][j] = 'O';
            }
        }
    }
};