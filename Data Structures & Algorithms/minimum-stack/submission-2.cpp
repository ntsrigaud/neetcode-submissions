class MinStack {
    std::stack<int> st;
    std::stack<int> min_values;  // Keep track of min values

   public:
    MinStack() = default;

    void push(int val) {
        st.push(val);
        if (min_values.empty() || val <= min_values.top()) {
            min_values.push(val);
        }
    }

    void pop() {
        if (st.empty()) {
            return;
        }

        // Pop min values only if it matches the current top
        if (st.top() == min_values.top()) {
            min_values.pop();
        }

        st.pop();
    }

    int top() { return st.top(); }

    int getMin() { return min_values.top(); }
};
