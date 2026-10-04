class Solution {
public:
    int trap(vector<int>& height) {
        const int n = static_cast<int>(height.size());
        if (n < 2)
            return 0;

        // Get the min of LR of each height value
        std::vector<int> left_max(n, 0);
        std::vector<int> right_max(n, 0);

        // Retrieve max left values first in res array
        left_max[0] = height[0];
        for (int i = 1; i < n; ++i) {
            left_max[i] = std::max(left_max[i - 1], height[i]);
        }

        // Retrieve max vals from both LR
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right_max[i] = std::max(right_max[i + 1], height[i]);
        }

        // Compute the sum of trapped water
        int trapped_water = 0;
        for (int i = 0; i < n; ++i) {
            trapped_water += std::min(left_max[i], right_max[i]) - height[i];
        }

        return trapped_water;
    }
};
