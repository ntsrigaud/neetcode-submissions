class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int i = 0;
        int j = 0;
        int nums_len = static_cast<int>(nums.size());
        std::unordered_map<int, int> freq_record;
        std::vector<int> top_k_frequent;
        top_k_frequent.reserve(k);

        // Count all frequencies first
        for (j = 1; j < nums_len; ++j) {
            if (nums[j] != nums[i]) {
                freq_record[nums[i]] = j - i;
                i = j;  // Jump to next item range
            }
        }

        // Add last group
        freq_record[nums[i]] = j - i;

        // Record top K elements in min-priority queue
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, greater<>>
            p_queue;

        for (auto& [elt, freq] : freq_record) {
            p_queue.push({freq, elt});

            if (p_queue.size() > k) {
                p_queue.pop();
            }
        }

        // Collect the top Ks into a vector
        while (!p_queue.empty()) {
            top_k_frequent.emplace_back(p_queue.top().second);
            p_queue.pop();
        }

        return top_k_frequent;
    }
};