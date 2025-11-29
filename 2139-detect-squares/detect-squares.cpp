
// 思路：使用哈希表记录每个点出现的次数
// 对于每个查询点 (x, y)，遍历所有与其 y 相同的点 (col, y)
// 若 col != x，则说明可能形成正方形的边长为 |col - x|
// 检查上下两种可能的正方形：
//   1. (x, y ± d) 和 (col, y ± d)
// 统计所有满足条件的组合数量并累加

#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

class DetectSquares {
public:
    // 记录每个点的出现次数
    unordered_map<int, unordered_map<int, int>> cnt;

    DetectSquares() { }

    // 添加点
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        cnt[x][y]++; // 记录该点出现次数
    }

    // 统计与查询点形成正方形的数量
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int res = 0;
        // 遍历所有与查询点 y 相同的点
        for (auto& [col, ymap] : cnt) {
            if (col == x) continue; // 同一列无法形成正方形
            int d = abs(col - x); // 边长
            // 检查上方正方形
            if (cnt[col].count(y) > 0) {
                if (cnt[x].count(y + d) > 0 && cnt[col].count(y + d) > 0)
                    res += cnt[col][y] * cnt[x][y + d] * cnt[col][y + d];
                if (cnt[x].count(y - d) > 0 && cnt[col].count(y - d) > 0)
                    res += cnt[col][y] * cnt[x][y - d] * cnt[col][y - d];
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