class Solution {
public:
    int maxArea(const std::vector<int>& height) {
        int left = 0;
        int right = static_cast<int>(height.size()) -1;

        int maxArea = 0;

        while (left < right) {
            const int width = right - left;
            const int currentHeight = std::min(height[left], height[right]);
            const int area = width * currentHeight;

            maxArea = std::max(maxArea, area);

            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return maxArea;
    }
};
