class Solution {
   private:
    int maxSum = INT_MIN;

    int maxGain(TreeNode* node) {
        if (!node) return 0;

        int leftGain = std::max(0, maxGain(node->left));
        int rightGain = std::max(0, maxGain(node->right));

        int pathSum = node->val + leftGain + rightGain;
        maxSum = std::max(maxSum, pathSum);
        return node->val + std::max(leftGain, rightGain);
    }

   public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        maxGain(root);
        return maxSum;
    }
};
