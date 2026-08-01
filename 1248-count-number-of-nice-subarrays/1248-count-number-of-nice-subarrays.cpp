class Solution {
private:
    int function(vector<int>& nums, int k) {
        int n = nums.size();
        if (k < 0)
            return 0;
        int left = 0;
        int oddCount = 0;
        int count = 0;
        for (int right = 0; right < n; right++) {

            if (nums[right] % 2 != 0)
                oddCount++;
            while (oddCount > k) {
                if (nums[left] % 2 != 0)
                    oddCount--;
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return function(nums, k) - function(nums, k - 1);
    }
};