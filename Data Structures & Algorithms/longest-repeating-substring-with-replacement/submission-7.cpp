class Solution {
   public:
    int characterReplacement(string s, int k) {
        // Occurences of each character
        std::unordered_map<char, int> freq;
        int max_subs_len = 0;

        auto getMaxFreq = [&]() -> int {
            int max_freq = 0;

            for (const auto& p : freq) max_freq = std::max(max_freq, p.second);

            return max_freq;
        };

        int n = static_cast<int>(s.size());
        int low = 0;
        for (int high = 0; high < n; ++high) {
            ++freq[s[high]];

            // Ensure current window is valid
            while ((high - low + 1) - getMaxFreq() > k) {
                // Shift the window until valid
                --freq[s[low]];
                ++low;
            }

            max_subs_len = std::max(max_subs_len, high - low + 1);
        }

        return max_subs_len;
    }
};
