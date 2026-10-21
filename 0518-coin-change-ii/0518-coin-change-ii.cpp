
class Solution {
    int amt;

    int fun(int idx, int sum, vector<int>& coins, auto& dp) {
        if (sum == amt) return 1;

        if (idx == coins.size()) return 0;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        // Take: 
        int take = 0;
        if (sum + coins[idx] <= amt) {
            take = fun(idx, sum + coins[idx], coins, dp);
        }

        // Not take
        int n_take = fun(idx + 1, sum, coins, dp);

        return dp[idx][sum] = take + n_take;
    }

public:
    int change(int amount, vector<int>& coins) {
        amt = amount;
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amt + 1, -1));
        return fun(0, 0, coins, dp);
    }
};
