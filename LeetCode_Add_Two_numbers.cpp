/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /*
 
 You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *preHead = new ListNode(0);
        ListNode *newList = preHead;
        int l1_val , l2_val;
        int carry =0;
        while(l1 || l2) {
            if(!l1) l1_val=0; else {
                l1_val = l1->val;
                l1=l1->next;
            }
            if(!l2) l2_val=0; else {
                l2_val = l2->val;
                l2=l2->next;
            }
            
            int res = l1_val+l2_val+carry;
            if(res>9) carry=1;
            else carry =0;
            res= res%10;
            newList->next = new ListNode(res);
            
            newList = newList->next;
                    }
        
        if(carry)  newList->next = new ListNode(carry);
        return preHead->next;
    
        
    }
};
