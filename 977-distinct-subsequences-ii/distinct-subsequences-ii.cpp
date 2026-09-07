class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.length(), MOD = 1000000000 + 7;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        vector<int> last(26, -1);
        for (int i = 0; i < n; i++) {
            dp[i+1] = (2 * dp[i]) % MOD;
            int c = s[i] - 'a';
            if (last[c] != -1)
                dp[i+1] = (dp[i+1] - dp[last[c]] + MOD) % MOD;
            last[c] = i;
        }
        return (dp[n] - 1 + MOD) % MOD;
    }
};