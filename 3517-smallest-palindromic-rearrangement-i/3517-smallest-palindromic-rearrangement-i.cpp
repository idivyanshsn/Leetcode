class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string st = s.substr(0, n / 2);
        sort(st.begin(), st.end());
        string result = st;
        if (n % 2 != 0)
            result += s[n / 2];
        result.append(st.rbegin(), st.rend());
        return result;
    }
};