class Solution {
   public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) {
            return false;
        }

        std::stack<char> st;

        auto isOpenBracket = [](char c) -> bool { return c == '{' || c == '(' || c == '['; };

        auto areMatchedBrackets =
            [](char first, char second) {
                return (first == '{' && second == '}') || (first == '[' && second == ']') ||
                       (first == '(' && second == ')');
            };

        // Push the open brackets (half of the string)
        for (int i = 0; i < s.length(); ++i) {
            if (isOpenBracket(s[i])) {
                st.push(s[i]);
            } else if (!st.empty() && areMatchedBrackets(st.top(), s[i])) {
                st.pop();
            } else {
                return false;
            }
        }

        return st.empty();
    }
};
