class Solution {
   public:
    int maxArea(vector<int>& heights) {
        size_t left = 0;
        size_t right = heights.size() - 1;
        int max_area = 0;
        int new_area = 0;
        int min_h = 0;

        auto getArea = [&](size_t left, size_t right) -> int {
            return std::min(heights[left], heights[right]) * (right - left);
        };

        while (left < right) {
            min_h = std::min(heights[left], heights[right]);
            new_area = min_h * (right - left);
            max_area = std::max(max_area, new_area);

            // Fast skipping for shorter lines to avoid redundant area computations
            while (left < right && heights[left] <= min_h) {
                ++left;
            }

            while (left < right && heights[right] <= min_h) {
                --right;
            }
        }

        return max_area;
    }
};
