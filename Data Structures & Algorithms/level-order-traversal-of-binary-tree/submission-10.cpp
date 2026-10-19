class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        std::queue<TreeNode*> queue;
        std::vector<std::vector<int>> result;
        queue.push(root);

        while (!queue.empty()) {
            int levelSize = queue.size();
            std::vector<int> level;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = queue.front();
                queue.pop();

                level.push_back(node->val);

                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
            result.push_back(level);
        }
        return result;
    }
};
