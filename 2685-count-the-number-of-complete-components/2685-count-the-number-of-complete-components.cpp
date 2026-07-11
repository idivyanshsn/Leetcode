class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (auto it : edges) {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        vector<int> visited(n, 0);
        int completeComponents = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int edgeCount = 0;
                int nodeCount = 0;
                queue<int> q;
                q.push(i);
                visited[i] = 1;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    nodeCount++;
                    edgeCount += adjList[node].size();
                    for (auto p : adjList[node]) {
                        if (!visited[p]) {
                            visited[p] = 1;
                            q.push(p);
                        }
                    }
                }
                if (edgeCount == nodeCount * (nodeCount - 1)) {
                    completeComponents++;
                }
            }
        }
        return completeComponents;
    }
};