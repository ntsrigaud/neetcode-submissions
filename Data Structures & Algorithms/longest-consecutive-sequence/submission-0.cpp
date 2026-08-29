class Solution {
   public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }

        std::ranges::sort(nums);
        size_t max_count = 0;
        size_t count = 1;
        size_t diff = 0;

        for (size_t i = 1; i < nums.size(); ++i) {
            diff = nums[i] - nums[i - 1];
            if (diff <= 1) {
                count += diff;
            } else {
                max_count = std::max(count, max_count);
                count = 1;
            }
        }
        max_count = std::max(count, max_count);

        return static_cast<int>(max_count);
    }
};
