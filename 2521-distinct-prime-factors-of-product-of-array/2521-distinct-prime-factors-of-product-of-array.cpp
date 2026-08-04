class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> sett;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 2; j * j <= nums[i]; j++) {
                while (nums[i] % j == 0) {
                    sett.insert(j);
                    nums[i] /= j;
                }
            }
            if (nums[i] > 1)
                sett.insert(nums[i]);
        }
        return sett.size();
    }
};