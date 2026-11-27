class Solution {
    static constexpr char VISITED = '\0';

public:
    bool exist(vector<vector<char>>& board, string word) {
        const int rows = static_cast<int>(board.size());
        const int cols = static_cast<int>(board.front().size());

        // Edge case -> Cannot fit in board
        if (word.size() > static_cast<size_t>(rows * cols))
            return false;

        auto backtrack = [&](auto&& self, int r, int c, size_t idx) -> bool {
            // Base cases -> Word completely found or not
            if (board[r][c] != word[idx])
                return false;
            if (idx + 1 == word.size())
                return true; // The end

            const char last_visited = board[r][c];
            board[r][c] = VISITED; // Mark in-place

            const bool found =
                (r > 0 && self(self, r - 1, c, idx + 1)) ||
                (r + 1 < rows && self(self, r + 1, c, idx + 1)) ||
                (c > 0 && self(self, r, c - 1, idx + 1)) ||
                (c + 1 < cols && self(self, r, c + 1, idx + 1));

            board[r][c] = last_visited; // Restore cell on backtrack
            return found;
        };

        // Try every board position as starting point
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c)
                if (backtrack(backtrack, r, c, 0))
                    return true;
        }

        return false; // Not found
    }
};
