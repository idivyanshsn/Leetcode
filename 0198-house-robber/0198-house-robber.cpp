class Solution {
public:
    int function(int ind, vector<int>& nums, vector<int>& dp) {
        if (ind < 0)
            return 0;
        if (ind == 0)
            return nums[ind];
        if (dp[ind] != -1)
            return dp[ind];
        int pick = nums[ind] + function(ind - 2, nums,dp);
        int notPick = function(ind - 1, nums,dp) + 0;

        return dp[ind] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return function(n - 1, nums,dp);
    }
};