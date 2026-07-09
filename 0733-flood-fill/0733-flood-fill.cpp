class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int startingColor,
             int color) {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size())
            return;
        if (image[sr][sc] != startingColor)
            return;
        image[sr][sc] = color;
        dfs(image, sr + 1, sc, startingColor, color);
        dfs(image, sr, sc + 1, startingColor, color);
        dfs(image, sr - 1, sc, startingColor, color);
        dfs(image, sr, sc - 1, startingColor, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int startingColor = image[sr][sc];
        if (startingColor != color) {
            dfs(image, sr, sc, startingColor, color);
        }
        return image;
    }
};