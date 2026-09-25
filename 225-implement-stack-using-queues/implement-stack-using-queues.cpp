#include <queue>

class MyStack {
private:
    std::queue<int> q1;
    std::queue<int> q2;

public:
    MyStack() {
        // Constructor doesn't need specific initialization 
        // as std::queue handles it automatically.
    }
    
    void push(int x) {
        // Step 1: Push new element to the empty helper queue
        q2.push(x);
        
        // Step 2: Move all elements from main queue to helper queue
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Step 3: Swap the queues so q1 remains our main data structure
        std::swap(q1, q2);
    }
    
    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */