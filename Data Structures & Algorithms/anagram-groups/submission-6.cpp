class Solution {
public:
  std::vector<std::vector<std::string>>
  groupAnagrams(std::vector<std::string> &strs) {
    std::unordered_map<std::string, std::vector<std::string>> processed_groups;

    // Iterate on the list to create the distinct key-groups
    for (const auto &s : strs) {
      auto s_key = s;
      std::ranges::sort(s_key);
      processed_groups[s_key].push_back(s);
    }

    // Collect the sublists
    std::vector<std::vector<std::string>> anagram_sublists;
    anagram_sublists.reserve(processed_groups.size());

    for (const auto &g : processed_groups) {
      anagram_sublists.emplace_back(g.second);
    }

    return anagram_sublists;
  }
};