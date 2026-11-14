class Solution {
public:
    int minimumSumSubarray(vector<int>& a, int l, int r) {
        int n = a.size();
        vector<int> pref(n + 1, 0);

        for(int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }

        int ans = INT_MAX;

        for(int i = 0; i <= n; i++) {
            for(int j = i + l; j <= min(n, i + r); j++) {
                int sum = pref[j] - pref[i];

                if(sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};