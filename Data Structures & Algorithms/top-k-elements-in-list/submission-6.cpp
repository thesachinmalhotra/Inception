class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
       std::unordered_map<int, int> frequency;

       for (const auto& num : nums) {
            ++frequency[num];
       }

       std::vector<std::vector<int>> buckets(nums.size() + 1);

       for (const auto& [num, count] : frequency) {
          buckets[count].push_back(num);
       }

       std::vector<int> results;

       for (int i = static_cast<int> (buckets.size()) - 1; i > 0; --i) {
         for (const auto num : buckets[i]) {
             results.push_back(num);

             if (results.size() == k) {
                return results;
             }     
         }
       }
       return results;
    }
};
