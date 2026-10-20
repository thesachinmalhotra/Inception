class Solution {
   private:
    bool validate(TreeNode* node, long long minValue, long long maxValue) {
        if (!node) return true;

        if (node->val <= minValue || node->val >= maxValue) return false;

        return validate(node->left, minValue, node->val) &&
               validate(node->right, node->val, maxValue);
    }

   public:
    bool isValidBST(TreeNode* root) { return validate(root, LLONG_MIN, LLONG_MAX); }
};
