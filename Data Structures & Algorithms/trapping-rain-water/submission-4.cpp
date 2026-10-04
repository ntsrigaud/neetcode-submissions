class Solution {
   public:
    int trap(vector<int>& height) {
        const int n = static_cast<int>(height.size());
        if (n < 2) return 0;

        int left = 0;
        int right = n - 1;

        // Get the min of LR of each height value
        int max_left = height[left];
        int max_right = height[right];

        // Compute trapped water
        int trapped_water = 0;
        while (left < right) {
            // Find which ptr to shift and update max LR
            if (max_left < max_right) {
                ++left;
                max_left = std::max(max_left, height[left]);
                trapped_water += max_left - height[left];
            } else {
                --right;
                max_right = std::max(max_right, height[right]);
                trapped_water += max_right - height[right];
            }
        }

        return trapped_water;
    }
};
