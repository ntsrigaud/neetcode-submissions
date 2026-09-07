class TimeMap {
    std::unordered_map<int, std::unordered_map<std::string, std::string>> time_map;

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) { time_map[timestamp][key] = value; }

    string get(string key, int timestamp) {
        while (timestamp >= 0) {
            if (time_map.contains(timestamp) && time_map[timestamp].contains(key)) {
                return time_map[timestamp][key];
            }
            --timestamp;
        }

        return "";
    }
};
