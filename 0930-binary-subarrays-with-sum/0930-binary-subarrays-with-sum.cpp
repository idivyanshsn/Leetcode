class Solution {
private:
    int function(vector<int>& nums, int goal) {
        int n = nums.size();
        if (goal < 0)
            return 0;
        int left = 0;
        int right = 0;
        int count = 0;
        int sum = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum > goal) {
                sum -= nums[left];
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return function(nums, goal) - function(nums, goal - 1);
    }
};