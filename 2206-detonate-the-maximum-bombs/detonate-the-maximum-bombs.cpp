class Solution {
public:
    int dfs(vector<vector<int>>& adj,vector<bool>& vis,int node){
        vis[node]=true;
        int count=1;
        for(int next : adj[node]) {
            if(!vis[next])
                count += dfs(adj, vis,next);
        }
        return count;

    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>> adj(n);
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                long long dx = bombs[i][0] - bombs[j][0];
                long long dy = bombs[i][1] - bombs[j][1];
                long long dist = dx*dx+dy*dy;
                long long radius =1LL* bombs[i][2] * bombs[i][2];
                if(dist <= radius) {
                    adj[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            vector<bool> vis(n, false);
            ans = max(ans, dfs(adj, vis,i));
        }
        return ans;

    }
};