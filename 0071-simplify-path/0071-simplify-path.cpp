class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp;
        string ans;
        for (char ch : path) {
            if (ch == '/') {
                if (temp == "" || temp == ".") {
                } else if (temp == "..") {
                    if (!st.empty())
                        st.pop();
                } else {
                    st.push(temp);
                }
                temp = "";
            } else {
                temp += ch;
            }
        }
        if (temp == "..") {
            if (!st.empty())
                st.pop();
        } else if (temp != "" && temp != ".") {
            st.push(temp);
        }
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans.empty() ? "/" : ans;
    }
};