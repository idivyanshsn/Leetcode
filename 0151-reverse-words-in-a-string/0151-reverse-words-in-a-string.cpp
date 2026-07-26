class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> words;
        int i = 0;
        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;
            if (i == n)
                break;
            int start = i;
            while (i < n && s[i] != ' ')
                i++;
            words.push_back(s.substr(start, i - start));
        }
        reverse(words.begin(), words.end());
        string ans = "";

        for (int i = 0; i < words.size(); i++) {
            ans += words[i];
            if (i != words.size() - 1)
                ans += " ";
        }

        return ans;
    }
};