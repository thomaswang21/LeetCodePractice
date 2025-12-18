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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto pa=headA;
        auto pb=headB;
        while(pa!=pb){
            if(pa==NULL){
                pa=headB;
            }else{
                pa=pa->next;
            }
            if(pb==NULL){
                pb=headA;
            }else{
                pb=pb->next;
            }
        }
        return pa;
    }
};