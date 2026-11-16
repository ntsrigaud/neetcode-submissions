class KthLargest {
    using MinHeap = std::priority_queue<int, std::vector<int>, std::greater<int>>;
    MinHeap min_heap_;
    int k_ = 0;

   public:
    KthLargest(int k, vector<int>& nums) : k_(k), min_heap_(std::greater<int>{}, std::move(nums)) {
        // Remove excess elements in heap
        while (min_heap_.size() > k_) {
            min_heap_.pop();
        }
    }

    int add(int val) {
        min_heap_.push(val);

        // Ensure heap has enough elt before popping
        while (min_heap_.size() > k_) {
            min_heap_.pop();
        }

        return min_heap_.top();
    }
};
