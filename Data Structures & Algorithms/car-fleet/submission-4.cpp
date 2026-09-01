class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int fleets = 0;
        double max_time = 0.0;
        std::vector<std::pair<int, double>> pt_cars;

        // Link and sort the cars by position
        for (size_t i = 0; i < position.size(); ++i) {
            pt_cars.push_back(
                {position[i],
                 (static_cast<double>(target - position[i]) / speed[i])});
        }
        std::ranges::sort(pt_cars,
                          std::greater<>()); // Decreasing order

        // Process the pairs from right to left
        for (const auto& [pos, time]: pt_cars) {
            if (fleets == 0 || max_time < time) {
                ++fleets;
                max_time = time;
            }
        }

        return fleets;
    }
};
