
// 思路：
// 使用两个队列分别存储Radiant和Dire阵营议员的下标
// 每一轮中，比较两个队列的队首下标，较小的那个议员先行动
// 他会禁止对方阵营的一个议员（即弹出对方队首）
// 然后该议员进入下一轮（即在自己队列尾部加入当前下标+n）
// 当一个队列为空时，另一个阵营获胜

#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant; // 存储Radiant阵营议员的下标
        queue<int> dire;    // 存储Dire阵营议员的下标
        int n = senate.size();

        // 初始化两个队列
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }

        // 模拟投票过程
        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front();
            int d = dire.front();
            radiant.pop();
            dire.pop();

            // 谁的下标小，谁先行动
            if (r < d) {
                radiant.push(r + n); // Radiant胜出，进入下一轮
            } else {
                dire.push(d + n);    // Dire胜出，进入下一轮
            }
        }

        // 判断胜利方
        if (!radiant.empty()) {
            return "Radiant";
        } else {
            return "Dire";
        }
    }
};
