class Solution {
    using Point = std::vector<int>;
    static constexpr std::array<int, 2> ORIGIN{0, 0};

    // No need for Euclid distance since we are only looking for closest
    static long long distSq(const Point& p) {
        const long long dx = p[0] - ORIGIN[0];
        const long long dy = p[1] - ORIGIN[1];

        return dx * dx + dy * dy;
    }

   public:
    vector<Point> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](const Point& a, const Point& b) -> bool {
            return distSq(a) < distSq(b);  // Max heap -> Farthest at the top
        };
        std::priority_queue<Point, std::vector<Point>, decltype(comp)> max_heap(comp);

        // Add pts with fast-skip check for larger values to keep mins
        for (auto& pt : points) {
            if (max_heap.size() < static_cast<size_t>(k))
                max_heap.push(std::move(pt));
            else if (distSq(pt) < distSq(max_heap.top())) {
                max_heap.pop();
                max_heap.push(std::move(pt));
            }
        }

        std::vector<Point> k_closest;
        k_closest.reserve(max_heap.size());
        while (!max_heap.empty()) {
            // const_cast allows moving elements out of priority_queue::top()
            k_closest.push_back(std::move(const_cast<Point&>(max_heap.top())));
            max_heap.pop();
        }

        return k_closest;
    }
};
