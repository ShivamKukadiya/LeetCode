class Twitter {
public:
    unordered_map<int, vector<int>> follows;
    vector<pair<int, int>> order;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        order.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;

        for (int i = order.size() - 1; i >= 0; i--) {

            if (order[i].first == userId ||
                find(follows[userId].begin(), follows[userId].end(),
                     order[i].first) != follows[userId].end()) {

                ans.push_back(order[i].second);
            }

            if (ans.size() == 10)
                return ans;
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {

        follows[followerId].push_back(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        auto it = find(follows[followerId].begin(), follows[followerId].end(),
                       followeeId);

        if (it != follows[followerId].end())
            follows[followerId].erase(it);
    }
};

