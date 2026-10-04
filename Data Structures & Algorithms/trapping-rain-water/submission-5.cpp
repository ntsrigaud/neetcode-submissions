class Solution {
public:
    int trap(vector<int>& height) {
        const int n = static_cast<int>(height.size());
        if (n < 2)
            return 0;

        int left = 0;
        int right = n - 1;

        // Get the min of LR of each height value
        int max_left = height[left];
        int max_right = height[right];

        // Compute trapped water
        int trapped_water = 0;
        while (left < right) {
            // Find which ptr to shift and update max LR
            if (height[left] < height[right]) {
                if (height[left] >= max_left)
                    max_left = height[left];
                else
                    trapped_water += max_left - height[left];
                ++left;
            } else {
                if (height[right] >= max_right)
                    max_right = height[right];
                else
                    trapped_water += max_right - height[right];
                --right;
            }
        }

        return trapped_water;
    }
};
