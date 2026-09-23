class TimeMap {
private:
    // 哈希表：key -> 数组。数组里存的是 {timestamp, value}
    unordered_map<string, vector<pair<int, string>>> m;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        // 因为时间戳是递增的，直接 push_back 进去，天然就是有序的
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // 如果连这个 key 都没有，直接返回空
        if (m.find(key) == m.end()) {
            return "";
        }
        
        const auto& v = m[key];
        int l = 0, r = v.size() - 1;
        
        // 我们最熟悉的闭区间模板
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (v[mid].first <= timestamp) {
                // 当前时间戳及格了（<= 目标值）
                // 因为我们要找最大的，所以往右边逼近
                l = mid + 1; 
            } else {
                // 当前时间戳超标了（太大），必须往左边退
                r = mid - 1;
            }
        }
        
        // 肌肉记忆：刚才在及格分支里执行了 l = mid + 1
        // 跳出循环时，r 必定停留在最后一个及格的位置上！
        if (r >= 0) {
            return v[r].second;
        }
        
        // 如果 r 退到了 -1，说明所有的时间戳都比目标值大，没找到
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */