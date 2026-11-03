class WordDictionary {
   private:
    struct Node {
        Node* children[26]{};
        bool isEnd = false;
    };

    Node* root = new Node();

    bool dfs(Node* node, const string& word, int index) {
        if (index == word.size()) return node->isEnd;

        char ch = word[index];

        if (ch == '.') {
            for (Node* child : node->children) {
                if (child && dfs(child, word, index + 1)) return true;
            }
            return false;
        }

        Node* child = node->children[ch - 'a'];

        return child && dfs(child, word, index + 1);
    }

   public:
    WordDictionary() {}

    void addWord(string word) {
        Node* curr = root;

        for (char ch : word) {
            int i = ch - 'a';

            if (!curr->children[i]) curr->children[i] = new Node();

            curr = curr->children[i];
        }
        
        curr->isEnd = true;
    }

    bool search(string word) { return dfs(root, word, 0); }
};
