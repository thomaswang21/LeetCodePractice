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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next){
            return true;
        }
        auto mid = findMid(head);
        auto last = reverse(mid->next);
        auto p = head;
        auto q= last;
        while(q != NULL){
            if(p->val != q->val){
                return false;
            }
            p = p->next;
            q = q->next;

        }
        return true;
    }
    ListNode* findMid(ListNode*head){
        auto slow = head;
        auto fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode*head){
        if(!head)return head;
        auto a = head;
        auto b = head->next;
        while(b){
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;

        }
        head->next = nullptr;
        return a;
    }
};