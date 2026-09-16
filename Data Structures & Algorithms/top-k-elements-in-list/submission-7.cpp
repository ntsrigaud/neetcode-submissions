class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        for (const int n : nums) ++count[n];

        // Track the order using frequency min heap
        auto cmp = [](const std::pair<int, int>& a,
                      const std::pair<int, int>& b) -> bool {
            return a.second > b.second;
        };

        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>, 
                            decltype(cmp)>
            min_heap(cmp);
        for (const auto& p : count) {
            // Add new and remove the one with the lowest count
            min_heap.push(p);
            if (min_heap.size() > k)
                min_heap.pop();
        }

        // Collect the top k values in vector
        std::vector<int> top_k_frequent;
        top_k_frequent.reserve(k);
        while (!min_heap.empty()) {
            top_k_frequent.push_back(min_heap.top().first);
            min_heap.pop();
        }

        return top_k_frequent;
    }
};