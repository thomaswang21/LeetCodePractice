#include <stack>

class Solution {
public:
    void reorderList(ListNode* head) {
        std::stack<ListNode*> stk;
        // 先把所有节点装进栈里，得到倒序结果
        ListNode* p = head;
        while (p != nullptr) {
            stk.push(p);
            p = p->next;
        }

        p = head;
        while (!stk.empty()) {
            // 链表尾部的节点
            ListNode* lastNode = stk.top();
            stk.pop();
            ListNode* next = p->next;
            if (lastNode == next || lastNode->next == next) {
                // 结束条件，链表节点数为奇数或偶数时均适用
                lastNode->next = nullptr;
                break;
            }
            p->next = lastNode;
            lastNode->next = next;
            p = next;
        }
    }
};