class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            return nums.front() == target ? 0 : -1;
        }

        int median = nums.size() / 2;
        int left = 0;
        int right = nums.size();
        int m_val = 0;

        while (left < right) {
            median = left + (right - left) / 2;
            m_val = nums[median];

            if (target == m_val) {
                return median;
            } else if (target < m_val) {
                right = median - 1;
            } else {
                left = median + 1;
            }
        }

        return (left == right && nums[left] == target) ? left : -1;
    }
};
