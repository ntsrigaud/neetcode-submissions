class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap(
            std::greater<int>{}, std::move(nums));

        while (min_heap.size() > static_cast<size_t>(k)) {
            min_heap.pop();
        }

        return min_heap.top();
    }
};
