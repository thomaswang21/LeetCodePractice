

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n, INT_MAX); 
        vector<bool> inMST(n, false);    
        minDist[0] = 0;                 
        int result = 0;

        for (int i = 0; i < n; i++) {
            int u = -1;
            int minVal = INT_MAX;

           
            for (int j = 0; j < n; j++) {
                if (!inMST[j] && minDist[j] < minVal) {
                    minVal = minDist[j];
                    u = j;
                }
            }

            inMST[u] = true;
            result += minVal;

          
            for (int v = 0; v < n; v++) {
                if (!inMST[v]) {
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    if (dist < minDist[v]) {
                        minDist[v] = dist;
                    }
                }
            }
        }
        return result;
    }
};


