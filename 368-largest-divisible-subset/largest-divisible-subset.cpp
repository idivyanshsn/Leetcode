class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> hash(n);
        for (int i = 0; i < n; i++)
            hash[i] = i;
        vector<int> dp(n, 1);
        int maxi = 1;
        int lastIndex = 0;
        for (int i = 0; i < n; i++) {
            for (int prevInd = 0; prevInd < i; prevInd++) {
                if (nums[i] % nums[prevInd] == 0 && dp[i] < 1 + dp[prevInd]) {
                    dp[i] = 1 + dp[prevInd];
                    hash[i] = prevInd;
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while (hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};