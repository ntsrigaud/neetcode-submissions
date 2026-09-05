class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        size_t left = 0;
        bool is_valid_letter = false;

        auto recordFreq = [](string s) -> std::unordered_map<char, int> {
            std::unordered_map<char, int> record;
            // Map each substr chars
            for (char c : s) {
                ++record[c];
            }

            return record;
        };

        auto record_s1 = recordFreq(s1);
        auto isValidWindow = [&](int left, int right) -> bool {
            auto win = recordFreq(s2.substr(left, right - left + 1));
            return record_s1 == win;
        };

        for (size_t right = s1.length() - 1; right < s2.length(); ++left, ++right) {
            if (isValidWindow(left, right)) {
                return true;
            }
        }

        return false;
    }
};
