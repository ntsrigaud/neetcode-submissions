class Solution {
    static constexpr char DOT = '.';
    static constexpr size_t GRID_SIZE = 3;
    static constexpr size_t BOARD_SIZE = 9;

   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        size_t c = 0;
        size_t val = 0;
        int mask = 0;
        int grid_idx = 0;
        std::array<int, BOARD_SIZE> col_map{0};
        std::array<int, BOARD_SIZE> row_map{0};
        std::array<int, BOARD_SIZE> grid_map{0};

        for (size_t r = 0; r < board.size(); ++r) {
            for (c = 0; c < board.size(); ++c) {
                if (board[r][c] == DOT) {
                    continue;
                }

                val = board[r][c] - '1';  // Adjust index to 0-8
                mask = 1 << val;          // Create a bit mask for all 9 values
                grid_idx = (c / GRID_SIZE) + (r / GRID_SIZE) * GRID_SIZE;

                if ((row_map[r] & mask) || (col_map[c] & mask) || (grid_map[grid_idx] & mask)) {
                    return false;
                }

                // Update the bit masks
                row_map[r] |= mask;
                col_map[c] |= mask;
                grid_map[grid_idx] |= mask;
            }
        }

        return true;
    }
};