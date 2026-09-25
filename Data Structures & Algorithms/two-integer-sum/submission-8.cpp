class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = static_cast<int>(nums.size());

        // Store val & index of each elt
        std::unordered_map<int, int> seen;
        seen.reserve(len);

        for (int i = 0; i < len; ++i) {
            // Check if complement is available
            int comp = target - nums[i];

            auto it = seen.find(comp);
            if (it != seen.end()) {
                return {it->second, i};
            }

            // Insert after checking to prevent self-matching & dups
            seen.insert({nums[i], i});
        }

        return {};  // Should not be reached
    }
};
