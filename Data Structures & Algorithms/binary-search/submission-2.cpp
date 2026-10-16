class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = static_cast<int>(nums.size()) - 1;

        while (low <= high) {
            const int mid = low + (high - low) / 2;
            const int mid_val = nums[mid];
            if (mid_val == target)
                return mid;
            else if (mid_val < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};
