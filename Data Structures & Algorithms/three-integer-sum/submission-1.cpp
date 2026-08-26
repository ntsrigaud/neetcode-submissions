class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::set<std::vector<int>> triplets;

        std::ranges::sort(nums);
        auto twoSum = [&](int first_num, int left, int right) -> std::pair<int, int> {
            int sum = 0;
            while (left < right) {
                sum = first_num + nums[left] + nums[right];
                if (sum == 0) {
                    return {left, right};
                } else if (sum < 0) {
                    ++left;  // Increase sum
                } else {
                    --right;  // Decrease sum
                }
            }

            return {-1, -1};  // Not found
        };

        for (size_t i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;  // Skip duplicates
            }

            for (size_t j = i + 1; j < nums.size() - 1; ++j) {
                auto p = twoSum(nums[i], j, nums.size() - 1);
                if (p.first > 0) {
                    triplets.insert({nums[i], nums[p.first], nums[p.second]});
                } else {
                    break;
                }
            }
        }

        return std::vector<std::vector<int>>(triplets.begin(), triplets.end());
    }
};
