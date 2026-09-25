class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> record;
        for (int n : nums) {
            if (record.count(n)) return true;
            record.insert(n);
        }

        return false;
    }
};