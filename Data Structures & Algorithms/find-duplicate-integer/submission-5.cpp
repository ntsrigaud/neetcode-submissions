class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) return -1;

        size_t slow = 0;
        size_t fast = 0;

        // Find slow and fast intersection
        do {
            // Use array values as pointers
            slow = nums[slow];
            fast = nums[nums[fast]];  // Move twice fast
        } while (nums[slow] != nums[fast]);

        // Find second intersection of slow ptrs
        size_t slow2 = 0;
        while (nums[slow] != nums[slow2]) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }

        return nums[slow];
    }
};
