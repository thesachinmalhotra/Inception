class Solution {
public:
    bool isValidSudoku(const std::vector<std::vector<char>>& board) {
        std::array<std::array<bool, 9>, 9> rows{};
        std::array<std::array<bool, 9>, 9> column{};
        std::array<std::array<bool, 9>, 9> boxes{};

        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                const char value = board[row][col];

                if (value == '.') {
                    continue;
                }
                const int digit = value - '1';
                const int box = (row/3) * 3 + (col/3);

                if (rows[row][digit] || column[col][digit] || boxes[box][digit]) {
                    return false;
                }
                rows[row][digit] = true;
                column[col][digit] = true;
                boxes[box][digit] = true;
            }
        }
        return true;
    }
};
