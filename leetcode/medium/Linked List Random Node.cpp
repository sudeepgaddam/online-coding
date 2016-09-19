/*
382. Linked List Random Node  QuestionEditorial Solution  My Submissions
Total Accepted: 9455
Total Submissions: 20730
Difficulty: Medium
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

Example:

// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    private:
    int size;
    ListNode *head_immu;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        size =0;
        head_immu = head;
        while(head) {
            size++;
            head=head->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        auto curr = head_immu;
        
        int rand_num = rand()%size;
        int i=1;
        while(i++<=rand_num) curr=curr->next;
        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
