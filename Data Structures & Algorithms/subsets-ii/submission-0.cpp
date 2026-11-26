class Solution {
   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Pre-allocate 2^N space to avoid alloc overhead
        std::vector<std::vector<int>> result;
        result.reserve(1ULL << nums.size());

        // Sort first to skip duplicates
        std::ranges::sort(nums);

        // Track current subset at each level
        std::vector<int> subset;
        subset.reserve(nums.size());  // no matter for the dups, alloc is worse

        auto backtrack = [&](auto&& self, size_t cur_pos) -> void {
            // Check for end of array
            if (cur_pos == nums.size()) {
                result.push_back(subset);
                return;
            }

            // Two decisions: included AND not included
            subset.push_back(nums[cur_pos]);
            self(self, cur_pos + 1);
            subset.pop_back();

            // IMPORTANT -> Skip all duplicates
            while (cur_pos + 1 < nums.size() && nums[cur_pos] == nums[cur_pos + 1]) ++cur_pos;

            self(self, cur_pos + 1);
        };

        backtrack(backtrack, 0);
        return result;
    }
};
