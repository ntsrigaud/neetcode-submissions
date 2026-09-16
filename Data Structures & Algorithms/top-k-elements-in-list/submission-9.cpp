class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int n = static_cast<int>(nums.size());
        std::unordered_map<int, int> count;
        count.reserve(n); // Prevent map re-hashes
        for (const int val : nums)
            ++count[val];

        // Index the elements in buckets by frequency
        // Max bucket needed is same as array, but no frequency 0
        // will be recorded -> Shift by one value
        std::vector<std::vector<int>> buckets(n + 1);
        for (const auto& [val, freq] : count) {
            buckets[freq].push_back(val);
        }

        // Collect elements starting from maximum possible frequency down to 1
        std::vector<int> top_k;
        top_k.reserve(k);

        for (int freq = n; freq > 0; --freq) {
            if (buckets[freq].empty())
                continue;
            for (const int val : buckets[freq]) {
                if (top_k.size() == k)
                    return top_k;       // Early stopping
                top_k.push_back(val);
            }
        }

        return top_k;
    }
};