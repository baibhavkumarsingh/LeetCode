class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = INT_MIN;
        stack<int> st;
        int indx, element;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                element = heights[st.top()];
                st.pop();
                st.empty() ? indx = -1 : indx = st.top();
                area = max(area, element * (i - indx - 1));
            }
            st.push(i);
        }
        int i = st.top();
        while (!st.empty()) {
            int element = heights[st.top()];
            st.pop();
            st.empty() ? indx = -1 : indx = st.top();
            area = max(area, element * (i - indx));
        }
        return area;
    }
};