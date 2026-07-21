class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int size = INT_MAX;
        if (nums.size() == 0)
            return 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum >= target) {
                size = min(size, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return (size == INT_MAX) ? 0 : size;
    }
};