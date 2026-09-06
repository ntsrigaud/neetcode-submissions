class Solution {
   public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;

        int low = 0;
        int high = static_cast<int>(nums.size()) - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (target == nums[mid]) return mid;

            // Determine which sorted portion should we move to
            if (nums[mid] > nums[high]) {
                // Left sorted portion
                if (target > nums[mid] || target < nums[mid] && target < nums[low]) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            } else {
                // Right sorted portion
                if (target < nums[mid] || target > nums[mid] && target > nums[high]) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
        }

        return nums[low] == target ? low : -1;
    }
};
