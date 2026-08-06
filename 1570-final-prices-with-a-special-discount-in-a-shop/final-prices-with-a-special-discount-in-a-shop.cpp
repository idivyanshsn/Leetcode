class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans = prices;
        stack<int> st;
        int n = prices.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() > prices[i])
                st.pop();
            if (!st.empty())
                ans[i] -= st.top();
            st.push(prices[i]);
        }
        return ans;
    }
};