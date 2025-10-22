class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int>hash;
    vector<int>ans;
    for(int i=0;i<nums.size();i++){
        hash[nums[i]]++;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>heap;
        for(auto t: hash){
            heap.push({t.second,t.first});
            if(heap.size()>k)heap.pop();
        }
        while(!heap.empty()){
            
        ans.push_back(heap.top().second);
        heap.pop();
        }

    return ans;
    }
};