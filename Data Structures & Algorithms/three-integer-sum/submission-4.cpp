class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int n = static_cast<int>(nums.size());
        std::vector<std::vector<int>> triplets;

        std::ranges::sort(nums);
        for (int i = 0; i < n; ++i) {
            // Since the list is sorted, if nums[i] > 0, no chance of ever getting sum = 0
            if (nums[i] > 0) {
                break;
            }

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;  // Skip duplicates
            }

            // Two-Sum
            left = i + 1;
            right = n - 1;
            sum = 0;
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    triplets.push_back({nums[i], nums[left], nums[right]});
                    // Update our pointers to continue for all the possible combinations and skip
                    // duplicates
                    ++left;
                    --right;
                    while (left < right && nums[left] == nums[left - 1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        --right;
                    }
                } else if (sum < 0) {
                    ++left;  // Increase sum
                } else {
                    --right;  // Decrease sum
                }
            }
        }

        return triplets;
    }
};
