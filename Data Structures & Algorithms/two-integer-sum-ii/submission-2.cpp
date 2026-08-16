class Solution {
   public:
    std::vector<int> twoSum(const std::vector<int>& numbers, int target) {
        int left = 0;
        int right = static_cast<int>(numbers.size() - 1);

        while (left < right) {
            const int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1};
            }

            if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
        return {};
    }
};
