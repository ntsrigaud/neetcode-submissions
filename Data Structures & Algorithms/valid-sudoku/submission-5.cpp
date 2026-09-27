class Solution {
    static constexpr int B_SIZE = 9;
    static constexpr char EMPTY = '.';

   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Bitmasks tracking seen numbers
        std::array<int, B_SIZE> rows{};
        std::array<int, B_SIZE> cols{};
        std::array<int, B_SIZE> boxes{};

        // Check everything in one go
        for (int r = 0; r < B_SIZE; ++r) {
            for (int c = 0; c < B_SIZE; ++c) {
                const char val = board[r][c];

                // Ignore empty cells
                if (val == EMPTY) continue;

                // Map chars to their respective bit idx
                const int digit = val - '1';
                const int mask = 1 << digit;
                const int box_idx = (r / 3) * 3 + (c / 3);

                // Bitwise check for dups
                if ((rows[r] & mask) || (cols[c] & mask) || (boxes[box_idx] & mask)) {
                    return false;
                }

                // Mark digit as seen
                rows[r] |= mask;
                cols[c] |= mask;
                boxes[box_idx] |= mask;
            }
        }

        return true;
    }
};
