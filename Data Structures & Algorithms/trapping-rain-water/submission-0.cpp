class Solution {
   public:
    int trap(vector<int>& height) {
        // Compute the amnt of water that can be trapped at each height[i]
        // 1. Store the max height on both sides of height[i]
        int max_val = 0;
        const int n = static_cast<int>(height.size());

        std::vector<int> max_left(n);
        std::vector<int> max_right(n);
        int trapped_water = 0;

        for (int i = 0; i < n; ++i) {
            max_left[i] = max_val;
            max_val = std::max(max_val, height[i]);
        }

        max_val = 0;
        for (int i = n - 1; i >= 0; --i) {
            max_right[i] = max_val;
            max_val = std::max(max_val, height[i]);
        }

        // 2. Compute the water amnt at each height[i]
        for (size_t i = 0; i < n; ++i) {
            trapped_water += std::max(std::min(max_left[i], max_right[i]) - height[i], 0);
        }

        return trapped_water;
    }
};
