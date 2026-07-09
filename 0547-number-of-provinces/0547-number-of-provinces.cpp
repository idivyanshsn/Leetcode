class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, adj, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected.size(); j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    // adj[j].push_back(isConnected[i]);
                }
            }
        }
        vector<int> visited(n,0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, adj, visited);
            }
        }
        return count;
    }
};