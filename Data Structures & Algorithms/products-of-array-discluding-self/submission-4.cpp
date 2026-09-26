class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // result[i] = prefix[i - 1] * postfix[i + 1]
        const int len = static_cast<int>(nums.size());

        std::vector<int> result(len, 1); // Init vals for product result

        // Accumulate the prefixes into result directly
        int prefix = 1;
        for (int i = 0; i < len; ++i) {
            result[i] = prefix;
            prefix *= nums[i];
        }

        // Accumulate postfixes while computing final results
        int postfix = 1;
        for (int i = len - 1; i >= 0; --i) {
            result[i] *= postfix;
            postfix *= nums[i];
        }

        return result;
    }
};
