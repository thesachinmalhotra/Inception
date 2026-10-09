class Solution {
   private:
    int diameter = 0;

    int maxDepth(TreeNode* node) {
        if (!node) return 0;

        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);

        diameter = std::max(diameter, leftDepth + rightDepth);

        return 1 + std::max(leftDepth, rightDepth);
    }

   public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);

        return diameter;
    }
};
