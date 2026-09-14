#include <vector>

class Solution {
   public:
    int trap(const std::vector<int>& height) {
        if (height.empty()) return 0;

        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        int max_left = 0;
        int max_right = 0;
        int trapped_water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                const int h = height[left];
                if (h >= max_left)
                    max_left = h;  // Update peak (no water addition)
                else
                    trapped_water += max_left - h;  // Add water (no max update needed)
                ++left;
            } else {
                const int h = height[right];
                if (h >= max_right)
                    max_right = h;  // Update peak (no water addition needed)
                else
                    trapped_water += max_right - h;  // Add water (no max update needed)
                --right;
            }
        }

        return trapped_water;
    }
};