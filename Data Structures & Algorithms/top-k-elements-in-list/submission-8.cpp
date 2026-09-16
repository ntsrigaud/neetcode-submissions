class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int n = static_cast<int>(nums.size());
        std::unordered_map<int, int> count;
        for (const int n : nums) ++count[n];

        // Index the elements in buckets by frequency
        // Max bucket needed is same as array, but no frequency 0
        // will be recorded -> Shift by one value
        std::vector<std::vector<int>> buckets(n + 1);
        for (const auto& [val, freq] : count) {
            buckets[freq].push_back(val);
        }

        // Collect the topmost values from highest frequency from right
        std::vector<int> top_k_frequent;
        top_k_frequent.reserve(k);
        for (int i = n; i >= 0 && top_k_frequent.size() < k; --i) {
            if (buckets[i].empty()) continue;
            for (const int val : buckets[i]) {
                if (top_k_frequent.size() == k) break;
                top_k_frequent.push_back(val);
            }
        }

        return top_k_frequent;
    }
};