class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int n = s.size();
        vector<bool> remove(n, false);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')') {
                if (!st.empty())
                    st.pop();
                else
                    remove[i] = true;
            }
        }
        while (!st.empty()) {
            remove[st.top()] = true;
            st.pop();
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (!remove[i])
                ans += s[i];
        }
        return ans;
    }
};