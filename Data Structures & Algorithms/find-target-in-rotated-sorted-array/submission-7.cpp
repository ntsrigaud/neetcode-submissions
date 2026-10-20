class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = static_cast<int>(nums.size()) - 1;

        while (low <= high) {
            const int mid = low + (high - low) / 2;
            const int mid_val = nums[mid];
            const int leftmost_val = nums[low];

            if (mid_val == target) return mid;

            // Where are we? Left or Right?
            if (leftmost_val <= mid_val) {
                // Left sorted portion
                if (target > mid_val || target < leftmost_val)
                    low = mid + 1;  // Search right
                else
                    high = mid - 1;  // Search right
            } else {
                // Right sorted portion
                if (target < mid_val || target > nums[high])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }

        return -1;  // Not found
    }
};
