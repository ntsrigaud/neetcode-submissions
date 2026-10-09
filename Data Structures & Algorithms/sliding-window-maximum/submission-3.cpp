class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> out;

        // Monotonic deque to track sliding window
        std::deque<int> q;
        int left = 0;
        int right = 0;
        int n = static_cast<int>(nums.size());

        while (right < n) {
            // Ensure no smaller value exists in queue before adding
            while (!q.empty() && nums[q.back()] < nums[right]) q.pop_back();

            // Track number indexes to reduce array lookup overhead
            q.push_back(right);

            // Remove leftmost value if OOB
            if (left > q.front()) q.pop_front();

            // EDGE CASE -> Ensure win is at least size k for updates
            if (right + 1 >= k) {
                out.push_back(nums[q.front()]);
                ++left;
            }

            ++right;
        }

        return out;
    }
};
