class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& visited,
             vector<pair<int, int>>& vec, vector<vector<char>>& grid, int row0,
             int col0) {
        int m = grid.size();
        int n = grid[0].size();
        vec.push_back({row - row0, col - col0});
        visited[row][col] = 1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                !visited[nrow][ncol] && grid[nrow][ncol] == '1') {
                dfs(nrow, ncol, visited, vec, grid, row0, col0);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<pair<int, int>>> st;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    vector<pair<int, int>> vec;
                    dfs(i, j, visited, vec, grid, i, j);
                    st.push_back(vec);
                }
            }
        }
        return st.size();
    }
};