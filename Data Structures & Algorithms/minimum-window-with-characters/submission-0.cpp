class Solution {
public:
    string minWindow(string s, string t) {
        // 1. Ensure that target string is not empty
        if (t.empty())
            return "";

        // 2. Init a map for target string for needed chars
        std::unordered_map<char, int> target_count;
        for (char ch : t)
            ++target_count[ch];

        // 3. Init a map for sliding window match
        std::unordered_map<char, int> window;

        // 4. Track the chars needed and obtained
        const int need = static_cast<int>(target_count.size());
        int obtained = 0;
        int n = static_cast<int>(s.size());

        // 5. Track resulting string length with LR sliding window bounds
        std::pair<int, int> res_idx = {-1, -1};
        int res_len = INT_MAX;

        // 6. Sliding window algorithm
        int l = 0;
        int r = 0;
        for (r = 0; r < n; ++r) {
            auto ch = s[r];
            ++window[ch];

            // Update tracked chars obtained if possible
            if (target_count.contains(ch) && window[ch] == target_count[ch])
                ++obtained;

            // Iteratively update and shrink result
            while (obtained == need) {
                auto res_size = r - l + 1;

                if (res_size < res_len) {
                    res_idx = {l, r};
                    res_len = res_size;
                }

                // Shrink from the left for shortest possible substring
                char left_ch = s[l];
                --window[left_ch];

                // Ensure window is valid for continuing
                if (target_count.contains(left_ch) &&
                    window[left_ch] < target_count[left_ch])
                    --obtained;
                ++l;
            }
        }

        // Collect result string
        return (res_len != INT_MAX)
                   ? std::string(s.begin() + res_idx.first,
                                 s.begin() + res_idx.second + 1)
                   : "";
    }
};
