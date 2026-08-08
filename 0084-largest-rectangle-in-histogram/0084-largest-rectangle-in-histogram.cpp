class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int area = 0;
        stack<int> st;
        for (int i = 0; i <= heights.size(); i++) {
            int curr = i == n ? 0 : heights[i];
            while (!st.empty() && heights[st.top()] > curr) {
                int index = st.top();
                st.pop();
                int height = heights[index];
                int width = st.empty() ? i : i - st.top() - 1;
                area = max(area, (height * width));
            }
            st.push(i);
        }
        return area;
    }
};