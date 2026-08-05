class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int p = cuts.size();
        vector<vector<int>> dp(p, vector<int>(p, 0));
        for (int i = p - 2; i >=1; i--) {
            for (int j = i; j <= p - 2; j++) {
                int mini = INT_MAX;
                for (int k = i; k <= j; k++) {
                    int cost = ((cuts[j + 1] - cuts[i - 1]) + dp[i][k - 1] +
                                dp[k + 1][j]);
                    mini = min(cost, mini);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][p - 2];
    }
};