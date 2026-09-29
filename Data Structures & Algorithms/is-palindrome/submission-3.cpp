class Solution {
public:
    bool isPalindrome(std::string s) {
        int left = 0;
        int right = static_cast<int>(s.size()) - 1;

        auto toLower = [](char ch) -> unsigned char {
            return std::tolower(static_cast<unsigned char>(ch));
        };

        while (left < right) {
            if (!std::isalnum(s[left]))
                ++left;
            else if (!std::isalnum(s[right]))
                --right;
            else if (toLower(s[left]) != toLower(s[right])) {
                return false;
            } else {
                ++left;
                --right;
            }
        }

        return true;
    }
};