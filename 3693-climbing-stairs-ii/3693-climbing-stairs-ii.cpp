class Solution {
public:
    int climbStairs(int n, std::vector<int>& costs) {

        const long long INF = 1e18;
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {

            long long c = costs[i - 1];

            if (i >= 1 && dp[i - 1] != INF) {
                dp[i] = min(dp[i], dp[i - 1] + c + 1);
            }

            if (i >= 2 && dp[i - 2] != INF) {
                dp[i] = min(dp[i], dp[i - 2] + c + 4);
            }

            if (i >= 3 && dp[i - 3] != INF) {
                dp[i] = min(dp[i], dp[i - 3] + c + 9);
            }
        }

        return (int)dp[n];
    }
};