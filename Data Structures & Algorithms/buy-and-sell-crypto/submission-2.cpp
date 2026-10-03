class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        // Define the boundaries for buying and selling
        int low = 0;
        int high = 1;
        int max_profit = 0;
        int n_prices = static_cast<int>(prices.size());

        while (high < n_prices) {
            // Ensure that transaction is profitable
            if (prices[low] < prices[high]) {
                auto profit = prices[high] - prices[low];
                max_profit = std::max(max_profit, profit);
            } else {
                // Found the lowest price -> Shift to next lower price
                low = high;
            }

            ++high;
        }

        return max_profit;
    }
};
