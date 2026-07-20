class Solution {
private:
    void reverseGrid(vector<vector<int>>& grid, int start, int end, int n) {
        while (start < end) {
            int r1 = start / n, r2 = end / n;
            int c1 = start % n, c2 = end % n;
            swap(grid[r1][c1], grid[r2][c2]);
            start++;
            end--;
        }
    }

public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total_ele = m * n;
        if (k == 0)
            return grid;
        k = k % total_ele;
        reverseGrid(grid, 0, total_ele - 1, n);
        reverseGrid(grid, 0, k - 1, n);
        reverseGrid(grid, k, total_ele - 1, n);
        return grid;
    }
};