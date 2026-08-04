class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        int maxEle = *max_element(nums.begin(), nums.end());
        int minEle = *min_element(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        for (int i = minEle; i < maxEle; i++) {
            if (mpp[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};