class MinStack {
    std::stack<int> st;
    std::stack<int> min_values;  // Keep track of min values

   public:
    MinStack() {
        // Clear existing stack
        while (!st.empty()) {
            st.pop();
        }

        while (!min_values.empty()) {
            min_values.pop();
        }
    }

    void push(int val) {
        st.push(val);
        min_values.push(min_values.empty() || val < min_values.top() ? val : min_values.top());
    }

    void pop() {
        st.pop();
        min_values.pop();
    }

    int top() { return st.top(); }

    int getMin() { return min_values.top(); }
};
