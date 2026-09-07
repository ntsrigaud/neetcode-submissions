class TimeMap {
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> time_map;

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        time_map[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        std::string res;

        if (time_map.contains(key)) {
            int low = 0;
            int high = static_cast<int>(time_map[key].size()) - 1;

            while (low <= high) {
                const int mid = (high + low) / 2;

                // Get the closest and less to the requested timestamp
                if (time_map[key][mid].first <= timestamp) {
                    res = time_map[key][mid].second;  // Save the closest value
                    low = mid + 1;
                } else {
                    high = mid - 1;  // No need to save since higher is invalid
                }
            }
        }

        return res;
    }
};
