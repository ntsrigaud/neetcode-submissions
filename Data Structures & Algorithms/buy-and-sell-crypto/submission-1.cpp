class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t left = 0;
        size_t right = 0;
        int max_profit = 0;

        while (right < prices.size()) {
            if (prices[left] < prices[right]) {
                max_profit = std::max(max_profit, prices[right] - prices[left]);
            } else {
                // Found a lower buying price
                left = right;
            }
            ++right;
        }

        return max_profit;
    }
};
