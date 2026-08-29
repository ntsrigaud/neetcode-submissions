class Solution {
    static constexpr char DOT = '.';
    static constexpr size_t GRID_SIZE = 3;

   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        size_t i = 0;
        size_t j = 0;
        std::unordered_set<char> map;

        auto updateMap = [&](size_t r, size_t c) -> bool {
            if (board[r][c] != DOT && map.contains(board[r][c])) {
                return false;
            } else {
                map.insert(board[r][c]);
            }

            return true;
        };

        auto areValidRows = [&]() -> bool {
            for (i = 0; i < board.size(); ++i) {
                map.clear();
                for (j = 0; j < board.size(); ++j) {
                    if (!updateMap(i, j)) {
                        return false;
                    }
                }
            }

            return true;
        };

        auto areValidColumns = [&]() -> bool {
            for (i = 0; i < board.size(); ++i) {
                map.clear();
                for (j = 0; j < board.size(); ++j) {
                    if (!updateMap(j, i)) {
                        return false;
                    }
                }
            }

            return true;
        };

        auto areValid3x3Grids = [&]() -> bool {
            auto isValidGrid = [&](size_t r_start, size_t c_start) -> bool {
                map.clear();
                for (size_t i = r_start; i < r_start + GRID_SIZE; ++i) {
                    for (size_t j = c_start; j < c_start + GRID_SIZE; ++j) {
                        if (!updateMap(i, j)) {
                            return false;
                        }
                    }
                }

                return true;
            };

            for (i = 0; i < board.size(); i = i + GRID_SIZE) {
                for (j = 0; j < board.size(); j = j + GRID_SIZE) {
                    if (!isValidGrid(i, j)) {
                        return false;
                    }
                }
            }

            return true;
        };

        return areValidRows() && areValidColumns() && areValid3x3Grids();
    }
};
