class Solution {
   public:
    bool isPalindrome(string s) {
        // Record only valid characters
        std::string new_str;

        for (char ch : s) {
            if (std::isalnum(ch)) new_str += std::tolower(ch);
        }

        // Compare new string with its reversed version
        std::string rev_str(new_str);
        std::reverse(new_str.begin(), new_str.end());

        return new_str == rev_str;
    }
};
