class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min_eating_speed = 0;

        // Get maximum pile for HIGH ptrs
        int low = 1;  // Eats at least 1 banana per hour
        int high = 1;
        for (const int p : piles) high = std::max(high, p);

        auto canEatPile = [&](int eating_rate) -> bool {
            // Attempt to eat all piles using eating_rate
            int tmp_h = h;
            for (const int p : piles) {
                if (tmp_h <= 0) return false;
                tmp_h -= (p / eating_rate) + !!(p % eating_rate);
            }

            return tmp_h >= 0;
        };

        // Binary search across eating rate range
        while (low <= high) {
            const int mid = low + (high - low) / 2;

            if (canEatPile(mid)) {
                min_eating_speed = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }

        return min_eating_speed;
    }
};
