class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix.front().size());

        int low = 0;
        int high = m * n - 1;

        while (low <= high) {
            const int mid = low + (high - low) / 2;
            const int val = matrix[mid / n][mid % n];

            if (val == target)
                return true;
            else if (val < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }
};
