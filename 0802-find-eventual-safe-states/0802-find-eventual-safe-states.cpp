class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safeNodes;
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        queue<int> q;
        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                adj[v].push_back(u);
                indegree[u]++;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};