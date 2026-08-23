class Solution {
public:
    int trap(std::vector<int>& height) {
         int left = 0;
         int right = static_cast<int>(height.size()) - 1;

         int leftMax = 0;
         int rightMax = 0;
         int water = 0;

         while (left <= right) {
            if (leftMax <= rightMax) {
              leftMax = std::max(leftMax, height[left]);
              water += leftMax - height[left];
              ++left;
            } else {
                rightMax = std::max(rightMax, height[right]);
                water += rightMax - height[right];
                --right;
            }
         }
         return water;
    }
};
