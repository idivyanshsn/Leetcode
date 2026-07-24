class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int i = 0; i < n; i++)
            totalSum += nums[i];
        if (totalSum % 2 != 0)
            return false;
        int sum = totalSum / 2;
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if (nums[0] <= sum)
            dp[0][nums[0]] = true;
        for (int index = 1; index < n; index++) {
            for (int target = 0; target <= sum; target++) {
                bool notTaken = dp[index - 1][target];
                bool taken = false;
                if (nums[index] <= target) {
                    taken = dp[index - 1][target - nums[index]];
                }
                dp[index][target] = taken || notTaken;
            }
        }
        return dp[n - 1][sum];
    }
};