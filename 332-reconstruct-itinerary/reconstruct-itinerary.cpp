class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 构建邻接表
        unordered_map<string, vector<string>> graph;
        for (const auto& ticket : tickets) {
            graph[ticket[0]].push_back(ticket[1]);
        }
        // 对每个出发点的目的地进行排序，确保字典序
        for (auto& [from, dests] : graph) {
            sort(dests.begin(), dests.end());
        }
        // Hierholzer 算法寻找以 JFK 为起点的欧拉路径
        // 计算以 JFK 为起点的后序遍历结果
        vector<string> postOrder;
        traverse(graph, "JFK", postOrder);
        // 反转后序遍历结果，得到欧拉路径
        reverse(postOrder.begin(), postOrder.end());
        return postOrder;
    }

private:
    void traverse(unordered_map<string, vector<string>>& graph, const string& node, vector<string>& postOrder) {
        if (!graph.count(node)) {
            postOrder.push_back(node);
            return;
        }
        // 复制节点列表，避免在遍历过程中修改原列表
        while (!graph[node].empty()) {
            string v = graph[node][0];
            graph[node].erase(graph[node].begin());
            traverse(graph, v, postOrder);
        }
        // 获取后序遍历结果
        postOrder.push_back(node);
    }
};