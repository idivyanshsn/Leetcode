class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> st;
        int k = 0;
        string ans = "";
        for (char ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0');
            }
            else if (ch == '[') {
                nums.push(k);
                st.push("[");
                k = 0;
            }
            else if (ch == ']') {
                string temp = "";
                while (!st.empty() && st.top() != "[") {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                int num = nums.top();
                nums.pop();
                string tempAns = "";
                for (int i = 0; i < num; i++) {
                    tempAns += temp;
                }
                st.push(tempAns);
            }
            else {
                st.push(string(1, ch));
            }
        }
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};