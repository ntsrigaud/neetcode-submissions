class MedianFinder {
    std::priority_queue<int> lower_;  // Max heap -> smaller half
    std::priority_queue<int, std::vector<int>, std::greater<int>>
        upper_;  // Min-heap -> larger half

   public:
    MedianFinder() = default;

    void addNum(int num) {
        // Insert into lower first befor upper to keep the order
        lower_.push(num);
        upper_.push(lower_.top());
        lower_.pop();

        // Balance the two halves
        if (upper_.size() > lower_.size()) {
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
