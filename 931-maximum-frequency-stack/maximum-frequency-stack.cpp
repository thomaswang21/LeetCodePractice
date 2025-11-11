
// 思路：
// 设计一个数据结构，支持 push 和 pop 操作
// push(x)：将元素 x 压入栈中
// pop()：弹出出现频率最高的元素，如果有多个频率相同的，则弹出最近压入的那个
// 实现方法：
// 1. 使用一个哈希表 freq 记录每个元素出现的频率
// 2. 使用另一个哈希表 group，将相同频率的元素放入一个栈中
// 3. 记录当前最大频率 maxFreq
// 4. push 时：更新 freq[val]，将 val 压入 group[freq[val]] 栈中，更新 maxFreq
// 5. pop 时：从 group[maxFreq] 栈顶弹出一个元素，更新 freq，并在栈空时减少 maxFreq

#include <unordered_map>
#include <stack>
using namespace std;

class FreqStack {
public:
    // 记录每个元素出现的频率
    unordered_map<int, int> freq;
    // 记录每个频率对应的元素栈
    unordered_map<int, stack<int>> group;
    // 当前最大频率
    int maxFreq;

    FreqStack() {
        maxFreq = 0;
    }

    void push(int val) {
        // 更新元素频率
        freq[val]++;
        int f = freq[val];
        // 更新最大频率
        if (f > maxFreq) {
            maxFreq = f;
        }
        // 将元素压入对应频率的栈中
        group[f].push(val);
    }

    int pop() {
        // 获取当前最大频率的栈
        stack<int>& stk = group[maxFreq];
        int val = stk.top();
        stk.pop();
        // 更新频率表
        freq[val]--;
        // 如果该频率的栈空了，减少最大频率
        if (stk.empty()) {
            group.erase(maxFreq);
            maxFreq--;
        }
        return val;
    }
};


/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */