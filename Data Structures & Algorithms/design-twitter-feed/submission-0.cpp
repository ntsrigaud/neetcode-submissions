class Twitter {
    struct TweetNode {
        int time;
        int tweet_id;
        int user_id;
        int next_idx;

        bool operator<(const TweetNode& other) const {
            return time < other.time;  // Max-heap -> largest timestamp on top
        }
    };

    int timestamp_ = 0;
    std::unordered_map<int, std::vector<std::pair<int, int>>> tweets_;
    std::unordered_map<int, std::unordered_set<int>> following_;

   public:
    Twitter() = default;  // Compiler-generated constructor

    void postTweet(int user_id, int tweet_id) {
        tweets_[user_id].emplace_back(timestamp_++, tweet_id);
    }

    vector<int> getNewsFeed(int user_id) {
        std::priority_queue<TweetNode> max_heap;

        auto push_latest = [&](int uid) {
            if (const auto it = tweets_.find(uid); it != tweets_.end() && !it->second.empty()) {
                const int last_idx = static_cast<int>(it->second.size()) - 1;
                const auto [time, tweet_id] = it->second[last_idx];
                max_heap.push({time, tweet_id, uid, last_idx - 1});
            }
        };

        // Seed heap with user's own most recent tweet
        push_latest(user_id);

        // Seed heap most recent tweets for user's followees
        if (const auto it = following_.find(user_id); it != following_.end()) {
            for (int followee_id : it->second) {
                if (followee_id != user_id) push_latest(followee_id);
            }
        }

        // Extract at most 10 most recent tweets
        std::vector<int> result;
        result.reserve(10);

        while (!max_heap.empty() && result.size() < 10) {
            const auto [time, tweet_id, uid, nxt_idx] = max_heap.top();
            max_heap.pop();
            result.push_back(tweet_id);

            // Push current user's next most recent tweet
            if (nxt_idx >= 0) {
                const auto [prev_time, prev_tweet_id] = tweets_[uid][nxt_idx];
                max_heap.push({prev_time, prev_tweet_id, uid, nxt_idx - 1});
            }
        }

        return result;
    }

    void follow(int follower_id, int followee_id) {
        // Prevent users from following themselves
        if (follower_id != followee_id) following_[follower_id].insert(followee_id);
    }

    void unfollow(int follower_id, int followee_id) {
        if (const auto it = following_.find(follower_id); it != following_.end()) {
            it->second.erase(followee_id);
        }
    }
};
