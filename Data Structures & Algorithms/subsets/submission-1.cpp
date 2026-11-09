class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        function<void(int)> backtrack = [&](int index) {
            if (index == nums.size()) {
                result.push_back(current);
                return;
            }

            current.push_back(nums[index]);
            backtrack(index + 1);

            current.pop_back();

            backtrack(index + 1);
        };

        backtrack(0);
        return result;
    }
};
