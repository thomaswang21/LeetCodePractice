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
   void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    // 使用快慢指针找到链表的中间节点
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 反转第二部分链表
    ListNode* secondHalf = reverseList(slow->next);
    slow->next = nullptr;

    // 合并两个链表
    mergeLists(head, secondHalf);
}

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void mergeLists(ListNode* l1, ListNode* l2) {
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    while (p1 != nullptr && p2 != nullptr) {
        ListNode* p1Next = p1->next;
        ListNode* p2Next = p2->next;

        p1->next = p2;
        p2->next = p1Next;

        p1 = p1Next;
        p2 = p2Next;
    }
}




};