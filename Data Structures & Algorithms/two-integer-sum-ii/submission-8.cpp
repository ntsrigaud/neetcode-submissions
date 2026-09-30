class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = static_cast<int>(numbers.size()) - 1;

        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target)
                return {low + 1, high + 1};
            else if (sum < target)
                ++low;
            else
                --high;
        }

        return {-1, -1};  // Should not be reached
    }
};
