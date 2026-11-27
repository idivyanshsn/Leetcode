class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for(int stone:stones)
            sum+=stone;
        int target=sum/2;
        int n = stones.size();
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        dp[0][0]=true;
        for(int i=0;i<n;i++)
            dp[i][0]=true;
        if(stones[0]<=target)
            dp[0][stones[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                bool notpick=dp[i-1][j];
                bool pick=false;
                if(j>=stones[i])
                    pick=dp[i-1][j-stones[i]];
                dp[i][j]=pick||notpick;
            }
        }
        int mini=INT_MAX;
        for(int x=0;x<=target;x++){
            if(dp[n-1][x]){
                int s2=sum-x;
                mini=min(mini,abs(x-s2));
            }
        }
        return mini;
    }
};