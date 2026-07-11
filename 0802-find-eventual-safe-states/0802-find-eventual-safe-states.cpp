class Solution {
private:
    bool function(vector<vector<int>>& graph, int node, vector<int>& visited,
                  vector<int>& pathVis, vector<int> &check) {
        visited[node] = 1;
        pathVis[node] = 1;
        for (auto it : graph[node]) {
            if (!visited[it]) {
                if (function(graph, it, visited, pathVis, check)) {
                    return true;
                }
            } else if (pathVis[it]) {
                return true;
            }
        }

        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> check(n, 0);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                function(graph, i, visited, pathVis, check);
            }
        }

        for(int i=0;i<check.size();i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};