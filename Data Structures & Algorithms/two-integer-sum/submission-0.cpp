#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        seen.reserve(nums.size());

        for (std::size_t i = 0; i < nums.size(); ++i) {
            const auto complement = target - nums[i];

            if (const auto it = seen.find(complement); it != seen.end()) {
                return {it->second, static_cast<int>(i)};
            }

            seen.emplace(nums[i], static_cast<int>(i));
        }
        return {};
    }
};
