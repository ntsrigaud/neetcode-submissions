class Solution {
   public:
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> cur_part;
        result.reserve(1ULL << (s.size() - 1));  // At most 2^(N-1) partitions (gaps)
        cur_part.reserve(s.size());

        auto isPalindrome = [&](size_t i, size_t j) -> bool {
            while (i < j && s[i] == s[j]) {
                ++i;
                --j;
            }

            return i >= j;  // Checks both odd & even palindromes
        };

        // Backtracking with recursive DFS
        auto dfs = [&](auto&& self, size_t start) -> void {
            // Base case -> completed partition
            if (start >= s.size()) {
                result.push_back(cur_part);
                return;
            }

            // Check each substring range for valid palindromes
            for (size_t end = start; end < s.size(); ++end) {
                if (isPalindrome(start, end)) {
                    cur_part.emplace_back(s.substr(start, end - start + 1));
                    self(self, end + 1);  // Find rest of cur partition
                    cur_part.pop_back();  // Backtrack
                }
            }
        };

        dfs(dfs, 0);
        return result;
    }
};
