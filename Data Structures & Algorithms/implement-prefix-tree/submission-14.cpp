class PrefixTree {
   private:
    struct Node {
        Node* children[26]{};
        bool isEnd = false;
    };

    Node* root = new Node();

   public:
    PrefixTree() {}

    void insert(string word) {
        Node* curr = root;

        for (char ch : word) {
            int i = ch - 'a';

            if (!curr->children[i]) curr->children[i] = new Node();
            curr = curr->children[i];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        Node* curr = root;

        for (char ch : word) {
            int i = ch - 'a';

            if (!curr->children[i]) return false;
            curr = curr->children[i];
        }
        return curr->isEnd;
    }

    bool startsWith(string prefix) {
        Node* curr = root;

        for (char ch : prefix) {
            int i = ch - 'a';

            if (!curr->children[i]) return false;
            curr = curr->children[i];
        }
        return true;
    }
};
