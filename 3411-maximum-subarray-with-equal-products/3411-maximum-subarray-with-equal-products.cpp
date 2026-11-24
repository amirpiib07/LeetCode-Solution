
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for (int j = 0; j < n; ++j) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;

            for (int k = j; k < n; ++k) {

                
                if (prod > LLONG_MAX / nums[k])
                    break;

                prod *= nums[k];
                g = gcd(g, (long long)nums[k]);

                
                long long temp = l / gcd(l, (long long)nums[k]);

                if (temp > LLONG_MAX / nums[k])
                    break;

                l = temp * nums[k];

                
                if (g != 0 && l <= LLONG_MAX / g) {
                    if (prod == l * g) {
                        ans = max(ans, k - j + 1);
                    }
                }
            }
        }

        return ans;
    }
};
