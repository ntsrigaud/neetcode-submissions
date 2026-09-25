class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        std::ranges::sort(s);
        std::ranges::sort(t);

        return s == t;
    }
};
