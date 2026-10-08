#include <string>
#include <unordered_map>
#include <climits>

class Solution {
public:
    std::string minWindow(const std::string& s, const std::string& t) {
        if (t.empty() || s.empty()) return "";

        std::unordered_map<char, int> count_t;
        std::unordered_map<char, int> win;

        for (const char ch : t) ++count_t[ch];

        int have = 0;
        const int need = static_cast<int>(count_t.size());

        const int n = static_cast<int>(s.size());
        int res_start = -1;
        int res_len = INT_MAX;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            const char ch = s[right];
            ++win[ch];

            // Found a match
            if (count_t.contains(ch) && win[ch] == count_t[ch]) {
                ++have;
            }

            // Shrink window while all requirements are satisfied
            while (have == need) {
                const int cur_len = right - left + 1;
                if (cur_len < res_len) {
                    res_len = cur_len;
                    res_start = left;
                }

                const char l_ch = s[left];
                --win[l_ch];

                // If removing s[left] violates requirement, decrease 'have'
                if (count_t.contains(l_ch) && win[l_ch] < count_t[l_ch]) {
                    --have;
                }

                ++left;
            }
        }

        return res_len == INT_MAX ? "" : s.substr(res_start, res_len);
    }
};