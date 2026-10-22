class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;
        int half = total / 2;

        // BinSearch -> # of elts A contributes
        int low = 0;
        int high = n;

        while (low <= high) {
            const int part_a = low + (high - low) / 2;
            const int part_b = half - part_a;

            // Find comparison values to ensure correct partitioning
            const double a_left = (part_a > 0) ? nums1[part_a - 1] : INT_MIN;
            const double a_right = (part_a < n) ? nums1[part_a] : INT_MAX;

            const double b_left = (part_b > 0) ? nums2[part_b - 1] : INT_MIN;
            const double b_right = (part_b < m) ? nums2[part_b] : INT_MAX;

            // Check correct partitioning
            if (a_left <= b_right && b_left <= a_right) {
                // Edge case -> odd array size
                if (total % 2) return std::min(a_right, b_right);

                return (std::max(a_left, b_left) + std::min(a_right, b_right)) / 2.0;
            } else if (a_left > b_right) {
                // Too many elts from A -> move partition left
                high = part_a - 1;
            } else {
                // Too few elts from A -> move partition right
                low = part_a + 1;
            }
        }

        return -1.0;  // Should not execute
    }
};
