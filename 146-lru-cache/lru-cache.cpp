// 定义双向链表节点
struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int v): key(k), value(v), prev(NULL), next(NULL) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> cache; // 哈希表
    Node* head;
    Node* tail;
    int size;
    int capacity;

    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }

    void removeNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void addToHead(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    Node* removeTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            Node* node = new Node(key, value);
            cache[key] = node;
            addToHead(node);
            size++;
            if (size > capacity) {
                Node* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                size--;
            }
        } else {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }
};

