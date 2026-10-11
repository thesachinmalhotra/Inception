class Solution {
   private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) return p == q;

        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

   public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;

        if (!root) return false;

        if (isSameTree(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};