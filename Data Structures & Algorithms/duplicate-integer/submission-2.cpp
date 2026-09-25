class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> record;
        for (int n : nums) {
            ++record[n];
            if (record[n] == 2) return true;
        }

        return false;
    }
};