/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        auto slow = head;
        auto fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)break;
        }
        if(fast ==nullptr || fast->next ==nullptr){
            return NULL;
        }
        slow = head;
        while(slow !=fast){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};