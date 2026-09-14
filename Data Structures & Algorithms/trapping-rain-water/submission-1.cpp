class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        int max_left = height.front();
        int max_right = height.back();
        int trapped_water = 0;

        while (left < right) {
            if (max_left < max_right) {
                // Move the left ptr, update the max_left and cur_sum
                ++left;
                max_left = std::max(max_left, height[left]);
                trapped_water += max_left - height[left];
            } else {
                // Move the right ptr and update sum and max_right
                --right;
                max_right = std::max(max_right, height[right]);
                trapped_water += max_right - height[right];
            }
        }

        return trapped_water;
    }
};
