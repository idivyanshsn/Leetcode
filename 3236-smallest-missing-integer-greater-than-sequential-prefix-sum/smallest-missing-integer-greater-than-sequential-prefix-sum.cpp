class Solution {
public:
    int missingInteger(vector<int>& nums) {
        vector<bool> exist(52);
        for (int i = 0; i < nums.size(); i++) {
            exist[nums[i]] = true;
        }
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1)
                sum += nums[i];
            else
                break;
        }
        while (sum < 52 && exist[sum])
            sum++;

        return sum;
    }
};