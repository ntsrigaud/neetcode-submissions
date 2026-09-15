class Solution {
   public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        // Use sorted letters of each words as key
        std::unordered_map<std::string, std::vector<std::string>> str_map;
        for (auto& str : strs) {
            auto key = str;
            std::ranges::sort(key);

            str_map[key].push_back(str);
        }

        // Collect the collected sublists of anagrams
        std::vector<std::vector<std::string>> anagram_lists;
        for (auto& [key, sublist] : str_map) {
            anagram_lists.push_back(std::move(sublist));
        }

        return anagram_lists;
    }
};