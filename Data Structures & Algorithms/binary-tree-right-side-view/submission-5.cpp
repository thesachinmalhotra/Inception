class Solution {
   public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)  return {};

        std::queue<TreeNode*> queue;
        std::vector<int> result;
        queue.push(root);

        while (!queue.empty()) {
            int levelSize = queue.size();

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = queue.front();
                queue.pop();

                if (i == levelSize - 1) result.push_back(node->val);

                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
        }
        return result;
    }
};
