class Solution {
    static constexpr char DELIM = '#';

   public:
    string encode(vector<string>& strs) {
        std::string encoded_str;

        // Encoding format <length>DELIM<string>
        for (const auto& str : strs) {
            encoded_str += std::to_string(str.size()) + DELIM + str;
        }

        return encoded_str;
    }

    vector<string> decode(string s) {
        // Decode string based on encoding format
        std::vector<std::string> decoded_str;
        size_t i = 0;

        while (i < s.size()) {
            // Locate DELIM after length
            size_t delim_pos = s.find(DELIM, i);

            // Extract length and jump past DELIM
            int len = std::stoi(s.substr(i, delim_pos - i));
            i = delim_pos + 1;

            // Extract substr payload
            decoded_str.push_back(s.substr(i, len));

            // Move past payload for next substr
            i += len;
        }

        return decoded_str;
    }
};
