class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int result = 0;
        int n = static_cast<int>(heights.size());

        int low = 0;
        int high = n - 1;

        while (low < high) {
            int area = (high - low) * std::min(heights[low], heights[high]);
            result = std::max(result, area);

            if (heights[low] < heights[high])
                ++low;
            else
                --high;
        }

        return result;
    }
};
