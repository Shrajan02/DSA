class Twitter {
private:
    int time; // global timestamp
    unordered_map<int, unordered_set<int>> friends; // {follower -> {list<followees>}}
    unordered_map<int, vector<pair<int, int>>> tweets; // {userId, {time, tweetId}}

public:
    Twitter() {
        time = 1;
        friends.clear();
        tweets.clear();
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> user_timeline; // max-heap
        for (auto tweet : tweets[userId]) {
            user_timeline.push(tweet);
        }

        for (auto followee : friends[userId]) {
            for (auto tweet : tweets[followee]) {
                user_timeline.push(tweet);
            }
        }

        vector<int> latest_feed;
        int count = 10;
        while (!user_timeline.empty() && count--) {
            latest_feed.push_back(user_timeline.top().second);
            user_timeline.pop();
        }
        return latest_feed;
    }

    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */