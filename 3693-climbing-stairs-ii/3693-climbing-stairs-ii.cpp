#include <vector>
#include <algorithm>

class Solution {
private:
    const long long INF = 1e18;

    long long solve(int i, const std::vector<int>& costs, std::vector<long long>& memo) {
        
        if (i == 0) return 0;
        
        // Return already computed result
        if (memo[i] != -1) return memo[i];

        long long ans = INF;
        long long c = costs[i - 1]; // step i corresponds to costs[i - 1]

        // Transition from step i - 1
        if (i >= 1) {
            long long prev = solve(i - 1, costs, memo);
            if (prev != INF) ans = std::min(ans, prev + c + 1);
        }
        // Transition from step i - 2
        if (i >= 2) {
            long long prev = solve(i - 2, costs, memo);
            if (prev != INF) ans = std::min(ans, prev + c + 4);
        }
        // Transition from step i - 3
        if (i >= 3) {
            long long prev = solve(i - 3, costs, memo);
            if (prev != INF) ans = std::min(ans, prev + c + 9);
        }

        return memo[i] = ans;
    }

public:
    int climbStairs(int n, std::vector<int>& costs) {
        std::vector<long long> memo(n + 1, -1);
        long long result = solve(n, costs, memo);
        return (result >= INF) ? -1 : (int)result;
    }
};