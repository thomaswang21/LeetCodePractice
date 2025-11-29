class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        multiset<int> S;
        for (auto x: hand) S.insert(x);
        while (S.size()) {
            int x = *S.begin();
            for (int i = x; i < x + W; i ++ )
                if (!S.count(i))
                    return false;
                else
                    S.erase(S.find(i));
        }
        return true;
    }
};
