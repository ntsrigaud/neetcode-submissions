class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        int n = static_cast<int>(heights.size());
        std::stack<std::pair<int, int>> idx_height;

        auto getNewArea = [&](const int start) -> int {
            const auto [idx, height] = idx_height.top();
            const int new_area = height * (start - idx);
            idx_height.pop();

            return new_area;
        };

        for (int i = 0; i < n; ++i) {
            int start = i;

            // Ensure monotonic increasing stack property
            while (!idx_height.empty() && idx_height.top().second > heights[i]) {
                const int idx = idx_height.top().first;
                const int new_area = getNewArea(i);
                if (new_area > max_area) max_area = new_area;

                // Extend start index backward
                start = idx;
            }

            // Add new increasing entry
            idx_height.push({start, heights[i]});
        }

        // Handles entries that extend to the histogram's end
        while (!idx_height.empty()) {
            const int new_area = getNewArea(n);
            if (new_area > max_area) max_area = new_area;
        }

        return max_area;
    }
};
