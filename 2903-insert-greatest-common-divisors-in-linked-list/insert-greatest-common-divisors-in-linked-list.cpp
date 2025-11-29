class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* p=head;
        ListNode* a =p->next;
            
            int c=gcd(p->val, a->val);
            ListNode* d=new ListNode(c);
            p->next=d;
            d->next=a;
                       insertGreatestCommonDivisors(a);

            
        
        return head;

    }
};
            
        
