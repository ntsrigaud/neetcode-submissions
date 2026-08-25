class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t i = 0;
        size_t j = 0;
        int prod = 1;
        std::vector<int> products(static_cast<int>(nums.size()), 0);

        // If you have at least two zero, all the answers are 0
        // If you have only one zero, all the answers except where it is are 0
        // So find how much zeros you have in this array
        int zero_count = 0;
        for (i = 0; i < nums.size() && zero_count < 2; ++i) {
            if (nums[i] == 0) {
                j = i;  // Mark first and maybe only zero
                ++zero_count;
            }
        }

        if (zero_count >= 2) {
            return products;
        }

        for (i = 0; i < nums.size(); ++i) {
            if (zero_count == 1 && i == j) {
                continue;  // Skip zero index since it would cancel the product
            }

            prod *= nums[i];
        }

        // If only one zero was found, everything else except at j is 0
        if (zero_count == 1) {
            products[j] = prod;
        } else {
            for (i = 0; i < nums.size(); ++i) {
                products[i] = prod / nums[i];
            }
        }

        return products;
    }
};
