class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        vector<int> safeNodes;
        queue<int> q;
        for(int i =0;i<n;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                safeNodes.push_back(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    safeNodes.push_back(it);
                }
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};