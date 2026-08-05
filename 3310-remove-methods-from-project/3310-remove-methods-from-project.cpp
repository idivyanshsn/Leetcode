class Solution {
private:
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adj) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, visited, adj);
            }
        }
    }

public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto it : invocations) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        vector<int> visited(n, 0);
        dfs(k, visited, adj);
        for (auto it : invocations) {
            int u = it[0];
            int v = it[1];
            if (!visited[u] && visited[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!visited[i])
                ans.push_back(i);
        }

        return ans;
    }
};