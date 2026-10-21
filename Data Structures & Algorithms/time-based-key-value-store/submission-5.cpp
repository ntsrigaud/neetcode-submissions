class TimeMap {
    std::unordered_map<std::string, std::map<int, std::string>> t_map;

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) { t_map[key][timestamp] = value; }

    string get(string key, int timestamp) {
        auto it = t_map.find(key);
        if (it == t_map.end()) return "";

        const auto& sub_map = it->second;

        // First timestamp strictly GREATER than request
        auto sub_it = sub_map.upper_bound(timestamp);

        // All timestamps might be greater than request
        if (sub_it == sub_map.begin()) return "";

        // Step back by one to get the largest
        --sub_it;
        return sub_it->second;
    }
};
