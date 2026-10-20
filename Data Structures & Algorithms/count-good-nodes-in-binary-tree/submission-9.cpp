class Solution {
   private:
    int goodNodesCount = 0;

    void dfs(TreeNode* node, int maxSoFar) {
        if (!node) return;

        if (node->val >= maxSoFar) ++goodNodesCount;

        maxSoFar = std::max(maxSoFar, node->val);

        dfs(node->left, maxSoFar);
        dfs(node->right, maxSoFar);
    }

   public:
    int goodNodes(TreeNode* root) {
        goodNodesCount = 0;
        dfs(root, INT_MIN);
        return goodNodesCount;
    }
};
