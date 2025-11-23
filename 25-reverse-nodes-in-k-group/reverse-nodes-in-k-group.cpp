class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy; // 上一组的尾节点

        while (true) {
            // 找到这一组的末尾节点
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* groupEnd = prevGroupEnd;
            for (int i = 0; i < k && groupEnd; i++) groupEnd = groupEnd->next;
            if (!groupEnd) break; // 不足 k 个节点，不反转

            ListNode* nextGroupStart = groupEnd->next;

            // 反转当前组
            ListNode* prev = nextGroupStart;
            ListNode* curr = groupStart;
            while (curr != nextGroupStart) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            // 连接上一组和当前组
            prevGroupEnd->next = groupEnd;
            prevGroupEnd = groupStart; // 现在 groupStart 是组尾
        }

        return dummy->next;
    }
};

