class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = static_cast<int>(heights.size());
        int max_area = 0;

        // Track the height and their indices to find the expansion area
        std::stack<std::pair<int, int>> idx_h;

        for (int i = 0; i < n; ++i) {
            // Track the starting index for the current height
            int start = i;

            // Ensure continuous expansion
            while (!idx_h.empty() && idx_h.top().second > heights[i]) {
                // Cannot expand further with top height
                auto h_top = idx_h.top();
                idx_h.pop();

                // Compute area produced by cur highest value
                auto cur_area = h_top.second * (i - h_top.first);
                if (cur_area > max_area) max_area = cur_area;

                // Expand backward since stack is in increasing order
                start = h_top.first;
            }

            // New height expands all the way back to an equal or lower height
            idx_h.push({start, heights[i]});
        }

        // Compute the area for the ones that expand all the way to the end if any
        while (!idx_h.empty()) {
            auto h_top = idx_h.top();
            idx_h.pop();

            auto cur_area = h_top.second * (n - h_top.first);
            if (cur_area > max_area) max_area = cur_area;
        }

        return max_area;
    }
};
