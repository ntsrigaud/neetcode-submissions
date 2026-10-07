#include <string>
#include <array>

class Solution {
   public:
    bool checkInclusion(const std::string& s1, const std::string& s2) {
        if (s1.size() > s2.size()) return false;

        // Zero-initialize character frequency arrays
        std::array<int, 26> s1_count{};
        std::array<int, 26> s2_count{};

        // 1. Fill frequency counts for s1 and the initial s2 window
        for (size_t i = 0; i < s1.size(); ++i) {
            ++s1_count[s1[i] - 'a'];
            ++s2_count[s2[i] - 'a'];
        }

        // 2. Compute initial character match count across all 26 letters
        int matches = 0;
        for (int i = 0; i < 26; ++i) {
            if (s1_count[i] == s2_count[i]) {
                ++matches;
            }
        }

        // 3. Slide fixed-size window of length s1.size() across s2
        size_t low = 0;
        for (size_t high = s1.size(); high < s2.size(); ++high) {
            if (matches == 26) return true;

            // Add incoming character s2[high]
            const int r_idx = s2[high] - 'a';
            if (s1_count[r_idx] == s2_count[r_idx]) --matches;
            ++s2_count[r_idx];
            if (s1_count[r_idx] == s2_count[r_idx]) ++matches;

            // Remove outgoing character s2[low]
            const int l_idx = s2[low] - 'a';
            if (s1_count[l_idx] == s2_count[l_idx]) --matches;
            --s2_count[l_idx];
            if (s1_count[l_idx] == s2_count[l_idx]) ++matches;

            ++low;
        }

        return matches == 26;
    }
};