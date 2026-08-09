class Solution {
   public:
    int longestConsecutive(const std::vector<int>& nums) {
        std::unordered_set<int> numbers(nums.begin(), nums.end());
     
         int longest = 0;

        for (const auto num : nums) {
            if (numbers.contains(num - 1)) {
                continue;
            }

            int length = 1;

            while (numbers.contains(num + length)) {
                ++length;
            }
            longest = std::max(longest, length);
        }

        return longest;
    }
};
