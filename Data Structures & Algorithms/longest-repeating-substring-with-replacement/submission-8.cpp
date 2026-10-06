class Solution {
public:
    int characterReplacement(string s, int k) {
        // Occurences of each character
        std::unordered_map<char, int> freq;
        int max_subs_len = 0;

        int n = static_cast<int>(s.size());
        int low = 0;
        int max_freq = 0;
        for (int high = 0; high < n; ++high) {
            const char key = s[high];
            ++freq[key];

            // Track maximum frequency
            max_freq = std::max(max_freq, freq[key]);

            // Ensure current window is valid
            while ((high - low + 1) - max_freq > k) {
                // Shift the window until valid
                --freq[s[low]];
                ++low;
            }

            max_subs_len = std::max(max_subs_len, high - low + 1);
        }

        return max_subs_len;
    }
};
