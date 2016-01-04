/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto ab = l1; 
        auto cd = l2;
        int num=0;
        ListNode *newList = NULL;
        ListNode *head = NULL;
        while (ab || cd) {
            if(ab) num+=ab->val;
            if(cd) num+=cd->val;
             if(!newList) {
                newList = new ListNode(num%10);
                head = newList;
            }
            else {
                
                newList->next = new ListNode(num%10);
                newList = newList->next;
            }
            
            num/=10;
            if(cd) cd = cd->next;
            if(ab) ab = ab->next;
        }
        
        if(num)     newList->next = new ListNode(num%10);

        return head;
        
    }
};
