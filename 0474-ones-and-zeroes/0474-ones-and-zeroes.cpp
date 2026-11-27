class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<vector<vector<int>>> dp(
            N, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        // base case
        int zero = 0, one = 0;

        for (char ch : strs[0]) {
            if (ch == '0')
                zero++;
            else
                one++;
        }
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= n; k++) {
                if (zero <= j && one <= k) {
                    dp[0][j][k] = 1;
                }
            }
        }
        for (int i = 1; i < N; i++) {
            int zeros = 0;
            int ones = 0;
            for (char ch : strs[i]) {
                if (ch == '0')
                    zeros++;
                if (ch == '1')
                    ones++;
            }
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    // notpick
                    int notpick = dp[i - 1][j][k];

                    // pick
                    int pick = 0;
                    if (zeros <= j && ones <= k)
                        pick = dp[i - 1][j - zeros][k - ones] + 1;

                    dp[i][j][k] = max(pick, notpick);
                }
            }
        }
        return dp[N - 1][m][n];
    }
};