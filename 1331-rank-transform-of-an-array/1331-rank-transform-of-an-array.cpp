class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> rankMap;
        for (int element : arr) {
            rankMap[element] = 0;
        }
        int currentRank = 1;
        for (auto& pair : rankMap) {
            pair.second = currentRank;
            currentRank++;
        }
        vector<int> ans;
        for (int element : arr) {
            ans.push_back(rankMap[element]);
        }

        return ans;
    }
};