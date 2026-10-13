class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> result(temperatures.size(), 0);

        // Monotonic decreasing stack -> {temp, idx}
        std::stack<std::pair<int, int>> st;
        for (size_t i = 0; i < temperatures.size(); ++i) {
            // Compute range and update stack
            while (!st.empty() && temperatures[i] > st.top().first) {
                const int n_days = i - st.top().second;
                result[st.top().second] = n_days;
                st.pop();
            }
            st.push({temperatures[i], i});
        }

        return result;
    }
};
