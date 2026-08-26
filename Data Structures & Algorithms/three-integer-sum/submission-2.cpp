class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        std::vector<std::vector<int>> triplets;

        std::ranges::sort(nums);
        auto twoSum = [&](int first_num, int left, int right) -> std::pair<int, int> {
            return {-1, -1};  // Not found
        };

        for (size_t i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;  // Skip duplicates
            }

            // Two-Sum
            left = i + 1;
            right = nums.size() - 1;
            sum = 0;
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    triplets.push_back({nums[i], nums[left], nums[right]});
                    // Update our pointers to continue for all the possible combinations
                    ++left;
                    while (left < right && nums[left] == nums[left - 1]) {
                        ++left;
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
