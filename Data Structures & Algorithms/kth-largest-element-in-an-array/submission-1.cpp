class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

        for (int n : nums) {
            if (min_heap.size() == static_cast<size_t>(k) && min_heap.top() < n) {
                min_heap.pop();
                min_heap.push(n);
            } else if (min_heap.size() < static_cast<size_t>(k))
                min_heap.push(n);
        }

        return min_heap.top();
    }
};
