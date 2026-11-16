class KthLargest {
    using MinHeap =
        std::priority_queue<int, std::vector<int>, std::greater<int>>;
    MinHeap min_heap_;
    const size_t k_ = 0;

public:
    KthLargest(int k, vector<int>& nums) : k_(static_cast<size_t>(k)) {
        if (nums.size() > k_) {
            // O(n) partition: places the k largest elements  in [0, k)
            std::nth_element(nums.begin(),
                             nums.begin() + static_cast<std::ptrdiff_t>(k_),
                             nums.end(), std::greater<int>{});
            nums.resize(k_);
        }

        // O(k) heap construction on at most k elements
        min_heap_ = MinHeap(std::greater<int>{}, std::move(nums));
    }

    int add(int val) {
        if (min_heap_.size() < k_) {
            min_heap_.push(val);
        } else if (min_heap_.top() < val) {
            // Pop first so heap size never exceeds k_
            min_heap_.pop();
            min_heap_.push(val);
        }

        return min_heap_.top();
    }
};
