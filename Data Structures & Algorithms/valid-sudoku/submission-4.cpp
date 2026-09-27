class Solution {
    static constexpr int N_DIGITS = 10;
    static constexpr int B_SIZE = 9;
    static constexpr char EMPTY = '.';

   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows, colums and 3x3 grids using hash set
        std::unordered_set<int> seen;
        seen.reserve(N_DIGITS);

        // Rows check
        for (int row = 0; row < B_SIZE; ++row) {
            seen.clear();
            for (int col = 0; col < B_SIZE; ++col) {
                const char ch = board[row][col];
                if (ch == EMPTY) continue;

                const int val = ch - '0';
                if (seen.contains(val)) return false;
                seen.insert(val);
            }
        }

        // Colums check
        for (int col = 0; col < B_SIZE; ++col) {
            seen.clear();
            for (int row = 0; row < B_SIZE; ++row) {
                const char ch = board[row][col];
                if (ch == EMPTY) continue;

                const int val = ch - '0';
                if (seen.contains(val)) return false;
                seen.insert(val);
            }
        }

        auto isValidGrid = [&](int r, int c) -> bool {
            seen.clear();
            for (int i = r; i < r + 3; ++i) {
                for (int j = c; j < c + 3; ++j) {
                    const char ch = board[i][j];
                    if (ch == EMPTY) continue;

                    const int val = ch - '0';
                    if (seen.contains(val)) return false;
                    seen.insert(val);
                }
            }

            return true;
        };

        // 3x3 Grid checks
        for (int r = 0; r < B_SIZE; r += 3) {
            for (int c = 0; c < B_SIZE; c += 3) {
                // Check a single grid
                if (!isValidGrid(r, c)) return false;
            }
        }

        return true;
    }
};
