class Solution {
    std::vector<std::vector<int>> getPerms(std::vector<int>& nums, size_t start) {
        if (start >= nums.size()) return {{}};

        // Record the different perms from bottom to top
        auto perms = getPerms(nums, start + 1);

        std::vector<std::vector<int>> result;

        // Insert cur elt at each positions from start to end
        for (auto& p : perms) {
            for (size_t i = 0; i <= p.size(); ++i) {
                // Make a copy to avoid changing the ref array
                auto p_copy = p;
                p_copy.insert(p_copy.begin() + i, nums[start]);
                result.emplace_back(std::move(p_copy));
            }
        }

        return result;
    }

   public:
    vector<vector<int>> permute(vector<int>& nums) { return getPerms(nums, 0); }
};
