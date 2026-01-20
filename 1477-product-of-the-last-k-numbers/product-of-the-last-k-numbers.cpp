class ProductOfNumbers {
public:
    vector<long long> p; // 用 long long 更安全
    int cnt;

    ProductOfNumbers() {
        cnt = 0;
        p.push_back(1); // p[0] = 1
    }
    
    void add(int num) {
        if (num != 0) {
            p.push_back(p[cnt] * num);
            cnt++;
        } else {
            // 遇到 0，清空前缀积
            p.clear();
            p.push_back(1);
            cnt = 0;
        }
    }
    
    int getProduct(int k) {
        if (k <= cnt) {
            return p[cnt] / p[cnt - k];
        } else {
            return 0;
        }
    }
};


/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */