class DetectSquares {
    unordered_map<int, unordered_map<int, int>> ptsCount;

public:
    DetectSquares() {}

    void add(vector<int> point) {
        ptsCount[point[0]][point[1]]++;
    }

    int count(vector<int> point) {
        int res = 0;
        int x1 = point[0], y1 = point[1];

        // 遍历 x1 列的所有点
        if (!ptsCount.count(x1)) return 0;  // 避免 x1 不存在时创建新的键
        for (auto &[y2, cnt] : ptsCount[x1]) {
            if (y2 == y1) continue;  // 同一点不算

            int side = y2 - y1;

            // 正方形在右边
            int x3 = x1 + side;
            if (ptsCount.count(x3)) {
                res += cnt * ptsCount[x3][y1] * ptsCount[x3][y2];
            }

            // 正方形在左边
            int x4 = x1 - side;
            if (ptsCount.count(x4)) {
                res += cnt * ptsCount[x4][y1] * ptsCount[x4][y2];
            }
        }

        return res;
    }
};


/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */