class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        result.reserve(1ULL << nums.size());  // Reserve 2^N subsets

        std::vector<int> subset;
        subset.reserve(nums.size());

        auto dfs = [&](auto&& self, size_t i) -> void {
            // i -> Value to decide on adding or not
            if (i >= nums.size()) {
                result.push_back(subset);
                return;
            }

            // Include nums[i]
            subset.push_back(nums[i]);

            self(self, i + 1);

            // Skip nums[i]
            subset.pop_back();
            self(self, i + 1);
        };

        dfs(dfs, 0);

        return result;
    }
};
