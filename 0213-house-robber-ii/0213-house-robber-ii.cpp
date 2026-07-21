class Solution {
public:
    int function(const vector<int>& nums,int start,int end) {
        int prev2 = 0;
        int prev = 0;
        for (int i = start; i <= end; i++) {
            int take = nums[i];
            if (i > 1)
                take += prev2;
            int notTake = prev + 0;
            int curr = max(take, notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        return max(function(nums,0,n-2), function(nums,1,n-1));
    }
};