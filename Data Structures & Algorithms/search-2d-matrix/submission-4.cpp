class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix.front().size());

        // Binary search in 2D matrix as 1D array
        int low = 0;
        int high = m * n;

        while (low < high) {
            const auto mid = low + (high - low) / 2;
            const auto val = matrix[mid / n][mid % n];

            // Guard clause pattern + Range reduction
            if (val == target) return true;
            if (val < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return false;
    }
};
