class Solution {
    static constexpr int ENGLISH_LETTERS = 26;

   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        // Fixed array for counting char frequencies
        std::array<int, ENGLISH_LETTERS> count;
        int len = static_cast<int>(s.size());

        // Record freqencies across both strings
        for (int i = 0; i < len; ++i) {
            ++count[s[i] - 'a'];
            --count[t[i] - 'a'];
        }

        for (int i = 0; i < ENGLISH_LETTERS; ++i) {
            if (count[i] != 0) return false;
        }

        return true;
    }
};
