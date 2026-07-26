class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned int>> dp(n, vector<unsigned int>(amount + 1, 0));
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                dp[0][i] = 1;
            else
                dp[0][i] = 0;
        }
        for (int index = 1; index < n; index++) {
            for (int money = 0; money <= amount; money++) {
                unsigned int nottake = dp[index - 1][money];
                unsigned int take = 0;
                if (money >= coins[index]) {
                    take = dp[index][money - coins[index]];
                }
                dp[index][money] = take + nottake;
            }
        }
        return dp[n - 1][amount];
    }
};