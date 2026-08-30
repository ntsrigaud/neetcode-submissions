class Solution {
   public:
    int maxArea(vector<int>& heights) {
        size_t left = 0;
        size_t right = heights.size() - 1;
        int max_area = 0;

        auto getArea = [&](size_t left, size_t right) -> int {
            return std::min(heights[left], heights[right]) * (right - left);
        };

        while (left < right) {
            max_area = std::max(max_area, getArea(left, right));

            if (heights[left] < heights[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return max_area;
    }
};
