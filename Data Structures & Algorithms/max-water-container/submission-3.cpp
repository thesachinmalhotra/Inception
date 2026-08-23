class Solution {
public:
    int maxArea(const std::vector<int>& heights) {
        int left = 0;
        int right = static_cast<int>(heights.size()) - 1;

        int maxArea = 0;

        while (left < right) {
            const int width = right - left;
            const int currentHeight = std::min(heights[left], heights[right]);
            const int area = width * currentHeight;

            maxArea = std::max(maxArea, area);

            if (heights[left] < heights[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return maxArea;
    }
};
