class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.empty() || h < static_cast<int>(piles.size())) return 0;

        int low = 1;
        int high = std::ranges::max(piles);

        while (low < high) {
            const auto mid = low + (high - low) / 2;

            // Get the total eating time
            long long eating_hours = 0;
            for (int p : piles) {
                eating_hours += (p + mid - 1) / mid;  // Integer ceiling division
            }

            if (eating_hours <= h) {
                // Eating rate might be too fast -> Shift to the left
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
