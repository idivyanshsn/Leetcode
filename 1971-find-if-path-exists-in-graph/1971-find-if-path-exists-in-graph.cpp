class Solution {
public:
    void dfs(int start, vector<vector<int>>& adj, vector<int> &vis) {
        vis[start] = 1;
        for (auto neighbour : adj[start]) {
            if (!vis[neighbour]) {
                dfs(neighbour, adj, vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        if (source == destination)
            return true;
        vector<int> vis(n);
        dfs(source, adj, vis);
        if (vis[destination])
            return true;
        return false;
    }
};