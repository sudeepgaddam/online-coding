from collections import defaultdict

class Twitter(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.followees = defaultdict(set)
        self.tweets = defaultdict(list)
        self.timestamp = 1

    def postTweet(self, userId, tweetId):
        """
        Compose a new tweet.
        :type userId: int
        :type tweetId: int
        :rtype: None
        """
        self.tweets[userId].append((tweetId,self.timestamp))
        self.timestamp+=1
    def getNewsFeed(self, userId):
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        :type userId: int
        :rtype: List[int]
        """
        lst = self.followees[userId]
        lst.add(userId)
        allTweets=[]
        for fellow in lst:
            for x in self.tweets[fellow]:
                allTweets.append(x)
        allTweets.sort(key=lambda x:x[1],reverse=True)
        # print(allTweets)
        return [x[0] for x in  allTweets[:10]]
        

    def follow(self, followerId, followeeId):
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: None
        """
        self.followees[followerId].add(followeeId)

    def unfollow(self, followerId, followeeId):
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: None
        """
        if followerId in self.followees and followeeId in self.followees[followerId]:
            self.followees[followerId].discard(followeeId)



# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
