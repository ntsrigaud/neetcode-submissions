class Solution {
   public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return -1;

        int low = 0;
        int high = static_cast<int>(nums.size()) - 1;

        while (low < high) {
            const auto mid = low + (high - low) / 2;

            // Determine whether in left or right sorted array
            if (nums[mid] > nums[high]) {
                low = mid + 1;  // Left portion -> Search right
            } else {
                high = mid;
            }
        }

        return nums[low];
    }
};
