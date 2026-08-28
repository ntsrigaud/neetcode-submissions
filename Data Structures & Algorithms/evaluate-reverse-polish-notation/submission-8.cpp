class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> s;
        int a = 0;
        int b = 0;
        int res = 0;

        auto getValue = [](const std::string& s) -> int {
            int v = 0;

            for (char c : s) {
                if (std::isdigit(c)) {
                    v = v * 10 + (c - '0');
                }
            }
            return v;
        };

        auto compute = [&](char op) {
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();

            switch (op) {
                case '+':
                    res = b + a;
                    break;
                case '-':
                    res = b - a;
                    break;
                case '*':
                    res = b * a;
                    break;
                case '/':
                    res = b / a;
                    break;
                default:
                    break;
            }

            s.push(res);
        };

        for (const auto& str : tokens) {
            if (std::isdigit(str.front())) {
                s.push(getValue(str));
            } else if (str.front() == '-' && str.size() > 1) {
                s.push(-getValue(str));
            } else {
                compute(str.front());
            }
        }

        return s.top();
    }
};
