#include <stack>
#include <utility>

class StockSpanner {
private:
    // Stack stores pairs of {price, span}
    std::stack<std::pair<int, int>> s;

public:
    StockSpanner() {
        // No explicit initialization needed for the stack
    }
    
    int next(int price) {
        int current_span = 1;
        
        // If the current price is greater than or equal to the price at the top of the stack,
        // it means the current price "consumes" the span of the previous price.
        while (!s.empty() && s.top().first <= price) {
            current_span += s.top().second;
            s.pop();
        }
        
        // Push the current price and its calculated span onto the stack
        s.push({price, current_span});
        
        return current_span;
    }
};