class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int r,
             int c) {
        vis[r][c] = true;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        int n = heights.size();
        int m = heights[0].size();
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc < m && nc >= 0 && !vis[nr][nc] &&
                heights[nr][nc] >= heights[r][c]) {
                dfs(heights, vis, nr, nc);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
            dfs(heights, pacific, i, 0);
        for (int j = 0; j < m; j++)
            dfs(heights, pacific, 0, j);
        for (int i = 0; i < n; i++)
            dfs(heights, atlantic, i, m - 1);
        for (int j = 0; j < m; j++)
            dfs(heights, atlantic, n- 1, j);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};