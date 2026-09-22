class Solution {
   public:
    std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
        const int n = static_cast<int>(nums.size());
        if (nums.empty() || n < k) return {};

        std::vector<int> res;
        res.reserve(n - k + 1);

        // Monotonic decreasing deque storing indices
        std::deque<int> dq;

        for (int right = 0; right < n; ++right) {
            // 1. Maintain monotonic property: remove smaller elements from back
            while (!dq.empty() && nums[dq.back()] < nums[right]) {
                dq.pop_back();
            }
            dq.push_back(right);

            // 2. Remove indices that fall outside the left window boundary
            if (dq.front() < right - k + 1) {
                dq.pop_front();
            }

            // 3. Record window max once window reaches size k
            if (right >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
    }
};