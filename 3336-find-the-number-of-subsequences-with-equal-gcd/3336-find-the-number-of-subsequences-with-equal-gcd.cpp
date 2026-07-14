class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int MOD = 1e9 + 7;
        int maxNum = *max_element(nums.begin(), nums.end());

        vector<vector<int>> dp(maxNum + 1, vector<int>(maxNum + 1, 0));
        dp[0][0] = 1;

        for (int num : nums) {
            vector<vector<int>> next_dp = dp;

            for (int g1 = 0; g1 <= maxNum; ++g1) {
                for (int g2 = 0; g2 <= maxNum; ++g2) {
                    if (dp[g1][g2] == 0)
                        continue;

                    int next_g1 = (g1 == 0) ? num : gcd(g1, num);
                    next_dp[next_g1][g2] =
                        (next_dp[next_g1][g2] + dp[g1][g2]) % MOD;

                    int next_g2 = (g2 == 0) ? num : gcd(g2, num);
                    next_dp[g1][next_g2] =
                        (next_dp[g1][next_g2] + dp[g1][g2]) % MOD;
                }
            }
            dp = move(next_dp);
        }

        int totalPairs = 0;
        for (int g = 1; g <= maxNum; ++g) {
            totalPairs = (totalPairs + dp[g][g]) % MOD;
        }

        return totalPairs;
    }
};