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
        if(!head||!head->next)return NULL;
        auto first=head;
        auto second=head;
        while(first &&second){
            first=first->next;
            second=second->next;
            if(second)second=second=second->next;
            else return 0;
            if(first==second){
                first=head;
                while(first!=second){
                    first=first->next;
                    second=second->next;
                }
                return first;
            }
        }
        return 0;
    }
};