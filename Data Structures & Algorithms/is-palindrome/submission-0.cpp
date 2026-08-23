class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        char left = 0;
        char right = 0;
        
        while(i < j) {
            while (i < j && std::isalnum(s[i]) == 0) {
                ++i;
            }

            while (i < j && std::isalnum(s[j]) == 0) {
                --j;
            }

            char left = std::tolower(s[i]);
            char right = std::tolower(s[j]);
            if (left != right) {
                return false;
            } 

            ++i;
            --j;
        }

        return true;
    }
};
