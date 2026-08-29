class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> result(temperatures.size(), 0);
        std::stack<std::pair<int, int>> st;

        for (size_t i = 0; i < temperatures.size(); ++i) {
            // Compute the days before finding warmer temp
            while (!st.empty() && st.top().first < temperatures[i]) {
                result[st.top().second] = i - st.top().second;
                st.pop();
            }

            st.push({temperatures[i], i});
        }

        return result;
    }
};
