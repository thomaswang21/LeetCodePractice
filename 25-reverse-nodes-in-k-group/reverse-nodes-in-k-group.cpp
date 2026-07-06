/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;
        
        ListNode* tail = head;
        for (int i = 0; i < k; i++) {
            if (!tail) return head; // 剩余节点不足 k 个，不反转，直接返回
            tail = tail->next;
        }
        
        // 核心：调用你的专属 reverse 函数，范围是 [head, tail)
        ListNode* newHead = reverse(head, tail);
        
        // 此时 head 已经变成了当前 K 个节点的尾巴，把它连向下一段递归的结果
        head->next = reverseKGroup(tail, k);
        
        return newHead;
    }

private:
    // 改造成你习惯的写法，注意第二个参数变成了终点边界 end
    ListNode* reverse(ListNode* head, ListNode* end) {
        if (!head || head == end) return head; // 加上针对空节点或只有一个节点的特判

        ListNode* a = head;
        ListNode* b = head->next;

        // 反转边界从 nullptr 变成了 end
        while (b != end) {
            ListNode* c = b->next;
            
            b->next = a;
            a = b;
            b = c;
        }
        
        // 循环结束后，手动剪断原本的尾巴，防止产生环
        head->next = nullptr; 
        
        return a;
    }
};