class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto binSearch = [&](int row) -> bool {
            int left = 0;
            int right = static_cast<int>(matrix[row].size());
            int val = 0;
            int mid = 0;

            while (left < right) {
                mid = left + (right - left) / 2;
                val = matrix[row][mid];

                if (val == target) {
                    return true;
                } else if (val < target) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            return false;
        };

        for (size_t r = 0; r < matrix.size(); ++r) {
            if (binSearch(r)) {
                return true;
            }
        }

        return false;
    }
};
