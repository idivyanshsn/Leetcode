class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j,bool & subIsland){
        int n=grid1.size();
        int m = grid1[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m || grid2[i][j] == 0) return;
        if(grid1[i][j]==0) subIsland=false;
        grid2[i][j]=0;
        dfs(grid1,grid2,i+1,j,subIsland);
        dfs(grid1,grid2,i,j-1,subIsland);
        dfs(grid1,grid2,i-1,j,subIsland);
        dfs(grid1,grid2,i,j+1,subIsland);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1){
                    bool subIsland=true;
                    dfs(grid1,grid2,i,j,subIsland);
                    if(subIsland) count++;
                } 
            }
        }
        return count;
    }
};