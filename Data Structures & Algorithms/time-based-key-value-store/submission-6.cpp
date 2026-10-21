class TimeMap {
    struct Record {
        int timestamp;
        std::string value;
    };

    std::unordered_map<std::string, std::vector<Record>> t_map;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        t_map[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto it = t_map.find(key);
        if (it == t_map.end())
            return "";

        const auto& t_values = it->second;

        // BinSearch to find first timestamp strictly GREATER than request
        int low = 0;
        int high = static_cast<int>(t_values.size()) - 1;
        std::string res;

        while (low <= high) {
            const int mid = low + (high - low) / 2;

            if (t_values[mid].timestamp <= timestamp) {
                res = t_values[mid].value; // Closest found so far
                low = mid + 1;
            } else
                high = mid - 1;
        }

        return res;
    }
};
