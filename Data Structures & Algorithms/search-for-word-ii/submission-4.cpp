class Solution {
   private:
    struct Node {
        Node* children[26]{};
        string word;
    };

    Node* root = new Node();
    vector<string> result;

    void insert(const string& word) {
        Node* curr = root;

        for (char ch : word) {
            int i = ch - 'a';

            if (!curr->children[i]) curr->children[i] = new Node();

            curr = curr->children[i];
        }
        
        curr->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, Node* parent) {
        char ch = board[r][c];
        Node* curr = parent->children[ch - 'a'];

        if (!curr) return;

        if (!curr->word.empty()) {
            result.push_back(curr->word);
            curr->word.clear();
        }

        board[r][c] = '#';

        int rows = board.size();
        int cols = board[0].size();

        if (r > 0 && board[r - 1][c] != '#') dfs(board, r - 1, c, curr);

        if (r + 1 < rows && board[r + 1][c] != '#') dfs(board, r + 1, c, curr);

        if (c > 0 && board[r][c - 1] != '#') dfs(board, r, c - 1, curr);

        if (c + 1 < cols && board[r][c + 1] != '#') dfs(board, r, c + 1, curr);

        board[r][c] = ch;

        if (curr->word.empty()) {
            bool empty = true;

            for (Node* child : curr->children) {
                if (child) {
                    empty = false;
                    break;
                }
            }

            if (empty) parent->children[ch - 'a'] = nullptr;
        }
    }


public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (const string& word : words) insert(word);

        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                dfs(board, r, c, root);
            }
        }
        return result;
    }
};
