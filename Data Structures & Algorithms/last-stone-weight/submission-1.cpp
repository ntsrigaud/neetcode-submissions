class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Use max-heap to track heavier stones
        std::priority_queue<int> pq(std::less<int>{}, std::move(stones));

        // Pick stones by two until none or a single one is left
        while (pq.size() > 1) {
            const int x = pq.top();
            pq.pop();

            const int y = pq.top();
            pq.pop();

            // Add remaining weight
            if (x != y)
                pq.push(x - y); // First element always greater
        }

        return pq.empty() ? 0 : pq.top();
    }
};
