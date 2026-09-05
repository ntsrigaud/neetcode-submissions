class Solution {
    static constexpr size_t ENG_LETTERS = 26;

   public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int max_len = 0;
        int max_freq = 0;  // Remove redundant array lookup

        // Record the occurrence of each window chars
        std::array<int, ENG_LETTERS> count{0};

        for (int right = 0; right < static_cast<int>(s.length()); ++right) {
            max_freq = std::max(max_freq, ++count[s[right] - 'A']);

            // Shift left ptr until window is valid
            while ((right - left + 1) - max_freq > k) {
                --count[s[left] - 'A'];
                ++left;
            }

            max_len = std::max(max_len, right - left + 1);
        }

        return max_len;
    }
};
