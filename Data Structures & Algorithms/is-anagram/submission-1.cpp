class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        std::unordered_map<char, int> count;

        for (const char c : s) ++count[c];

        for (const char c : t) {
            if (!count.contains(c) || count[c] == 0) return false;
            --count[c];
        }

        return true;
    }
};
