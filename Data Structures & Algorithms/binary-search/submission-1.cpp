class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int median = 0;

        while (left <= right) {
            median = left + (right - left) / 2;

            if (target == nums[median]) {
                return median;
            } else if (target < nums[median]) {
                right = median - 1;
            } else {
                left = median + 1;
            }
        }

        return -1;
    }
};
