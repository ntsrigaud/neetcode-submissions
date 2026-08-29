class Solution {
   public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }

        std::unordered_set<int> s(nums.begin(), nums.end());
        int max_count = 0;

        auto getLongestSequence = [&](int n) -> int {
            int c = 0;
            while (s.contains(n)) {
                ++c;
                ++n;
            }
            return c;
        };

        // Find the beginning of each sequences and count their length
        for (int n : s) {
            // Check for start of sequences only
            if (!s.contains(n - 1)) {
                max_count = std::max(getLongestSequence(n), max_count);
            }
        }

        return max_count;
    }
};
