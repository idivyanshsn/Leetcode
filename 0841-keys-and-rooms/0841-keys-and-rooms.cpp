class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int room, vector<int>& vis) {
        vis[room] = 1;
        for (int key : rooms[room]) {
            if (vis[key] == 0)
                dfs(rooms, key, vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0);
        dfs(rooms, 0, vis);
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0)
                return false;
        }
        return true;
    }
};