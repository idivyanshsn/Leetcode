class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i< s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
                continue;
            }
            if (st.empty())
                return false;
            char symbol = st.top();
            st.pop();

            if (s[i] == '}' && symbol == '{' || s[i] == ')' && symbol == '(' ||
                s[i] == ']' && symbol == '[')
                continue;
            return false;
        }
        return st.empty();
    }
};