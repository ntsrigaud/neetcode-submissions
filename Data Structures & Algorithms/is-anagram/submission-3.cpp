class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        std::unordered_map<char, int> count;
        for (char ch : s) ++count[ch];

        for (char ch : t) {
            --count[ch];
            if (count[ch] < 0) return false;
        }

        for (const auto & [k, v] : count) {
            if (v != 0) return false;
        }

        return true;
    }
};
