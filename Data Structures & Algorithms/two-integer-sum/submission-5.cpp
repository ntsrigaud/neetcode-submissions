class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create a copy with stored index of nums for sorting
        int len = static_cast<int>(nums.size());
        std::vector<std::pair<int, int>> seen;
        seen.reserve(len);
        for (int i = 0; i < len; ++i) {
            seen.push_back({nums[i], i});
        }

        std::ranges::sort(seen);

        int low = 0;
        int high = len - 1;
        while (low < high) {
            auto sum = seen[low].first + seen[high].first;
            if (sum == target)
                return {min(seen[low].second, seen[high].second),
                        max(seen[low].second, seen[high].second)};
            else if (sum < target)
                ++low;
            else
                --high;
        }

        return {-1, -1};  // Should not be reached
    }
};
