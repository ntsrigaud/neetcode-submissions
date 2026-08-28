class Solution {
    static constexpr char SEP = '#';

   public:
    string encode(vector<string>& strs) {
        std::string result;

        for (size_t i = 0; i < strs.size(); ++i) {
            result += to_string(strs[i].size()) + SEP + strs[i];
        }

        return result;
    }

    vector<string> decode(string s) {
        size_t i = 0;
        size_t j = 0;
        int len = 0;
        std::vector<std::string> strs;

        while (i < s.size()) {
            j = s.find(SEP, i);
            len = std::stoi(s.substr(i, j - i));
            strs.emplace_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }

        return strs;
    }
};
