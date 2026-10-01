#include <vector>
#include <algorithm>

class Solution {
   public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::ranges::sort(nums);
        std::vector<std::vector<int>> res;

        const int n = static_cast<int>(nums.size());

        for (int i = 0; i < n - 2; ++i) {
            // Early exit: smallest value > 0 cannot sum to 0
            if (nums[i] > 0) break;

            // Skip duplicate values for 'i'
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int low = i + 1;
            int high = n - 1;

            while (low < high) {
                const int three_sum = nums[i] + nums[low] + nums[high];

                if (three_sum > 0) {
                    --high;
                } else if (three_sum < 0) {
                    ++low;
                } else {
                    res.push_back({nums[i], nums[low], nums[high]});

                    // 1. Advance both pointers
                    ++low;
                    --high;

                    // 2. Skip duplicates for 'low'
                    while (low < high && nums[low] == nums[low - 1]) {
                        ++low;
                    }
                }
            }
        }

        return res;
    }
};