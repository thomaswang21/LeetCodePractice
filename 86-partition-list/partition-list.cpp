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
    ListNode* partition(ListNode* head, int x) {
        auto p11=new ListNode(-1);
      auto p12=new ListNode(-1);
      auto p1=p11;
      auto p2=p12;
        while(head){
        if(head->val<x){
            p1->next=head;
            p1=p1->next;
        }else{
            p2->next=head;
            p2=p2->next;
        }
        head=head->next;
        }
        p1->next=p12->next;
        p2->next=NULL;
        return p11->next;

    }
};