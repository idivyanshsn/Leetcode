class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<pair<int,int>,
               vector<pair<int,int>>,
               greater<pair<int,int>>> q;
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        q.push({0, k});
        while (!q.empty()) {
            auto it = q.top();
            q.pop();
            int dis = it.first;
            int node = it.second;
            if (dis > dist[node])
                continue;
            for (auto it : adj[node]) {
                int adjnode = it.first;
                int wt = it.second;
                if (dis + wt < dist[adjnode]) {
                    dist[adjnode] = dis + wt;
                    q.push({dist[adjnode], adjnode});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) {
                return -1;
            }
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};