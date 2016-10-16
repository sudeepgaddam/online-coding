/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
todo: priority queue based solution.
I saw this problem being under Divide and conquer. Then I reaalized its fairly easy extension of merge two lists
I have used mergeTwolists routine from leetcode discuss section.
Just keep dividing list into two, merge left half and right half recursively.
*/
class Solution {
public:


    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }

    
    ListNode * rec(vector<ListNode*>& lists, int start, int end) {
        /* Base cases */
        if(start==(end-1)) 
           return  mergeTwoLists(lists[start],lists[end]);
        else if(start==end) /*Odd case */ 
            return lists[start];
         else if(start>end)
            return NULL;

        int mid = (start+end)/2;
        auto first = rec(lists, start, mid);
        auto sec = rec(lists, mid+1,end);
 
        return mergeTwoLists(first, sec);
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        return rec(lists, 0, size-1);
    }
};
