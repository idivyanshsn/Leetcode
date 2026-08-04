class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end());
        vector<int> points(maxEle + 1, 0);
        for (int num : nums)
            points[num] += num;
        // vector<int> dp(points.size(), 0);
        // dp[0] = points[0];
        // if (points.size() > 1)
        //     dp[1] = max(points[0], points[1]);
        int prev2 = points[0];
        int prev = points.size() > 1 ? max(points[0], points[1]) : points[0];
        int curr = 0;
        for (int i = 2; i < points.size(); i++) {
            int take = points[i];
            if (i > 1)
                take += prev2;
            int notTake = 0 + prev;
            curr = max(take, notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};