class MinStack {
    std::stack<std::pair<int, int>> record;

   public:
    MinStack() {}

    void push(int val) {
        if (record.empty()) {
            record.push({val, val});
        } else {
            record.push({val, std::min(val, record.top().second)});
        }
    }

    void pop() { record.pop(); }

    int top() { return record.top().first; }

    int getMin() { return record.top().second; }
};
