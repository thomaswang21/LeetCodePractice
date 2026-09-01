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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto p = dummy;
        int length = 0;
        while(p->next){
            p = p->next;
            length++;
        }
        p = dummy;
        for(int i = 0; i < length-n; i++){
            p = p->next;
        }
        p->next = p->next->next;
        return dummy->next;
    }
};