class Solution {
public:
    void function(int ind, string str, vector<string>& ans, string s) {
        if (ind == s.size()) {
            ans.push_back(str);
            return;
        }
        if (s[ind] >= 97 && s[ind] <= 122 || s[ind] >= 65 && s[ind] <= 91) {
            str.push_back(toupper(s[ind]));
            function(ind + 1, str, ans, s);
            str.pop_back();
            str.push_back(tolower(s[ind]));
            function(ind + 1, str, ans, s);
        }

        else {
            str.push_back(s[ind]);
            function(ind + 1, str, ans, s);
        }
    }
    vector<string> letterCasePermutation(string s) {
        string str;
        vector<string> ans;
        function(0, str, ans, s);
        return ans;
    }
};