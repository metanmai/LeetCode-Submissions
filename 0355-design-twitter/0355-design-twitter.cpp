class Twitter {
private:
    int time;
    map<int, vector<pair<int, int>>> tweets;
    map<int, set<int>> following;
    
public:
    Twitter() : time(0) {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        priority_queue<vector<int>> pq;
        
        following[userId].insert(userId);
        
        for(auto user : following[userId])
        {
            if(tweets[user].size() == 0)
                continue;
            
            auto [timePosted, lastTweetId] = tweets[user].back();
            pq.push({timePosted, lastTweetId, user, (int) tweets[user].size() - 1});
        }
        
        while(!pq.empty() and feed.size() < 10)
        {
            auto tweet = pq.top(); pq.pop();
            int lastTweetId = tweet[1], user = tweet[2], tweetIndex = tweet[3];
            
            feed.push_back(lastTweetId);
            
            if(tweetIndex == 0)
                continue;
            
            auto [timePosted, nextTweetId] = tweets[user][tweetIndex - 1];
            pq.push({timePosted, nextTweetId, user, tweetIndex - 1});
        }
        
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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