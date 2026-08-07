class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int ast : asteroids) {
            while (!st.empty() && st.top() > 0 && ast < 0) {
                if (st.top() < abs(ast))
                    st.pop();
                else if (st.top() == abs(ast)) {
                    st.pop();
                    ast = 0;
                    break;
                } else {
                    ast = 0;
                    break;
                }
            }
            if (ast != 0)
                st.push(ast);
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};