

class TimeMap {
public:
    // key -> list of (timestamp, value)
    unordered_map<string, vector<pair<int, string>>> m;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        m[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        if (!m.count(key)) return "";

        const auto& vec = m[key];
        int left = 0, right = vec.size() - 1;
        string res = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (vec[mid].first == timestamp) {
                return vec[mid].second; // 精准匹配
            } else if (vec[mid].first < timestamp) {
                res = vec[mid].second;  // 候选值，继续向右找更大的
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return res; // 要么返回精准值，要么返回 <= timestamp 最大的那个
    }
};


/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */