class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>hash;
        for(auto t: s){
            hash[t]++;
        }
        priority_queue<pair<int,char>>heap;
        for(auto x:hash){
            heap.push({ x.second,x.first});
        }
        string ans = "";
        while(!heap.empty()){
            int cnt = heap.top().first;
            char ch = heap.top().second;
            for (int i = 0; i < cnt; i++) {
                ans += ch;
            }
            heap.pop();
        }
        return ans;

    }
};