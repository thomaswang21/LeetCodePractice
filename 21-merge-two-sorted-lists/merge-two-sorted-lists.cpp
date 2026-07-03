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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 1. 修正语法：实例化 ListNode 对象，并用 dummy 记住头节点位置
        ListNode* dummy = new ListNode(-1); 
        ListNode* p = dummy; // 用 p 来往后遍历
        
        while(list1 && list2){
            if(list1->val < list2->val){
                p->next = list1;
                list1 = list1->next; // 2. 必须让 list1 往后移动
            }else{
                p->next = list2;
                list2 = list2->next; // 2. 必须让 list2 往后移动
            }
            p = p->next; // 3. p 也必须往后移动，准备拼接下一个节点
        }
        
        // 4. 修正指针判断语法，直接用 if(list1) 即可
        if(list1) p->next = list1;
        if(list2) p->next = list2;
        
        
        return dummy->next; 
        
    }
};