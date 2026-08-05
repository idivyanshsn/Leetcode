class Solution {
private:
    static bool compare(string& str1, string& str2) {
        return str1.size() < str2.size();
    }
    bool function(string& str1, string& str2) {
        if (str1.size() != str2.size() + 1)
            return false;
        int first = 0;
        int second = 0;
        while (first < str1.size()) {
            if (second < str2.size() && str1[first] == str2[second]) {
                first++;
                second++;
            } else {
                first++;
            }
        }
        if (first == str1.size() && second == str2.size())
            return true;
        return false;
    }

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 0;
        sort(words.begin(), words.end(), compare);
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (function(words[i], words[prev]) && dp[i] < 1 + dp[prev])
                    dp[i] = dp[prev] + 1;
            }
            maxi = max(dp[i], maxi);
        }
        return maxi;
    }
};