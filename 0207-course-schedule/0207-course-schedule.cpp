class Solution {
private:
    bool dfs(int node, int parent, vector<vector<int>>& adj,
             vector<int> &visited) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                if (dfs(it, node, adj, visited) == true)
                    return true;
            } else if (visited[it] == 1)
                return true;
        }
        visited[node]=2;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            int course = it[0];
            int prereq = it[1];
            adj[prereq].push_back(course);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, adj, visited) == true)
                    return false;
            }
        }
        return true;
    }
};