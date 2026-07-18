class Solution {
public:
    int findGCD(vector<int>& nums) {
        int num1 = *min_element(nums.begin(), nums.end());
        int num2 = *max_element(nums.begin(), nums.end());
        return gcd(num1, num2);
    }
};