class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> count;

        for (int n : nums) {
            ++count[n];
            if (count[n] >= 2) {
                return n;
            }
        }

        return -1;
    }
};
