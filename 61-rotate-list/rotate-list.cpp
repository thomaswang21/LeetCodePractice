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
    ListNode* rotateRight(ListNode* head, int k) {
        // Edge cases: empty list, single node, or no rotation needed
        if (!head || !head->next || k == 0) return head;

        // Step 1: Calculate length and find the old tail
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // Step 2: Optimize k
        // If k is greater than length, we only need the remainder
        k = k % length;
        if (k == 0) return head; // No change if k is a multiple of length

        // Step 3: Make the list circular
        tail->next = head;

        // Step 4: Find the new tail
        // The new tail is at (length - k) steps from the beginning.
        // Since 'tail' is currently at the end, it is effectively at index 0 of the ring.
        // We move it forward by (length - k) steps.
        int stepsToNewTail = length - k;
        for (int i = 0; i < stepsToNewTail; i++) {
            tail = tail->next;
        }

        // Step 5: Break the ring and set the new head
        ListNode* newHead = tail->next;
        tail->next = nullptr;

        return newHead;
    }
};