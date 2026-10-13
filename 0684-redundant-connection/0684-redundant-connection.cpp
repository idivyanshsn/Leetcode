class Solution {
public:
    bool dfs(int start, int end, vector<vector<int>>& adj, vector<int>& vis) {
        vis[start] = 1;
        for (auto neighbour : adj[start]) {
            if (!vis[neighbour]) {
                if (dfs(neighbour, end, adj, vis))
                    return true;
            }
        }
        return vis[end];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        vector<int> ans;
        for (auto edge : edges) {
            vector<int> vis(n + 1, 0);
            if (dfs(edge[0], edge[1], adj, vis)){
                return{edge[0],edge[1]};
            }
            else {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
        }
        return {};
    }
};