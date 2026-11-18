class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        const auto target = nums.begin() + (k - 1);
        std::nth_element(nums.begin(), target, nums.end(), std::greater<int>{});
        return *target;
    }
};
