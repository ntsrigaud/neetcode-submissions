class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        std::ranges::sort(nums);

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] == nums[i]) return true;
        }

        return false;
    }
};