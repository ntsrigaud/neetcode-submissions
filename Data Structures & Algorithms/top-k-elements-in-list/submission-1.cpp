class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());
    int i = 0;
    int j = 0;
    int nums_len = static_cast<int>(nums.size());
    std::unordered_map<int, int> freq_record;
    std::vector<int> top_k_frequent;
    top_k_frequent.reserve(k);

    auto updateTopK = [&](int n, int freq) -> void {
      int top_k_len = static_cast<int>(top_k_frequent.size());
      freq_record[n] = freq;

      if (top_k_len < k) {
        top_k_frequent.emplace_back(n);
      } else {
        // Check least frequent item
        int least_frequent_idx = -1;
        int smaller_freq = freq;
        for (int idx = 0; idx < top_k_len; ++idx) {
          if (freq_record[top_k_frequent[idx]] < smaller_freq) {
            least_frequent_idx = idx;
            smaller_freq = freq_record[top_k_frequent[idx]];
          }
        }

        // Replace only if found
        if (least_frequent_idx != -1) {
          top_k_frequent[least_frequent_idx] = n;
        }
      }
    };

    for (j = 1; j < nums_len; ++j) {
      if (nums[j] != nums[i]) {
        updateTopK(nums[i], j - i);
        i = j; // Jump to next item range
      }
    }

    // Last item range
    updateTopK(nums[i], j - i);

    return top_k_frequent;
  }
};