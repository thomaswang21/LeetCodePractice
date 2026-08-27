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
    ListNode* reverse(ListNode*head){
        if(!head) return NULL;
        auto a = head;
        auto b = head->next;
        while(b){
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        head->next = NULL;
        return a;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(-1);
        auto p = dummy;
        int carry = 0;
        auto l11 = reverse(l1);
        
        auto l22 = reverse(l2);
        while(l11 || l22 ||carry){
            if(l11)carry += l11->val, l11 = l11->next;;
            
            if(l22)carry += l22->val, l22 =l22->next;
            ;
            p->next = new ListNode(carry%10);
            p = p->next;
            carry /=10;
        }
        return reverse(dummy->next);
    }
};