class Solution {
   private:
    std::unordered_map<int, int> inorderIndex;
    int preorderIndex = 0;

    TreeNode* build(const std::vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;

        int value = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(value);

        int mid = inorderIndex[value];

        root->left = build(preorder, left, mid - 1);
        root->right = build(preorder, mid + 1, right);

        return root;
    }

   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inorderIndex.clear();
        preorderIndex = 0;

        for (int i = 0; i < static_cast<int>(inorder.size()); ++i) inorderIndex[inorder[i]] = i;

        return build(preorder, 0, static_cast<int>(inorder.size()) - 1);
    }
};
