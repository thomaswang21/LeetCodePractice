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
        stack<ListNode*>stk;
        auto p=head;
        while(p!=NULL){
            stk.push(p);
            p=p->next;
        }
        p=head;
        while(!stk.empty()){
            ListNode*lastnode=stk.top();
            stk.pop();
            ListNode*next=p->next;
            if(lastnode==next||lastnode->next==next){
                lastnode->next=nullptr;
                break;
            }
            p->next=lastnode;
            lastnode->next=next;
            p=next;
        }
    }
};