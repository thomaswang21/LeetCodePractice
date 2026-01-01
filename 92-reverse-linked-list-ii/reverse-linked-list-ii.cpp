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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head)return NULL;
        auto dummy= new ListNode(-1);
        dummy->next=head;
        auto a=dummy;
        for(int i=0; i<left-1;i++)a=a->next;
        auto b=a->next, c=b->next;
        for(int i=0;i<right-left;i++){
            auto d=c->next;
            c->next=b;
            b=c;
            c=d;
        }
        a->next->next=c;
        a->next=b;
        return dummy->next;

    }
};