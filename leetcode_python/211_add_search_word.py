class TrieNode:
    # Initialize your data structure here.
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.is_word = False

class Trie(object):

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        curr = self.root
        for ch in word:
            curr = curr.children[ch]
        curr.is_word = True

    def search(self, word):
        curr = self.root
        for ch in word:
            if ch not in curr.children:
                return False
            curr = curr.children[ch]
        return curr.is_word
    
    def search_with_dot(self, word, root=None):
        if root:
            curr = root
        else:
            curr = self.root
        # print(word)
        for ind,ch in enumerate(word):
            if ch =='.':
                for k in curr.children.keys():
                    # print("Key:" + k)
                    res = self.search_with_dot(word[ind+1:],curr.children[k])
                    if res:
                        return res
            elif ch not in curr.children:
                # print('ch: ' + ch + "not in curr.children")
                return False
            curr = curr.children[ch]
        # print(word + str(curr.is_word))
        return curr.is_word

    def startsWith(self, prefix):
        curr = self.root
        for ch in prefix:
            if ch not in curr.children:
                return False
            curr = curr.children[ch]
            if curr is None:
                return False
        return True

class WordDictionary(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.tr = Trie()
        

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: None
        """
        self.tr.insert(word)
        

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        return self.tr.search_with_dot(word)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
