class Solution {
public:
    int function(int n, vector<int>& dp) {
        if (dp[n] != -1)
            return dp[n];
        dp[n] = function(n - 1, dp) + function(n - 3, dp) + function(n - 2, dp);
        return dp[n];
    }
    int tribonacci(int n) {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        if (n == 3)
            return 2;
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        return function(n, dp);
    }
};