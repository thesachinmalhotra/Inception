class Solution {
public:
    vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
        std::deque<int> window;
        std::vector<int> result;

        for (int right = 0; right < static_cast<int>(nums.size()); ++right) {
            if (!window.empty() && window.front() <= right - k) {
                window.pop_front();
            }

            while (!window.empty() && nums[window.back()] <= nums[right]) {
                window.pop_back();
            }
            window.push_back(right);

            if (right >= k - 1) {
                result.push_back(nums[window.front()]);
            }
        }
        return result;
    }
};
