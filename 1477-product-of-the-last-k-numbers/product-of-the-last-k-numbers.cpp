class ProductOfNumbers {
public:
    int p[40001],cnt;
    ProductOfNumbers() {
        cnt=0;
        p[0]=1;
    }
    
    void add(int num) {
        if(num!=0){
            p[cnt+1]=p[cnt]*num;
            cnt++;
        }else{
            cnt=0;
        }
    }
    
    int getProduct(int k) {
        if(k<=cnt){
            return p[cnt]/p[cnt-k];
        }else{
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