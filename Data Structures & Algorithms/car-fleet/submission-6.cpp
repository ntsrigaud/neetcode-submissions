class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Save the cars tuples in reverse sorted order
        std::vector<std::pair<int, int>> cars;

        for (size_t i = 0; i < position.size(); ++i) {
            cars.push_back({position[i], speed[i]});
        }

        auto cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) -> bool {
            return a.first > b.first;
        };
        std::ranges::sort(cars, cmp);

        std::stack<double> fleets_arrival_time;
        for (const auto& [pos, speed] : cars) {
            const auto arrival_time = (target - pos) / static_cast<double>(speed);
            if (fleets_arrival_time.empty() || fleets_arrival_time.top() < arrival_time)
                fleets_arrival_time.push(arrival_time);
        }

        return fleets_arrival_time.size();
    }
};
