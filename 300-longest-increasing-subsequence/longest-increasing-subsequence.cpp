class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i = n-1;i>=0;i--){
            for( int prev=i;prev>=-1;prev--){
                int nottake = dp[i+1][prev+1];
                if(prev==-1 || nums[i]>nums[prev])
                    nottake=max(nottake,1+dp[i+1][i+1]);
                dp[i][prev+1]=nottake;
            }
        }
        return dp[0][0];
    }
};