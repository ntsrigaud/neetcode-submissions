class Solution {
    static constexpr int NOT_FOUND = -1;

   public:
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) return NOT_FOUND;

        int slow = 0;
        int fast = 0;

        // Detect the first intersection
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];  // Move twice fast
        } while (slow != fast);

        // Detect second intersection
        int slow2 = 0;
        do {
            slow = nums[slow];
            slow2 = nums[slow2];
        } while (slow != slow2);

        return slow;
    }
};
