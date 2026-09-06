#include <vector>

class ProductOfNumbers {
private:
    // 预先分配足够大的数组，避免 push_back 扩容开销
    std::vector<int> prefix;
    // 记录当前有效的前缀乘积数量（包含初始的 1）
    int size;

public:
    ProductOfNumbers() {
        // LeetCode 最多操作数通常是 40000 次
        prefix.resize(40005);
        prefix[0] = 1; // 哨兵值
        size = 1;      // 当前长度为 1
    }
    
    void add(int num) {
        if (num == 0) {
            // 遇到 0 直接把有效长度重置为 1，相当于清空前面的数据
            size = 1;
        } else {
            // 直接通过索引赋值，取代 push_back
            prefix[size] = prefix[size - 1] * num;
            size++;
        }
    }
    
    int getProduct(int k) {
        // 如果请求的 k 已经超过了当前记录的连续非零元素数量，说明中间肯定有 0
        if (k >= size) {
            return 0;
        }
        
        // 否则通过除法求区间乘积
        return prefix[size - 1] / prefix[size - 1 - k];
    }
};


/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */