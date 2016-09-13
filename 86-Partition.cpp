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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode* lt = nullptr;
        ListNode* gt = nullptr;
        ListNode* lt_start = nullptr;
        ListNode* gt_start = nullptr;

        auto curr = head;
        while(curr) {
               cout<<curr->val<<endl;

            auto tmp = curr->next;
            if(curr->val<x) {
                if(!lt){
                    //lt not initialised yet, Change the head. lt_start always points to start of lt list
                    lt = lt_start = head = curr;
                } else {
                    lt->next = curr;
                    lt = lt->next;
                }
            } else {
                if(!gt){
                    //gt not initialised yet
                    gt = curr;
                    gt_start = gt;
                } else {
                    gt->next = curr;
                    gt = gt->next;
                }
            }
            
            
            curr=tmp;
        }
        if(gt) gt->next = nullptr;
        if(lt) lt->next = gt_start;
        return head;
    }
};
