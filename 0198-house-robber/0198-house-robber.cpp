class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int prev = nums[0];
        int prev2=0;
        int curr = 0;
        for (int i = 1; i < nums.size(); i++) {
            int pick = nums[i];
            if (i > 1)
                pick += prev2;
            int notPick = 0 + prev;
            curr = max(pick, notPick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};