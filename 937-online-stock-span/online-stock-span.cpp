#include <stack>
#include <utility>

class StockSpanner {
private:
    // Stack stores pairs of {price, span}
    // We use long long for safety, though int is sufficient per constraints
    std::stack<std::pair<int, int>> st;

public:
    StockSpanner() {
        // Constructor initializes the empty stack implicitly
    }
    
    int next(int price) {
        int span = 1;
        
        // While stack is not empty and top price is <= current price
        // We "collect" the span of the smaller previous prices
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second; // Add the previous span to current
            st.pop();                // Remove the smaller price
        }
        
        // Push the current price and its calculated total span
        st.push({price, span});
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */