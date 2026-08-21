class Solution {
private:
    int f(int mid, vector<int>& coins){
        int n = coins.size();
        int ans = 0;

        for(int mask = 1; mask < (1<<n); mask++){
            int curr_lcm = 1;
            int curr_size = 0;
            for(int i = 0; i < n; i++){
                if((mask & (1<<i))!= 0){
                    curr_lcm = lcm(curr_lcm, coins[i]);
                    curr_size++;
                    if(curr_lcm > mid) break;
                }
            }

            if((curr_size & 1) == 0){
                ans -= mid / curr_lcm;
            } else{
                ans += mid / curr_lcm;
            }
        }

        return ans;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        int mn = *min_element(coins.begin(), coins.end());

        long long low = 1, high = k * (long long)mn;
        long long ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(f(mid, coins) >= k){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};