class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> cur;

        // Sort to group adjacent duplicates
        std::ranges::sort(candidates);

        auto dfs = [&](auto&& self, size_t i, int total) -> void {
            // Base cases when to stop the recursion
            if (total == target) {
                result.push_back(cur);
                return;
            }

            // When exceeding the target
            if (i == candidates.size() || total + candidates[i] > target) return;

            // Two decisions
            cur.push_back(candidates[i]);
            self(self, i + 1, total + candidates[i]);

            // Skip candidates[i]
            cur.pop_back();

            // Skip duplicates
            while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) ++i;

            self(self, i + 1, total);
        };

        dfs(dfs, 0, 0);
        return result;
    }
};
