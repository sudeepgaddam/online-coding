class Node:
    def __init__(self, k, v):
        self.key = k
        self.val = v
        self.prev = None
        self.next = None

class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.head = Node(-1,-1)
        self.posMap = {}
        self.cap = capacity
        self.tail = Node(-1,-1)
        self.head.next = self.tail
        self.tail.prev = self.head

    def _remove(self, node):
        p = node.prev
        n = node.next
        p.next = n
        n.prev = p

    def _add(self, node):
        p = self.tail.prev
        p.next = node
        self.tail.prev = node
        node.prev = p
        node.next = self.tail
        
    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key in self.posMap:
            nd = self.posMap[key]
            self._remove(self.posMap[key])
            self._add(nd)
            return self.posMap[key].val
        else:
            return -1
        
    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        if key in self.posMap:
            self._remove(self.posMap[key])
        nd = Node(key, value)
        self.posMap[key] = nd
        if len(self.posMap) > self.cap:
            removeNode = self.head.next
            self._remove(removeNode)
            self.posMap.pop(removeNode.key)
        self._add(nd)



# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
