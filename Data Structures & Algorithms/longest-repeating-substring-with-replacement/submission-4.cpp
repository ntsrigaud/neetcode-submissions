class Solution {
    static constexpr size_t ENG_LETTERS = 26;

   public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int max_len = 0;
        // Record the occurrence of each window chars
        std::array<int, ENG_LETTERS> count{0};

        // Window validity check
        auto isWindowValid = [&](int left, int right) -> bool {
            // Window is valid only if win_len - count[most_freq_char] <= k
            auto win_len = right - left + 1;

            // Find the most frequent character -> O(26) -> O(1)
            int max_count = 0;
            for (size_t c = 0; c < count.size(); ++c) {
                max_count = std::max(max_count, count[c]);
            }

            return win_len - max_count <= k;
        };

        for (int right = 0; right < static_cast<int>(s.length()); ++right) {
            ++count[s[right] - 'A'];
            // Shift left ptr until window is valid
            while (left < right && !isWindowValid(left, right)) {
                --count[s[left] - 'A'];
                ++left;
            }

            max_len = std::max(max_len, right - left + 1);
        }

        return max_len;
    }
};
