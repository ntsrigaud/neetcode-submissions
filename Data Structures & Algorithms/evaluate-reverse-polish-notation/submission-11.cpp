class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        int result = 0;
        std::stack<int> record;

        auto isOperator = [](const std::string& token) -> bool {
            return token == "+" || token == "-" || token == "*" || token == "/";
        };

        auto compute = [](const int a, const char op, const int b) -> int {
            switch (op) {
                case '+':
                    return a + b;
                case '-':
                    return a - b;
                case '*':
                    return a * b;
                case '/':
                    if (b != 0) return a / b;
                default:
                    return INT_MAX;  // Should not be reached;
            }
        };

        for (const auto& token : tokens) {
            if (isOperator(token)) {
                char op = token.front();

                const int r_operand{record.top()};
                record.pop();

                int l_operand{record.top()};
                record.pop();

                l_operand = compute(l_operand, op, r_operand);
                record.push(l_operand);
            } else {
                record.push(std::stoi(token));
            }
        }

        return record.top();
    }
};
