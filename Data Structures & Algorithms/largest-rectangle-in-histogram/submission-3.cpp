class Solution {
   public:
    int largestRectangleArea(const std::vector<int>& heights) {
        std::stack<int> st;
        int result = 0;

        for (int right = 0; right < static_cast<int>(heights.size()); ++right) {
            while (!st.empty() && heights[right] < heights[st.top()]) {
                int i = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int width = right - left - 1;

                result = std::max(result, heights[i] * width);
            }
            st.push(right);
        }
        while (!st.empty()) {
            int i = st.top();
            st.pop();

            int left = st.empty() ? -1 : st.top();
            int width = heights.size() - left - 1;

            result = std::max(result, heights[i] * width);
        }
        return result;
    }
};
