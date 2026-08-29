class Solution {
    static constexpr char DOT = '.';
    static constexpr size_t GRID_SIZE = 3;
    static constexpr size_t BOARD_SIZE = 9;

   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        size_t c = 0;
        size_t cur_idx = 0;
        char cur_num = 0;
        std::array<std::array<bool, BOARD_SIZE>, BOARD_SIZE> col_map{false};
        std::array<std::array<bool, BOARD_SIZE>, BOARD_SIZE> row_map{false};
        std::array<std::array<bool, BOARD_SIZE>, BOARD_SIZE> grid_map{false};

        for (size_t r = 0; r < board.size(); ++r) {
            for (c = 0; c < board.size(); ++c) {
                cur_num = board[r][c];
                cur_idx = cur_num - '0' - 1;
                if (cur_num == DOT) {
                    continue;
                } else if (row_map[r][cur_idx] || col_map[c][cur_idx] ||
                           grid_map[(c / 3) + (r / 3) * GRID_SIZE][cur_idx]) {
                    return false;
                } else {
                    row_map[r][cur_idx] = true;
                    col_map[c][cur_idx] = true;
                    grid_map[(c / 3) + (r / 3) * GRID_SIZE][cur_idx] = true;
                }
            }
        }

        return true;
    }
};