class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        // Pre-alloc N! space capacity to avoid reallocation
        size_t total_perms = 1;
        for (size_t k = 2; k <= nums.size(); ++k)
            total_perms *= k;
        result.reserve(total_perms);

        // DFS
        auto getPerms = [&](auto&& self, size_t start) -> void {
            if (start == nums.size()) {
                result.push_back(nums);
                return;
            }

            for (size_t i = start; i < nums.size(); ++i) {
                // In-place permutation
                std::swap(nums[start], nums[i]);
                self(self, start + 1);
                std::swap(nums[start], nums[i]); // Backtrack
            }
        };

        getPerms(getPerms, 0);
        return result;
    }
};