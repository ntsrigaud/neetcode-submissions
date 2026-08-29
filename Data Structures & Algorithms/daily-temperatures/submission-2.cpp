class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> result(temperatures.size(), 0);
        std::stack<int> st;

        for (size_t i = 0; i < temperatures.size(); ++i) {
            // Compute the days before finding warmer temp
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                result[st.top()] = i - st.top();
                st.pop();
            }

            st.push(i);
        }

        return result;
    }
};
