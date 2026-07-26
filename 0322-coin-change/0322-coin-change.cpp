class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) {
                dp[0][i] = i / coins[0];
            } else {
                dp[0][i] = 1e9;
            }
        }
        for (int index = 1; index < n; index++) {
            for (int target = 0; target <= amount; target++) {
                int notTake = dp[index - 1][target];
                int take = INT_MAX;
                if (coins[index] <= target) {
                    take = 1 + dp[index][target - coins[index]];
                }
                dp[index][target] = min(take, notTake);
            }
        }
        return dp[n - 1][amount]>=1e9?-1:dp[n-1][amount];
    }
};