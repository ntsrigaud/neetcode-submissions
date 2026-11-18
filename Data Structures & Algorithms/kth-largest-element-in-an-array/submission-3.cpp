class Solution {
    int quickSelect(std::vector<int>& nums, int l, int r, int k) {
        int pivot = nums[r];
        int ptr = l;

        // Partition the array
        for (int i = l; i < r; ++i) {
            if (nums[i] <= pivot) {
                std::swap(nums[ptr], nums[i]);
                ++ptr;
            }
        }

        // Swapping rightmost value with val at ptr
        std::swap(nums[r], nums[ptr]);

        // Check for solution
        if (ptr > k) {
            // Not found yet -> Run on the left portion
            return quickSelect(nums, l, ptr - 1, k);
        } else if (ptr < k) {
            return quickSelect(nums, ptr + 1, r, k);
        } else
            return nums[ptr];
    }

   public:
    int findKthLargest(vector<int>& nums, int k) {
        // Update k to be the index of the element we're looking for
        k = static_cast<int>(nums.size()) - k;
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};
