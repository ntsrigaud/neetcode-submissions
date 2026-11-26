class Solution {
    static constexpr char OPEN = '(';
    static constexpr char CLOSED = ')';

   public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string current;
        current.reserve(2 * n);  // Avoid heap re-alloc overhead

        auto backtrack = [&](auto&& self, int open, int closed) -> void {
            if (open == closed && closed == n) {
                result.push_back(current);
                return;
            }

            // Add open parentheses first
            if (open < n) {
                current.push_back(OPEN);
                self(self, open + 1, closed);

                current.pop_back();
            }

            // Add closed if possible
            if (closed < open) {
                current.push_back(CLOSED);
                self(self, open, closed + 1);

                current.pop_back();
            }
        };

        backtrack(backtrack, 0, 0);
        return result;
    }
};
