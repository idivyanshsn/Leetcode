class Solution {
public:
    bool dfs(vector<vector<int>>& grid,int i,int j){
        int n=grid.size();
        int m = grid[0].size();
        if(i<0|| i>=n || j<0|| j>=m ) return false;
        if(grid[i][j]==1) return true;
        grid[i][j]=true;
        bool a=dfs(grid,i+1,j);
        bool b=dfs(grid,i-1,j);
        bool c=dfs(grid,i,j+1);
        bool d=dfs(grid,i,j-1);
        return a&&b&&c&&d;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    if(dfs(grid,i,j))
                        count++;
                }
            }
        }
        return count;
    }
};