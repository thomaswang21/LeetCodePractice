#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s; // Stores indices
        
        for (int i = 0; i < prices.size(); ++i) {
            // While stack is not empty and current price is <= price at index on top
            while (!s.empty() && prices[i] <= prices[s.top()]) {
                int index = s.top();
                s.pop();
                // Apply the discount
                prices[index] -= prices[i];
            }
            // Push current index onto stack to find its discount later
            s.push(i);
        }
        
        return prices;
    }
};