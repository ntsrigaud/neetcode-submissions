class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Algo -> Iterative BinSearch on smaller array

        // Determine smaller array
        if (nums1.size() > nums2.size()) std::swap(nums1, nums2);

        int n = static_cast<int>(nums1.size());
        int m = static_cast<int>(nums2.size());

        // BinSearch on smaller array
        int low = 0;
        int high = n;  // Half-closed interval BinSearch
        while (low <= high) {
            int s_mid = (low + high) / 2;
            int l_mid = ((n + m + 1) / 2) - s_mid;

            // Determine LR portions extr. values of both arrays
            int s_left = (s_mid != 0) ? nums1[s_mid - 1] : INT_MIN;
            int s_right = (s_mid != n) ? nums1[s_mid] : INT_MAX;

            int l_left = (l_mid != 0) ? nums2[l_mid - 1] : INT_MIN;
            int l_right = (l_mid != m) ? nums2[l_mid] : INT_MAX;

            // Determine median if portions are in correct order
            if (s_left <= l_right && l_left <= s_right) {
                if ((n + m) % 2 == 0)
                    return (std::max(s_left, l_left) + std::min(s_right, l_right)) / 2.0;
                return std::max(s_left, l_left);
            } else if (s_left > l_right) {
                // Left portion is too big -> Shrink to the left
                high = s_mid - 1;
            } else {
                // Left portion is too small -> Grow to the right
                low = s_mid + 1;
            }
        }

        return -1;  // Should not be reached
    }
};
