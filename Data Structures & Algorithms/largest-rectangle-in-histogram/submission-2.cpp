class Solution {
    struct Column {
        int index;
        int height;
    };

public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        const int n = static_cast<int>(heights.size());
        std::stack<Column> stack;

        for (int i = 0; i < n; ++i) {
            int start = i;

            // Ensure monotonic increasing stack property
            while (!stack.empty() && stack.top().height > heights[i]) {
                const auto [idx, height] = stack.top();
                stack.pop();

                max_area = std::max(max_area, height * (i - idx));

                // Extend start index backward
                start = idx;
            }

            // Emplace new increasing entry directly into the stack
            stack.emplace(start, heights[i]);
        }

        // Handles entries that extend to the histogram's end
        while (!stack.empty()) {
            const auto [idx, height] = stack.top();
            stack.pop();
            max_area = std::max(max_area, height * (n - idx));
        }

        return max_area;
    }
};
