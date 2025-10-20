class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>heap(stones.begin(), stones.end());
        while(heap.size()>1){
            int a=heap.top();heap.pop();
            int b=heap.top();heap.pop();
            heap.push(a-b);
        }
        return heap.top();
    }
};