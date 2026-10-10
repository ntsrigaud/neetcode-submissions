class Solution {
   public:
    bool isValid(string s) {
        if (s.size() % 2) return false;

        auto isMatched = [](const char a, const char b) -> bool {
            return a == '(' && b == ')' || a == '{' && b == '}' || a == '[' && b == ']';
        };

        auto isOpenBracket = [](const char ch) -> bool {
            return ch == '(' || ch == '{' || ch == '[';
        };

        std::stack<char> st;
        for (const char ch : s) {
            if (isOpenBracket(ch))
                st.push(ch);
            else if (st.empty() || !isMatched(st.top(), ch))
                return false;
            else
                st.pop();
        }

        return st.empty();
    }
};
