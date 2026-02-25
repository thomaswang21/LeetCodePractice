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
        if(!head||!head->next||k==0)return head;
        ListNode*tail=head;
        int length=1;
        while(tail->next){
            tail=tail->next;
        length++;
        }
        k=k%length;
        tail->next=head;
        int s=length-k;
        for(int i=0; i<s;i++){
            tail=tail->next;
        }
        ListNode*newHead=tail->next;
        tail->next=nullptr;
        return newHead;
    }
};