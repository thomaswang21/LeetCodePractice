#include <unordered_map>
using namespace std;

// 节点结构
struct Node {
    int key;
    int value;
    int freq;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), freq(1), prev(nullptr), next(nullptr) {}
};

// 双向链表结构
struct DLinkedList {
    Node* head;
    Node* tail;
    DLinkedList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    void addToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    Node* removeTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }

    bool empty() {
        return head->next == tail;
    }
};

// LFUCache 类
class LFUCache {
private:
    int capacity;
    int size;
    int minFreq;
    unordered_map<int, Node*> keyToNode;
    unordered_map<int, DLinkedList*> freqToList;

    void updateFreq(Node* node) {
        int freq = node->freq;
        freqToList[freq]->removeNode(node);

        // 如果当前频率链表空了，并且 freq 是最小频率，更新 minFreq
        if (freqToList[freq]->empty() && freq == minFreq) {
            minFreq++;
        }

        node->freq++;
        if (freqToList.find(node->freq) == freqToList.end())
            freqToList[node->freq] = new DLinkedList();
        freqToList[node->freq]->addToHead(node);
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        minFreq = 0;
    }

    int get(int key) {
        if (keyToNode.find(key) == keyToNode.end()) return -1;
        Node* node = keyToNode[key];
        updateFreq(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyToNode.find(key) != keyToNode.end()) {
            Node* node = keyToNode[key];
            node->value = value;
            updateFreq(node);
        } else {
            if (size == capacity) {
                // 淘汰最少频率链表的尾节点
                Node* nodeToRemove = freqToList[minFreq]->removeTail();
                keyToNode.erase(nodeToRemove->key);
                delete nodeToRemove;
                size--;
            }

            Node* newNode = new Node(key, value);
            keyToNode[key] = newNode;
            minFreq = 1;  // 新节点频率为 1
            if (freqToList.find(1) == freqToList.end())
                freqToList[1] = new DLinkedList();
            freqToList[1]->addToHead(newNode);
            size++;
        }
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */