# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummy = curr = ListNode(0)
        while l1 and l2:
            # print curr.val
            if l1.val < l2.val:
                curr.next,l1 = l1,l1.next
            else:
                curr.next,l2 = l2,l2.next
            curr = curr.next
        curr.next = l1 or l2
        return dummy.next
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        preSlow = None
        slow = head
        fast = head
        
        while fast and fast.next:
            preSlow  = slow
            fast = fast.next.next
            slow = slow.next
        preSlow.next = None
        return self.mergeTwoLists(self.sortList(head),self.sortList(slow))
            
        
