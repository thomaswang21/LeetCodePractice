class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        
        // 1. 找到中点
        auto mid = findMiddle(head);
        
        // 2. 反转后半部分（调用你第二题的写法）
        ListNode* last = reverse(mid->next);
        
        // 3. 比对前后两半
        ListNode* p = head;
        ListNode* q = last;
        bool result = true;
        
        // 加入 !result 提前退出的优化，提升效率
        while (q != nullptr ) {
            if (p->val != q->val) {
                result = false;
            }
            p = p->next;
            q = q->next;
        }
        
        // 4. 还原链表（保持好习惯，不破坏原数据结构）
        mid->next = reverse(last);
        
        return result;
    }

    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // 这里完全采用你第二题的逻辑
    ListNode* reverse(ListNode* head) {
        if (!head) return nullptr; // 必须加特判，否则 head->next 会报错
        
        ListNode* a = head;
        ListNode* b = head->next;

        while (b != nullptr) {
            ListNode* c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        
        // 致命补刀：把原头节点（现尾节点）的 next 剪断，防止死循环
        head->next = nullptr; 
        
        return a;
    }
};