class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        // Use set to track the start of sequences
        std::unordered_set<int> seen(nums.begin(), nums.end());
        int longest = 0;

        // Iterate over unique nbers -> remove overhead
        for (int n : seen) {
            // Check for sequence start
            if (!seen.contains(n - 1)) {
                int cur_n = n;
                int cur_len = 1;

                // Expand the sequence forward
                while (seen.contains(cur_n + 1)) {
                    ++cur_n;
                    ++cur_len;
                }

                longest = std::max(longest, cur_len);
            }
        }

        return longest;
    }
};
