class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<string> st;
        string temp = "";
        for (char ch : expression) {
            if (ch == 't')
                st.push("t");
            if (ch == 'f')
                st.push("f");
            if (ch == '!')
                st.push("!");
            if (ch == '&')
                st.push("&");
            if (ch == '|')
                st.push("|");
            if (ch == ')') {
                while (!st.empty() && (st.top() == "t" || st.top() == "f")) {
                    temp = st.top() + temp;
                    st.pop();
                }
                char op = st.top()[0];
                st.pop();
                string result = "";
                if (op == '&')
                    result = "t";
                else if (op == '|')
                    result = "f";
                for (int i = 0; i < temp.size(); i++) {
                    if (op == '&') {
                        if (temp[i] == 'f')
                            result = "f";

                    } else if (op == '|') {
                        if (temp[i] == 't')
                            result = "t";
                    } else if (op == '!')
                        if (temp[i] == 't')
                            result = "f";
                        else
                            result = "t";
                }
                st.push(result);
                temp = "";
            }
        }
        return st.top() == "t";
    }
};