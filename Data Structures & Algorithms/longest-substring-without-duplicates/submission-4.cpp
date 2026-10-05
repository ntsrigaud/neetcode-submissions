class Solution {
    static constexpr int N_CHARS = 256;
    static constexpr int UNSEEN = -1;

   public:
    int lengthOfLongestSubstring(string s) {
        // Track the last seen position of each characters in window
        std::array<int, N_CHARS> last_seen;
        last_seen.fill(UNSEEN);

        int max_len = 0;
        int low = 0;
        int n = static_cast<int>(s.size());

        for (int high = 0; high < n; ++high) {
            const auto ch = static_cast<unsigned char>(s[high]);

            if (last_seen[ch] >= low) {
                // Invalid for window -> Next substring
                low = last_seen[ch] + 1;  // Jump past duplicate
            }

            last_seen[ch] = high;
            max_len = std::max(max_len, high - low + 1);
        }

        return max_len;
    }
};
