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
struct cmp{
    bool operator()(ListNode*a, ListNode*b){
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return nullptr;
        ListNode*dummy=new ListNode(-1);
        ListNode*p=dummy;
        priority_queue<ListNode*, vector<ListNode*>,cmp>pq;
        for(ListNode*head:lists){
           if(head!=nullptr){
            pq.push(head);
           }
        }
        while(!pq.empty()){
            ListNode*node=pq.top();
            pq.pop();
            p->next=node;
            if(node->next!=NULL){
                pq.push(node->next);
            }
            p=p->next;

        }
        return dummy->next;
    }
};