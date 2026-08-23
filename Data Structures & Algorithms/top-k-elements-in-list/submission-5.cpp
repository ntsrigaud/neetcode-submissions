class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        std::unordered_map<int, int> freq_record;
        std::vector<std::vector<int>> buckets(nums.size() + 1);
        std::vector<int> top_k_frequent;

        top_k_frequent.reserve(k);

        // Count all frequencies first
        for (int num: nums) {
            ++freq_record[num];
        }

        // Collect frequencies in increasing order
        for (auto const& [num, freq] : freq_record) {
            buckets[freq].push_back(num);
        }

        // Collect top-K from back to front
        for (i = buckets.size() - 1; i >= 0 && top_k_frequent.size() < k; --i) {
            for (int num: buckets[i]) {
                top_k_frequent.push_back(num);
                if (top_k_frequent.size() == k) {
                    break;
                }
            }
        }

        return top_k_frequent;
    }
};