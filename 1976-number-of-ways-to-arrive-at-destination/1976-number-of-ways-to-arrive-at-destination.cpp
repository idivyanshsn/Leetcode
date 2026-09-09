class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : roads) {
            adj[it[0]].push_back({it[2], it[1]});
            adj[it[1]].push_back({it[2], it[0]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);
        const int mod = 1e9 + 7;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [distance, node] = pq.top();
            pq.pop();
            if (distance > dist[node])
                continue;
            for (auto [edweight, ednode] : adj[node]) {
                long long newdist = distance + edweight;
                if (newdist < dist[ednode]) {
                    dist[ednode] = newdist;
                    ways[ednode] = ways[node];
                    pq.push({newdist, ednode});
                } else if (newdist == dist[ednode]) {
                    ways[ednode] = (ways[ednode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1];
    }
};