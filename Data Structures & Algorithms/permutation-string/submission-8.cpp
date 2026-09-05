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

        // Hash both strings for 1rst window
        std::array<int, LETTERS> s1_count{0};
        std::array<int, LETTERS> s2_count{0};
        for (int i = 0; i < n1; ++i) {
            ++s1_count[s1[i] - LOW_BOUND];
            ++s2_count[s2[i] - LOW_BOUND];
        }

        // Track the number of matches for window size
        size_t matches = 0;
        for (size_t i = 0; i < LETTERS; ++i) {
            matches += s1_count[i] == s2_count[i];
        }

        auto updateMatches = [&](int idx, bool outgoing = false) -> void {
            if (s1_count[idx] == s2_count[idx]) {
                ++matches;
            } else if ((outgoing && s1_count[idx] - 1 == s2_count[idx]) ||
                       (!outgoing && s1_count[idx] + 1 == s2_count[idx])) {
                --matches;  // Made the occurrence smaller or larger
            }
        };

        // Slide the window while updating and checking the matches
        int left = 0;
        for (int right = n1; right < n2; ++right) {
            if (matches == LETTERS) {
                return true;
            }

            // Track incoming letter
            auto idx = s2[right] - LOW_BOUND;
            ++s2_count[idx];
            updateMatches(idx);

            // Remove outgoing letter
            idx = s2[left] - LOW_BOUND;
            --s2_count[idx];
            updateMatches(idx, true);

            ++left;  // Keep window size constant
        }

        return matches == LETTERS;
    }
};
