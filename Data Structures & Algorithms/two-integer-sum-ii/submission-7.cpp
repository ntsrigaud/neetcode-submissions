class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = static_cast<int>(numbers.size()) - 1;
        int sum = 0;

        while (i < j) {
            sum = numbers[i] + numbers[j];
            if (sum == target) {
                return {i + 1, j + 1};
            } else if (sum > target) {
                // Move right pointer to reduce the sum
                --j;
            } else {
                // Move left pointer to increase the sum
                ++i;
            }
        }

        return {-1, -1};
    }
};
