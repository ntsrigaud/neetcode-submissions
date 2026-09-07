class TimeMap {
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> time_map;

   public:
    TimeMap() {}

    void set(const std::string& key, const std::string& value, int timestamp) {
        time_map[key].emplace_back(timestamp, value);
    }

    string get(const std::string& key, int timestamp) {
        auto it = time_map.find(key);
        if (it == time_map.end()) return "";

        const auto& time_values = it->second;
        int low = 0;
        int high = static_cast<int>(time_values.size()) - 1;
        std::string res;

        while (low <= high) {
            const int mid = (high + low) / 2;

            // Get the closest and less to the requested timestamp
            if (time_values[mid].first <= timestamp) {
                res = time_values[mid].second;  // Save the closest value
                low = mid + 1;
            } else {
                high = mid - 1;  // No need to save since higher is invalid
            }
        }

        return res;
    }
};
