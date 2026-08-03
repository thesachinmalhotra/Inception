#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        seen.reserve(nums.size());

        for (auto i = 0; i < static_cast<int>(nums.size()); ++i) {
            const auto complement = target - nums[i];

            if (const auto it = seen.find(complement); it != seen.end()) {
                return{it->second, i};
            }

            seen.emplace(nums[i], i);
        }
         
        return {};
    }
};
