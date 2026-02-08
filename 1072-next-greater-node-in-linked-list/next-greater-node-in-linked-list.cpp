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
public:
    vector<int> nextLargerNodes(ListNode* head) {
        // 1. Convert Linked List to a vector for easy indexing
        vector<int> values;
        while (head) {
            values.push_back(head->val);
            head = head->next;
        }

        int n = values.size();
        vector<int> answer(n, 0); // Initialize with 0 as default
        stack<int> st; // This will store indices

        // 2. Iterate through the values
        for (int i = 0; i < n; i++) {
            // While stack is not empty and current value is greater than 
            // the value at the index stored at the top of the stack
            while (!st.empty() && values[i] > values[st.top()]) {
                answer[st.top()] = values[i];
                st.pop();
            }
            // Push current index onto stack
            st.push(i);
        }

        return answer;
    }
};