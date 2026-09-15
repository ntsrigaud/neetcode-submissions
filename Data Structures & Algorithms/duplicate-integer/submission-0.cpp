class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> n_set;

        for (const int n : nums) {
            if (n_set.contains(n)) return true;
            n_set.insert(n);
        }

        return false;
    }
};