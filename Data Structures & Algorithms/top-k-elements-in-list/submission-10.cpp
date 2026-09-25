class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        for (int n : nums)
            ++count[n];

        // Collect values in buckets based on counts
        std::vector<std::vector<int>> buckets(nums.size() + 1);

        int max_freq = 0;
        for (const auto& [val, c] : count) {
            buckets[c].push_back(val);
            max_freq = std::max(max_freq, c);
        }

        // Collect top k frequent elements from highest freq
        std::vector<int> top_k_elts;
        top_k_elts.reserve(k);
        for (int i = max_freq; i > 0 && static_cast<int>(top_k_elts.size()) < k;
             --i) {
            // Push all elts from the top bucket
            for (int n : buckets[i]) {
                if (static_cast<int>(top_k_elts.size()) == k)
                    break;
                top_k_elts.push_back(n);
            }
        }

        return top_k_elts;
    }
};
