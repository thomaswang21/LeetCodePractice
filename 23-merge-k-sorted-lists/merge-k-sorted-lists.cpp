#include <vector>
#include <queue>
using namespace std;

// 自定义比较器，用于最小堆
struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // 小顶堆
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        // 将每个链表的头节点加入堆
        for (ListNode* head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            p->next = node;
            if (node->next != nullptr) {
                pq.push(node->next);
            }
            p = p->next;
        }

        return dummy->next;
    }
};
