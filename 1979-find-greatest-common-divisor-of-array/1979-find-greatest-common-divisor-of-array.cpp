class Solution {
private:
    int gcd(int a, int b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int num1 = nums[0], num2 = nums[n - 1];
        return gcd(num1, num2);
    }
};