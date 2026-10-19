class Solution {
   public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = static_cast<int>(nums.size()) - 1;
        int res = nums.front();

        while (low <= high) {
            // End if sub-array is sorted
            if (nums[low] < nums[high]) return std::min(res, nums[low]);

            const int mid = low + (high - low) / 2;
            res = std::min(res, nums[mid]);
            if (nums[mid] >= nums[low]) {
                low = mid + 1;  // Search right
            } else
                high = mid - 1;  // Search left
        }

        return res;
    }
};
