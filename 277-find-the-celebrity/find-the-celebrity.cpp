/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        // --- 阶段 1: 寻找可能的候选人 (Candidate) ---
        // 就像在图中寻找唯一的“汇点” (Sink Node)
        int candidate = 0;
        
        for (int i = 1; i < n; ++i) {
            // 如果 candidate 认识 i (存在边 candidate -> i)
            // 那么 candidate 不可能是名人 (出度必须为0)，i 成为新的候选人
            if (knows(candidate, i)) {
                candidate = i;
            }
            // 否则 (candidate 不认识 i)，i 被淘汰 (因为每个人都得认识名人)，candidate 保持不变
        }
        
        // --- 阶段 2: 验证候选人 (Verification) ---
        // 验证候选人的 入度 (Indegree) 是否为 n-1，出度 (Outdegree) 是否为 0
        for (int i = 0; i < n; ++i) {
            if (i == candidate) continue; // 跳过自己
            
            // 验证 1: 出度检查 (Outdegree Check)
            // 名人不能认识任何人。如果 candidate 认识 i，返回 -1
            if (knows(candidate, i)) {
                return -1;
            }
            
            // 验证 2: 入度检查 (Indegree Check)
            // 所有人必须认识名人。如果 i 不认识 candidate，返回 -1
            if (!knows(i, candidate)) {
                return -1;
            }
        }
        
        return candidate;
    }
};