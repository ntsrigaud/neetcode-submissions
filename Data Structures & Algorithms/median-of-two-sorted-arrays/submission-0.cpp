class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Naive approach
        std::vector<int> combined;
        combined.reserve(nums1.size() + nums2.size());

        size_t i = 0;
        size_t j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                combined.push_back(nums1[i++]);
            } else {
                combined.push_back(nums2[j++]);
            }
        }

        // Add the rest if any
        while (i < nums1.size()) {
            combined.push_back(nums1[i++]);
        }
        while (j < nums2.size()) {
            combined.push_back(nums2[j++]);
        }

        double median = 0;
        auto mid = (i + j) / 2;
        if ((i + j) % 2 == 0) {
            median = (combined[mid - 1] + combined[mid]) / 2.0;
        } else {
            median = combined[mid];
        }

        return median;
    }
};
