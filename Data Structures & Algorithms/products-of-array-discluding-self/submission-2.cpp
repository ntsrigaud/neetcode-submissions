class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int running_prod = 1;
        std::vector<int> running_prefix(nums.size(), 1);
        std::vector<int> running_suffix(nums.size(), 1);

        // Product of all elements i is the product of all elts on the left x elts on the right
        // Thus we can have a pass on the left for the prefixes
        for (size_t i = 0; i < nums.size(); ++i) {
            running_prefix[i] = running_prod;
            running_prod *= nums[i];
        }

        // Then a pass from the right for the suffixes
        running_prod = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            running_suffix[i] = running_prod;
            running_prod *= nums[i];
        }

        // Compute final product of left and right
        for (size_t i = 0; i < nums.size(); ++i) {
            nums[i] = running_prefix[i] * running_suffix[i];
        }

        return nums;
    }
};
