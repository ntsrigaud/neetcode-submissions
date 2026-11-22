class MedianFinder {
    std::priority_queue<int> lower_;  // Max heap -> smaller half
    std::priority_queue<int, std::vector<int>, std::greater<int>>
        upper_;  // Min-heap -> larger half

   public:
    MedianFinder() = default;

    void addNum(int num) {
        // Insert directly into the appropriate half
        if (lower_.empty() || num <= lower_.top())
            lower_.push(num);
        else
            upper_.push(num);

        // Rebalance only if sizes violate invariant
        if (lower_.size() > upper_.size() + 1) {
            upper_.push(lower_.top());
            lower_.pop();
        } else if (upper_.size() > lower_.size()) {
            lower_.push(upper_.top());
            upper_.pop();
        }
    }

    double findMedian() {
        // Deterministic search in middle using heaps -> O(1)
        if (lower_.size() > upper_.size()) {
            return static_cast<double>(lower_.top());
        }

        return (static_cast<double>(lower_.top()) + upper_.top()) / 2.0;
    }
};
