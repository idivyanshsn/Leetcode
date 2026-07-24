class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n==1) return cost[0] ;
        if(n==0) return 0;
        
        vector<int> dp(n+1, 1e9);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            int step1=cost[i]+dp[i-1];
            int step2=cost[i]+dp[i-2];
            dp[i]=min(step1,step2);
        }
        return min(dp[n-1],dp[n-2]);
    }
};