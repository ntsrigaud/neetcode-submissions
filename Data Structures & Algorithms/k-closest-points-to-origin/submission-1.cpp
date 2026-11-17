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

        // In-place mutation for k closest selection -> O(n) time && O(1) space
        std::nth_element(points.begin(), points.begin() + k, points.end(), comp);
        points.resize(k);

        return points;
    }
};
