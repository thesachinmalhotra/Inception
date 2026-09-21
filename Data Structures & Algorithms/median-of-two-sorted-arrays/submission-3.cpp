class Solution {
   public:
    double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        const int m = nums1.size();
        const int n = nums2.size();

        const int leftSize = (m + n + 1) / 2;

        int left = 0;
        int right = m;

        while (left <= right) {
            const int partition1 = left + (right - left) / 2;
            const int partition2 = leftSize - partition1;

            const int nums1Left = partition1 == 0 ? INT_MIN : nums1[partition1 - 1];

            const int nums1Right = partition1 == m ? INT_MAX : nums1[partition1];

            const int nums2Left = partition2 == 0 ? INT_MIN : nums2[partition2 - 1];

            const int nums2Right = partition2 == n ? INT_MAX : nums2[partition2];

            if (nums1Left <= nums2Right && nums2Left <= nums1Right) {
                if ((m + n) % 2 == 1) return std::max(nums1Left, nums2Left);

                return (std::max(nums1Left, nums2Left) + std::min(nums1Right, nums2Right)) / 2.0;
            }

            if (nums1Left > nums2Right)
                right = partition1 - 1;
            else
                left = partition1 + 1;
        }

        return 0.0;
    }
};