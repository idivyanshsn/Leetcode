class Solution {
private:
    int function(vector<int>& nums, int position, vector<int>& dp) {
        int n = nums.size();
        if (position >= n - 1)
            return 0;
        if(dp[position]!=-1) return dp[position];
        if(nums[position]==0) return dp[position]=INT_MAX;
        int mini = INT_MAX;
        for(int i=1;i<=nums[position];i++){
            int subAns = function(nums, i + position,dp);
            if (subAns != INT_MAX) {
                mini = min(mini, 1 + subAns);
            }
            
        }
        return dp[position]=mini;
    }

public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, -1);
        return function(nums, 0, dp);
    }
};