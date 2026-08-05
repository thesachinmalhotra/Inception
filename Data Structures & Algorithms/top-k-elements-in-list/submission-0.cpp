#include <ranges>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
        std::unordered_map<int, int> frequency;
        frequency.reserve(nums.size());

        for (const auto num : nums) {
            ++frequency[num];
        }

        std::vector<std::vector<int>> buckets(nums.size() + 1);

        for (const auto& [num, count] : frequency) {
        buckets[count].push_back(num);
        }

      std::vector<int> results;
       results.reserve(k);

      for (const auto& bucket : buckets | std::views::reverse) {
         for (const auto num : bucket) {
            results.push_back(num);

           if (results.size() == static_cast<std::size_t>(k)) {
                return results;
            }
        }
     }
      return results; 
    }
};
