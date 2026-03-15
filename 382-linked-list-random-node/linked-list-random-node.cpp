/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* headNode;

public:
    Solution(ListNode* head) {
        // Store the head of the linked list
        headNode = head;
    }
    
    int getRandom() {
        int result = 0;
        ListNode* curr = headNode;
        int count = 1; // 1-indexed count of nodes we've seen so far
        
        while (curr != nullptr) {
            // Pick a random number between 0 and count - 1
            // If the random number is 0 (probability 1/count), update the result
            if (rand() % count == 0) {
                result = curr->val;
            }
            
            // Move to the next node and increment our counter
            count++;
            curr = curr->next;
        }
        
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */