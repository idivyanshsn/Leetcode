class Solution {
public:
    bool function(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char digit = '1'; digit <= '9'; digit++) {
                        if (isSafe(i, j, board, digit)) {
                            board[i][j] = digit;
                            if (function(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
                
            }
        }
        return true;
    }
    bool isSafe(int row, int col, vector<vector<char>>& board, char digit) {
        // col
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == digit) {
                return false;
            }
        }
        // row
        for (int j = 0; j < board.size(); j++) {
            if (board[row][j] == digit) {
                return false;
            }
        }
        int nrow = (row / 3) * 3;
        int ncol = (col / 3) * 3;
        // subboxes
        for (int i = nrow; i < nrow + 3; i++) {
            for (int j = ncol; j < ncol + 3; j++) {
                if (board[i][j] == digit) {
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { function(board); }
};