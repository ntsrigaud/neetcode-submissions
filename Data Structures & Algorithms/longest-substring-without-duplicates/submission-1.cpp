class Solution {
    static constexpr int N_CHARS = 256;
    static constexpr int UNSEEN = -1;

   public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int max_len = 0;
        std::array<int, N_CHARS> last_seen;
        last_seen.fill(UNSEEN);

        for (int right = 0; right < static_cast<int>(s.length()); ++right) {
            auto c_index = static_cast<unsigned char>(s[right]);

            // Check if seen in current window
            if (last_seen[c_index] >= left) {
                left = last_seen[c_index] + 1;  // Jump at next occurrence
            }

            last_seen[c_index] = right;
            max_len = std::max(max_len, right - left + 1);
        }

        return max_len;
    }
};
