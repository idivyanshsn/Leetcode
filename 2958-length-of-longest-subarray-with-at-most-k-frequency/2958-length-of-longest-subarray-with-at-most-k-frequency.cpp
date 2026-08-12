class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0, maxLen = 0;
        unordered_map<int, int> hash;
        for (int right = 0; right < nums.size(); right++) {
            hash[nums[right]]++;
            while (hash[nums[right]] > k) {
                hash[nums[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};