class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> b(n,0);
        for (auto& p: bookings) {
            int l = p[0] - 1, r = p[1] - 1, c = p[2];
            b[l] += c;
            if (r + 1 < n)
                b[r + 1] -= c;
        }

        for (int i = 1; i < n; i ++ ) b[i] += b[i - 1];
        return b;
    }
};

