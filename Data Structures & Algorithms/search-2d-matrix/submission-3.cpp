class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix.front().size();

        // Binary search in 2D matrix as 1D array
        int low = 0;
        int high = m * n;
        int mid = 0;
        int val = 0;
        while (low < high) {
            mid = low + (high - low) / 2;
            val = matrix[mid / n][mid % n];

            if (val == target) {
                return true;
            } else if (val < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return false;
    }
};
