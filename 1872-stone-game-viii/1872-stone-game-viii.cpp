class Solution {

public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        for (int idx = 1; idx < stones.size(); idx++)
            stones[idx] = stones[idx] + stones[idx - 1];

        int prev, curr;
        prev = stones[n - 1];
        for (int idx = n - 2; idx >= 1; idx--) {
            int take = stones[idx] - prev;
            int n_take = prev;

            curr = max(take, n_take);
            prev = curr;
        }

        return prev;
    }
};