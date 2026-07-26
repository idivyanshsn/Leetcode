class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        vector<int> cur(amount+1,0);
        vector<int> prev(amount+1,0);
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) {
                // dp[0][i] = i / coins[0];
                prev[i] = i / coins[0];
            } else {
                // dp[0][i] = 1e9;
                prev[i] = 1e9;
            }
        }
        for (int index = 1; index < n; index++) {
            for (int target = 0; target <= amount; target++) {
                // int notTake = dp[index - 1][target];
                int notTake = prev[target];
                int take = INT_MAX;
                if (coins[index] <= target) {
                    // take = 1 + dp[index][target - coins[index]];
                    take = 1 + cur[target - coins[index]];
                }
                // dp[index][target] = min(take, notTake);
                cur[target] = min(take, notTake);
            }
            prev=cur;
        }
        // return dp[n - 1][amount]>=1e9?-1:dp[n-1][amount];
        return prev[amount]>=1e9?-1:prev[amount];
    }
};