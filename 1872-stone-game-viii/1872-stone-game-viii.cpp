class Solution {

public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        for (int idx = 1; idx < stones.size(); idx++)
            stones[idx] = stones[idx] + stones[idx - 1];

        vector<int> dp(n);
        dp[n - 1] = stones[n - 1];
        for (int idx = n - 2; idx >= 1; idx--) {
            int take = stones[idx] - dp[idx + 1];
            int n_take = dp[idx + 1];

            dp[idx] = max(take, n_take);
        }

        return dp[1];
    }
};