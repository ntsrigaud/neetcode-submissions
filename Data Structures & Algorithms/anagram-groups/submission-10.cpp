class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map all strings into buckets based with letters as key
        std::unordered_map<std::string, std::vector<std::string>> buckets;

        // Initialize buckets and store words
        for (const std::string& s : strs) {
            auto key = s;
            std::ranges::sort(key);

            buckets[key].push_back(s);
        }

        // Collect all collected groups
        std::vector<std::vector<std::string>> anagrams;
        anagrams.reserve(buckets.size());  // Prevents map re-hash

        for (auto& [key, sublist] : buckets) {
            anagrams.emplace_back(std::move(sublist));
        }

        return anagrams;
    }
};
