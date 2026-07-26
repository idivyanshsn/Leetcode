class Solution {
public:
    int function(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        if (nums[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;
        if (nums[0] != 0 && nums[0] <= target)
            dp[0][nums[0]] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                int pick = 0;
                int notpick = dp[i - 1][j];
                if (nums[i] <= j) {
                    pick = dp[i - 1][j - nums[i]];
                }
                dp[i][j] = pick + notpick;
            }
        }
        return dp[n - 1][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for (auto it : nums) {
            totalSum += it;
        }
        if (abs(target) > totalSum || (totalSum + target) % 2 != 0)
            return 0;
        int newTarget = (totalSum + target) / 2;
        return function(nums, newTarget);
    }
};