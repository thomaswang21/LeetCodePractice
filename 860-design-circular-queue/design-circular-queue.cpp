
// 思路：使用数组实现循环队列，用两个指针 front 和 rear 表示队头和队尾位置
// 当队列为空时 front == rear，当队列满时 (rear + 1) % size == front
// 所有操作均通过取模运算实现循环效果

#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> data; // 存储队列元素的数组
    int front;        // 队头指针
    int rear;         // 队尾指针
    int capacity;     // 队列容量（比实际容量多 1，用于区分空和满）

public:
    // 构造函数，初始化队列大小为 k
    MyCircularQueue(int k) {
        capacity = k + 1; // 多留一个空间区分空和满
        data.resize(capacity);
        front = 0;
        rear = 0;
    }

    // 入队操作
    bool enQueue(int value) {
        if (isFull()) {
            return false; // 队列满，无法入队
        }
        data[rear] = value;
        rear = (rear + 1) % capacity; // 队尾指针循环移动
        return true;
    }

    // 出队操作
    bool deQueue() {
        if (isEmpty()) {
            return false; // 队列空，无法出队
        }
        front = (front + 1) % capacity; // 队头指针循环移动
        return true;
    }

    // 获取队头元素
    int Front() {
        if (isEmpty()) {
            return -1; // 队列空
        }
        return data[front];
    }

    // 获取队尾元素
    int Rear() {
        if (isEmpty()) {
            return -1; // 队列空
        }
        int index = (rear - 1 + capacity) % capacity; // 队尾前一个位置
        return data[index];
    }

    // 判断队列是否为空
    bool isEmpty() {
        return front == rear;
    }

    // 判断队列是否已满
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};