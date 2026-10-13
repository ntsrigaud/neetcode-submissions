class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> result(temperatures.size(), 0);

        // Monotonic decreasing stack -> idx only is needed
        std::stack<int> st;
        for (size_t i = 0; i < temperatures.size(); ++i) {
            // Compute range and update stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                const int n_days = i - st.top();
                result[st.top()] = n_days;
                st.pop();
            }
            st.push(i);
        }

        return result;
    }
};
