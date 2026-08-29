class Solution {
    static constexpr char DOT = '.';
    static constexpr size_t GRID_SIZE = 3;
    static constexpr size_t BOARD_SIZE = 9;

   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        size_t c = 0;
        char cur_num = 0;
        std::array<std::unordered_set<char>, BOARD_SIZE> col_map;
        std::array<std::unordered_set<char>, BOARD_SIZE> row_map;
        std::array<std::unordered_set<char>, BOARD_SIZE> grid_map;

        for (size_t r = 0; r < board.size(); ++r) {
            for (c = 0; c < board.size(); ++c) {
                cur_num = board[r][c];
                if (cur_num == DOT) {
                    continue;
                } else if (row_map[r].contains(cur_num) || col_map[c].contains(cur_num) ||
                           grid_map[(c / 3) + (r / 3) * GRID_SIZE].contains(cur_num)) {
                    return false;
                } else {
                    row_map[r].insert(cur_num);
                    col_map[c].insert(cur_num);
                    grid_map[(c / 3) + (r / 3) * GRID_SIZE].insert(cur_num);
                }
            }
        }

        return true;
    }
};
