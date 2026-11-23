class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> cur;

        auto dfs = [&](auto&& self, size_t i, int total) -> void {
            // Base cases -> Stop the recursion for correct or exceeding sum
            if (total == target) {
                result.push_back(cur);
                return;
            }

            if (i >= nums.size() || total > target)
                return;

            // Two decisions for generating unique combinations
            // 1. Include current value
            cur.push_back(nums[i]);
            self(self, i, total + nums[i]);

            // 2. Skip current value
            cur.pop_back();
            self(self, i + 1, total);
        };

        dfs(dfs, 0, 0);
        return result;
    }
};
