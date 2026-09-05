class Solution {
    static constexpr size_t LETTERS = 26;
    static constexpr char LOW_BOUND = 'a';

   public:
    bool checkInclusion(string s1, string s2) {
        int n1 = static_cast<int>(s1.length());
        int n2 = static_cast<int>(s2.length());
        if (n1 > n2) {
            return false;
        }

        // Initialize the first sliding window
        std::array<int, LETTERS> s1_count{0};
        std::array<int, LETTERS> s2_count{0};
        for (int i = 0; i < n1; ++i) {
            ++s1_count[s1[i] - LOW_BOUND];
            ++s2_count[s2[i] - LOW_BOUND];
        }

        if (s1_count == s2_count) {
            return true;
        }

        // Slide the window while updating the counts
        for (int right = n1; right < n2; ++right) {
            ++s2_count[s2[right] - LOW_BOUND];       // Track coming in
            --s2_count[s2[right - n1] - LOW_BOUND];  // Remove going out

            if (s1_count == s2_count) {
                return true;
            }
        }

        return false;
    }
};
