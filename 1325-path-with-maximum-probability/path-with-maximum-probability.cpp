class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        priority_queue<pair<double, int>> pq;
        vector<double> prob(n,0.0);
        prob[start_node]=1;
        pq.push({1,start_node});
        while(!pq.empty()){
            auto [probab,node]=pq.top();
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                double probAdjNode=it.second;
                double newProb=probAdjNode*probab;
                if(newProb>prob[adjNode]){
                    prob[adjNode]=newProb;
                    pq.push({newProb,adjNode});
                }
            }
        }
        return prob[end_node];

    }
};