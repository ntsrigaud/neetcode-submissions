class Solution {
public:
    bool isPalindrome(string s) {
        // Optimal solution: O(n) -> Complexity, O(1) -> Memory
        int left = 0;
        auto right = static_cast<int>(s.size()) - 1;

        auto isValid = [&](int idx) -> bool {
            return std::isalnum(static_cast<unsigned char>(s[idx]));
        };

        auto toLower = [](char ch) -> char {
            return static_cast<char>(
                std::tolower(static_cast<unsigned char>(ch)));
        };

        while (left < right) {
            // Determine which ptr to move if necessary first
            while (left < right && !isValid(left))
                ++left;

            while (left < right && !isValid(right))
                --right;

            // Case-insensitive comparison
            if (left < right) {
                if (toLower(s[left]) != toLower(s[right]))
                    return false;

                // Next comparison
                ++left;
                --right;
            }
        }

        return true;
    }
};
