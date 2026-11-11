class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long amt = 0;
        int cnt = 0;
        bool flag = true;
        
        if (need1 < need2) {
            if (1LL * (cost1 + cost2) <= costBoth) {
                amt = 1LL * cost1 * need1;
            } else {
                amt = 1LL * costBoth * need1;
                cnt = need1;
            }
        } else {
            if (1LL * (cost1 + cost2) <= costBoth) {
                amt = 1LL * cost2 * need2;
            } else {
                amt = 1LL * costBoth * need2;
                cnt = need2;
            }
            flag = false;
        }
        
        if (flag) {
            need2 -= cnt;
            amt += 1LL * need2 * min(cost2, costBoth);
        } else {
            need1 -= cnt;
            amt += 1LL * need1 * min(cost1, costBoth);
        }
        
        return amt;
    }
};
