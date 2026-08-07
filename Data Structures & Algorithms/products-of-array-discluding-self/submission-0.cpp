class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> result(nums.size(), 1);

        int prefix = 1;
        for (int i = 0; i < nums.size(); ++i) {
            result[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = static_cast<int>(nums.size()) - 1; i>=0; --i) {
            result[i] *= suffix;
            suffix *= nums[i];
        }
        return result;   
    }
};
