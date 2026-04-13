class Twitter {
public:
    unordered_map<int,unordered_set<int>> followMap;

    vector<pair<int,int>> tweets; 
    Twitter() {  
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }    
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;

        followMap[userId].insert(userId);

        for(int i=tweets.size()-1; i>=0 && ans.size()< 10 ; i--){
            int tweetUser = tweets[i].first;
            int tweetId = tweets[i].second;

            if(followMap[userId].count(tweetUser)){
                ans.push_back(tweetId);
            }

        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
