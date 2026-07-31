class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0;
        int right = 0;
        int maxLen = 0;
        int type = 0;
        unordered_map<int, int> freq;
        while (right < n) {
            freq[fruits[right]]++;
            while (freq.size() > 2) {
                freq[fruits[left]]--;
                if (freq[fruits[left]] == 0)
                    freq.erase(fruits[left]);
                left++;
            }
            int len = right - left + 1;
            right++;
            maxLen = max(len, maxLen);
        }
        return maxLen;
    }
};