class Solution {
private:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    long long f(long long mid, const vector<long long>& coins) {
        int n = coins.size();
        long long ans = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            long long curr_lcm = 1;
            int curr_size = 0;
            bool overflow = false;

            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    curr_lcm = lcm(curr_lcm, coins[i]);
                    curr_size++;
                    if (curr_lcm > mid) {
                        overflow = true;
                        break;
                    }
                }
            }

            if (overflow) continue;

            if (curr_size & 1) {
                ans += mid / curr_lcm;
            } else {
                ans -= mid / curr_lcm;
            }
        }

        return ans;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());
        
        
        vector<long long> filtered;
        for (int i = 0; i < coins.size(); i++) {
            bool redundant = false;
            for (int j = 0; j < filtered.size(); j++) {
                if (coins[i] % filtered[j] == 0) {
                    redundant = true;
                    break;
                }
            }
            if (!redundant) {
                filtered.push_back(coins[i]);
            }
        }

        long long low = 1;
        long long high = filtered[0] * (long long)k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2; 

            if (f(mid, filtered) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};