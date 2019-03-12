class Codec:

    def __init__(self):
        self.mpLs={}
        self.mpSl={}
        self.letters  = string.ascii_letters + '1234567890'
    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        if longUrl in  self.mpLs: 
            return self.mpLs[longUrl]
        else:
            x=''
            for i in range(0,6):
                x = x + random.choice(self.letters)
            self.mpLs[longUrl] = x
            self.mpSl[x] = longUrl
        return x

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        return self.mpSl[shortUrl]
# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
