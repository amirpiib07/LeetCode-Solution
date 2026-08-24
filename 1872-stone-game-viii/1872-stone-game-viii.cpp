class Solution {
    int f(int idx, vector<int>& stones, vector<int>& dp) {
        if (idx == stones.size() - 1)
            return stones[idx];

        if (dp[idx] != INT_MIN)
            return dp[idx];

        // take
        int take = stones[idx] - f(idx + 1, stones, dp);

        // skip
        int skip = f(idx + 1, stones, dp);

        return dp[idx] = max(skip, take);
    }

public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        for (int idx = 1; idx < stones.size(); idx++)
            stones[idx] = stones[idx] + stones[idx - 1];

        vector<int> dp(n - 1, INT_MIN);
        return f(1, stones, dp);
    }
};