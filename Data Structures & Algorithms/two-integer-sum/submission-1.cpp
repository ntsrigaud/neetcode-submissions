class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map all the values to check what misses to obtain the target
        std::unordered_map<int, int> val_idx;

        int n = static_cast<int>(nums.size());
        for (int i = 0; i < n; ++i) {
            auto comp = target - nums[i];
            if (val_idx.contains(comp)) return {val_idx[comp], i};

            // Save cur mapping for later comp checks
            val_idx[nums[i]] = i;
        }

        return {-1, -1};  // Invalid
    }
};
