class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.empty()) return 0;

        int low = 1;
        int high = std::ranges::max(piles);  // Get max eating speed

        auto getEatingTime = [&](int eating_speed) -> long long {
            long long total_time = 0;

            for (int p : piles) {
                // Math ceiling division identity
                // total_time += (p / eating_speed) + (p % eating_speed != 0);
                total_time += (p + eating_speed - 1) / eating_speed;
            }

            return total_time;
        };

        while (low < high) {
            const auto mid = low + (high - low) / 2;

            // Half-open interval -> [low, high)
            if (getEatingTime(mid) <= h) {
                // Speed is too fast
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;  // Points to the min valid speed at the end of search
    }
};
