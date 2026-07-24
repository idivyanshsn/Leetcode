class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int maxValue = 0;
        for (int num : nums) {
            maxValue = max(maxValue, num);
        }
        int limit = 1;
        while (limit <= maxValue) {
            limit *= 2;
        }
        vector<int> singleXor(limit), doubleXor(limit), tripleXor(limit);
        for (int num : nums) {
            singleXor[num] = 1;
            for (int xorValue = 0; xorValue < limit; xorValue++) {
                if (singleXor[xorValue]) {
                    doubleXor[xorValue ^ num] = 1;
                }
            }
        }
        for (int num : nums) {
            for (int xorValue = 0; xorValue < limit; xorValue++) {
                if (doubleXor[xorValue]) {
                    tripleXor[xorValue ^ num] = 1;
                }
            }
        }
        int uniqueCount = 0;
        for (int xorValue = 0; xorValue < limit; xorValue++) {
            if (tripleXor[xorValue]) {
                uniqueCount++;
            }
        }
        return uniqueCount;
    }
};