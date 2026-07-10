class Solution {
public:
void markSafe(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        markSafe(grid, i + 1, j, m, n);
        markSafe(grid, i, j + 1, m, n);
        markSafe(grid, i - 1, j, m, n);
        markSafe(grid, i, j - 1, m, n);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m==0) return 0;
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool isSafe = (i == 0 || j == 0 || i == m - 1 || j == n - 1);
                if (isSafe &&grid[i][j] == 1) {
                    markSafe(grid, i, j, m, n);
                }
            }
        }
        int var =0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    grid[i][j] = 1;
                } else if (grid[i][j] == 1) {
                    var++;
                }
            }
        }
        return var;
        
    }
};