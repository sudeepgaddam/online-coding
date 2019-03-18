# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        def leng(head):
            count = 0
            while(head):
                head = head.next
                count+=1
            return count
        def moveHead(count, head):
            while(count):
                head = head.next
                count-=1
            return head

        l1 = leng(headA) 
        l2 = leng(headB)
        if l1>l2:
            h1 = moveHead(l1-l2,headA)
            h2 = headB
        else:
            h2 = moveHead(l2-l1,headB)
            h1 = headA
        
        while(h1 and h2 and h1!=h2):
            h1=h1.next
            h2=h2.next
        return h1
