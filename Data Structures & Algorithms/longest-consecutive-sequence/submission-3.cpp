class Solution {
   public:
    int longestConsecutive(std::vector<int>& nums) {
        int max_count = 0;
        int count = 0;
        int curr_num = 0;
        std::unordered_set<int> s;
        s.reserve(nums.size());
        s.insert(nums.begin(), nums.end());

        // Find the beginning of each sequences and count their length
        for (int n : s) {
            // Check for start of sequences only
            if (!s.contains(n - 1)) {
                count = 1;
                curr_num = n;

                while (s.contains(curr_num + 1)) {
                    ++count;
                    ++curr_num;
                }

                max_count = std::max(count, max_count);
            }
        }

        return max_count;
    }
};
