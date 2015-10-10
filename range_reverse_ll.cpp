class Solution {
public:

ListNode *reverseBetween(ListNode *head, int m, int n) {
    
    int i=0;
    auto pre_head = new ListNode(0);
    pre_head->next = head;
    auto p1 = pre_head;
    while(++i<m) p1=p1->next;
    if(!p1 || !p1->next) return head;    
    auto p2=p1->next;
    for(int  i=0;i<n-m;i++){
    
        auto temp = p2->next->next;
        p2->next->next = p1->next;
        p1->next = p2->next;
        p2->next = temp;
    }
    return pre_head->next;
}
};
