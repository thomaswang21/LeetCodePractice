class Solution {
public:
   ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* a = dummy;   // 原 prev
    ListNode* b = head;    // 原 curr

    // 计算链表长度
    int length = 0;
    ListNode* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }

    // 分组反转
    for (int i = 0; i < length / k; i++) {
        for (int j = 1; j < k; j++) {
            ListNode* c = b->next;   // 原 next
            b->next = c->next;
            c->next = a->next;
            a->next = c;
        }
        a = b;
        b = a->next;
    }

    return dummy->next;
}
};
