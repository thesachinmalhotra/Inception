class Solution {
   public:
    int largestRectangleArea(const std::vector<int>& heights) {
        const int n = static_cast<int>(heights.size());
        stack<int> st;
        int maxArea = 0;

        for (int right = 0; right <= n; ++right) {
            while (!st.empty() && (right == n || heights[st.top()] >= heights[right])) {
                const int height = heights[st.top()];
                st.pop();

                const int left = st.empty() ? -1 : st.top();
                const int width = right - left - 1;

                maxArea = std::max(maxArea, height * width);
            }
            if (right < n) {
                st.push(right);
            }
        }
        return maxArea;
    }
};
