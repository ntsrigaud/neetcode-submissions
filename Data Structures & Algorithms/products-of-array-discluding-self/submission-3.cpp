class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int running_prod = 1;
        int n = static_cast<int>(nums.size());
        std::vector<int> res(n, 1);

        // Product of all elements i is the product of all elts on the left x elts on the right
        // Thus we can have a pass on the left for the prefixes
        for (size_t i = 0; i < nums.size(); ++i) {
            res[i] = running_prod;
            running_prod *= nums[i];
        }

        // Then a pass from the right for the suffixes
        // And compute final product of left and right
        running_prod = 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] *= running_prod;
            running_prod *= nums[i];
        }

        return res;
    }
};
