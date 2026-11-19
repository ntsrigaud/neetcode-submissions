class Solution {
    static constexpr int N_ALPHA = 26;

   public:
    int leastInterval(vector<char>& tasks, int n) {
        // Record the frequency of each task
        std::array<int, N_ALPHA> freq{};
        for (char ch : tasks) ++freq[ch - 'A'];

        // Use max-heap -> highest-freq task runs next
        std::priority_queue<int> max_heap;
        for (int count : freq)
            if (count > 0) max_heap.push(count);

        // Stores {remaining_count, cycle_when_ready}
        std::queue<std::pair<int, int>> cooldown;
        int cycle = 0;

        while (!max_heap.empty() || !cooldown.empty()) {
            ++cycle;

            // Release task whose cooldown has expired
            if (!cooldown.empty() && cooldown.front().second == cycle) {
                max_heap.push(cooldown.front().first);
                cooldown.pop();
            }

            if (!max_heap.empty()) {
                // Process a task
                const int remaining = max_heap.top() - 1;
                max_heap.pop();

                // Send duplicate to cooldown and wait for next cycle
                if (remaining > 0) cooldown.emplace(remaining, cycle + n + 1);
            } else if (!cooldown.empty()) {
                // Fast-forward idle cycles directly to the next ready task
                cycle = cooldown.front().second - 1;
            }
        }

        return cycle;
    }
};
