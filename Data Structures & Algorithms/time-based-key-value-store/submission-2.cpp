class TimeMap {
    std::unordered_map<std::string, std::unordered_map<int, std::string>> time_map;

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) { time_map[key][timestamp] = value; }

    string get(string key, int timestamp) {
        // Assuming that time_map will always contain key
        while (timestamp >= 0) {
            if (!time_map[key][timestamp].empty()) {
                return time_map[key][timestamp];
            }

            --timestamp;
        }

        return "";
    }
};
