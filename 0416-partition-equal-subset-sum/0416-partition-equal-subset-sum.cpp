class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int num : nums)
            sum += num;
        if (sum % 2 != 0)
            return false;
        int t = sum / 2;
        
        vector<vector<bool>> dp(n, vector<bool>(t + 1, false));
        if(nums[0] <= t)
        dp[0][nums[0]] = true;
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        for (int i = 1; i <n; i++) {
            for (int j = 1; j <= t; j++) {
                bool notpick = dp[i - 1][j];
                bool pick = false;
                if (nums[i] <= j)
                    pick = dp[i - 1][j - nums[i]];
                dp[i][j] = pick || notpick;
            }
        }
        return dp[n - 1][t];
    }
};