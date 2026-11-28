class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.empty())
            return {{}};

        const size_t n = s.size();

        std::vector<std::vector<std::string>> result;
        std::vector<std::string> cur_part;

        result.reserve(1ULL << (n - 1)); // At most 2^(N-1) partitions (gaps)
        cur_part.reserve(n);

        // Perf -> O(N^2): Precompute 2D palindrome lookup table (DP Table)
        // Avoids repeated scan of same substrings across overlapping branches
        // uint8_t (1 byte) -> Faster access + compact L1 cache footprint
        std::vector<std::vector<uint8_t>> is_pal(n, std::vector<uint8_t>(n, 0));
        for (size_t len = 1; len <= n; ++len) {
            // Longer substrings depend on inner substrings being palindromes
            // Fill NxN grid diagonally from main diagonal outward
            for (size_t i = 0; i + len <= n; ++i) {
                const size_t j = i + len - 1;
                if (s[i] == s[j] && (len <= 2 || is_pal[i + 1][j - 1]))
                    is_pal[i][j] = 1;
            }
        }

        // Backtracking with recursive DFS
        auto dfs = [&](auto&& self, size_t start) -> void {
            // Base case -> completed partition
            if (start >= n) {
                result.push_back(cur_part);
                return;
            }

            // Check each substring range for valid palindromes
            for (size_t end = start; end < n; ++end) {
                if (is_pal[start][end]) {
                    cur_part.push_back(s.substr(start, end - start + 1));
                    self(self, end + 1); // Find rest of cur partition
                    cur_part.pop_back(); // Backtrack
                }
            }
        };

        dfs(dfs, 0);
        return result;
    }
};
