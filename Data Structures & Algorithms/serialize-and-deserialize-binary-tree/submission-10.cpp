class Codec {
   private:
    void preorder(TreeNode* node, std::string& result) {
        if (!node) {
            result += "N,";
            return;
        }

        result += std::to_string(node->val) + ",";

        preorder(node->left, result);
        preorder(node->right, result);
    }

    TreeNode* build(const std::vector<std::string>& tokens, int& index) {
        if (tokens[index] == "N") {
            ++index;
            return nullptr;
        }

        int value = std::stoi(tokens[index]);
        ++index;

        TreeNode* node = new TreeNode(value);

        node->left = build(tokens, index);
        node->right = build(tokens, index);

        return node;
    }

   public:
    string serialize(TreeNode* root) {
        std::string result;
        preorder(root, result);
        return result;
    }

    TreeNode* deserialize(string data) {
        std::stringstream ss(data);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        int index = 0;
        return build(tokens, index);
    }
};
