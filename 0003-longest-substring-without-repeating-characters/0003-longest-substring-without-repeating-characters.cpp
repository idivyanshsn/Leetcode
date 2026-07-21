class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int size = 0;
        unordered_set<char> mpp;
        for (int right = 0; right < s.size(); right++) {
            if (mpp.contains(s[right])) {
                while (mpp.contains(s[right])) {
                    mpp.erase(s[left]);
                    left++;
                }
            }
            mpp.insert(s[right]);
            size = max(size, right - left + 1);
        }
        return size;
    }
};