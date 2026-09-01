class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sr, sc, litter = 0;
        map<pair<int,int>,int> litId;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') { sr = i; sc = j; }
                if (classroom[i][j] == 'L') { litId[{i,j}] = litter++; }
            }
        int full = (1 << litter) - 1;
        vector<vector<vector<int>>> vis(m, vector<vector<int>>(n, vector<int>(1 << litter, -1)));
        queue<tuple<int,int,int,int>> q;
        vis[sr][sc][0] = energy;
        q.push({sr, sc, 0, energy});
        int steps = 0;
        int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, mask, e] = q.front(); q.pop();
                if (mask == full) return steps;
                if (e <= 0) continue;
                for (int d = 0; d < 4; ++d) {
                    int nr = r+dx[d], nc = c+dy[d];
                    if (nr<0||nr>=m||nc<0||nc>=n||classroom[nr][nc]=='X') continue;
                    int ne = e - 1, nm = mask;
                    if (classroom[nr][nc] == 'L') nm |= (1 << litId[{nr,nc}]);
                    if (classroom[nr][nc] == 'R') ne = energy;
                    if (ne > vis[nr][nc][nm]) {
                        vis[nr][nc][nm] = ne;
                        q.push({nr, nc, nm, ne});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};